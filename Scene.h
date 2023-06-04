#include <QtWidgets>
#include <vector>
#include <QMouseEvent>
#include <QTimer>
#include <QLine>
#include <QPen>
#include <cmath>
#include <QMessageBox>
#include <iostream>
using namespace std;

// ############## Edit ##############

#define GunSize 10
#define FireSize 20
#define SensorSize 20

#define HorizonNum 8
#define VerticalNum 8

#define ProcessorWidth 50
#define ProcessorHeight 20
#define ProcessorOffsetV 50
#define ProcessorOffsetH 100

#define SendRange 230
#define AttackRange 150

#define FireStrength 50
#define SuppressNeed 2

// ##################################

#define Idle 0
#define Attack 1

#define Blue 0
#define Red  1

class WaterGun : public QWidget {
public:
    WaterGun(int belong, QWidget *parent = nullptr) : QWidget(parent), belongProcessor(belong) {
        size = GunSize;
        state = Idle;
    }

public:
    int X;
    int Y;
    int state;
    int size;

    int belongProcessor;
};

class Fire : public QWidget {
public:
    Fire(QWidget *parent = nullptr) : QWidget(parent) {
        size = FireSize;
        strength = FireStrength;
        color = Red;
    }

public:
    int X;
    int Y;
    int size;
    int color;

    vector<QLine*> detectLines;
    vector<QLine*> infoLines;
    vector<QLine*> commandLines;
    vector<QLine*> attackLines;

    int strength;
};

class Scene : public QWidget {
public:
    Scene(QWidget *parent = nullptr) : QWidget(parent) {
        setFixedSize(800, 800);

        int corridorWidth = 100;  // 走廊宽度
        int centerX = width() / 2;  // 获取窗口中心点的 x 坐标
        int centerY = height() / 2;  // 获取窗口中心点的 y 坐标

        // 围出走廊的矩形区域
        topLeftRect = new QRect(0, 0, centerX - corridorWidth / 2, centerY - corridorWidth / 2);  
        topRightRect = new QRect(centerX + corridorWidth / 2, 0, centerX - corridorWidth / 2, centerY - corridorWidth / 2); 
        bottomLeftRect = new QRect(0, centerY + corridorWidth / 2, centerX - corridorWidth / 2, centerY - corridorWidth / 2);  
        bottomRightRect = new QRect(centerX + corridorWidth / 2, centerY + corridorWidth / 2, centerX - corridorWidth / 2, centerY - corridorWidth / 2);  

        // 处理机
        int rectCenterX, rectCenterY;  
        int processorWidth = ProcessorWidth;  
        int processorHeight = ProcessorHeight;;  
        rectCenterX = topLeftRect->right() - ProcessorOffsetH;
        rectCenterY = topLeftRect->top() + ProcessorOffsetV;  
        topLeftProcessor = new QRect(rectCenterX - processorWidth / 2, rectCenterY - processorHeight / 2, processorWidth, processorHeight);  
        rectCenterX = topRightRect->left() + ProcessorOffsetH;
        rectCenterY = topRightRect->top() + ProcessorOffsetV;
        topRightProcessor = new QRect(rectCenterX - processorWidth / 2, rectCenterY - processorHeight / 2, processorWidth, processorHeight);  
        rectCenterX = bottomLeftRect->right() - ProcessorOffsetH;
        rectCenterY = bottomLeftRect->bottom() - ProcessorOffsetV;
        bottomLeftProcessor = new QRect(rectCenterX - processorWidth / 2, rectCenterY - processorHeight / 2, processorWidth, processorHeight);  
        rectCenterX = bottomRightRect->left() + ProcessorOffsetH;
        rectCenterY = bottomRightRect->bottom() - ProcessorOffsetV;
        bottomRightProcessor = new QRect(rectCenterX - processorWidth / 2, rectCenterY - processorHeight / 2, processorWidth, processorHeight);  

        // 红外传感器      
        int sensorSize = SensorSize;  
        topSensor = new QRect(centerX - sensorSize / 2, 0, sensorSize, sensorSize); 
        bottomSensor = new QRect(centerX - sensorSize / 2, height() - sensorSize, sensorSize, sensorSize); 
        leftSensor = new QRect(0, centerY - sensorSize / 2, sensorSize, sensorSize);  
        rightSensor = new QRect(width() - sensorSize, centerY - sensorSize / 2, sensorSize, sensorSize);  

        // 在矩形边界上均匀绘制水枪
        int stepSize = (centerX - corridorWidth / 2) / HorizonNum;  // 横向边界上的步长
        for (int i = 0; i < HorizonNum; i++) {
            int x = topLeftRect->left() + i * stepSize;
            int y1 = topLeftRect->bottom();
            int y2 = bottomLeftRect->top() - GunSize;
            createWaterGun(x, y1, 1);
            createWaterGun(x, y2, 3);
        }
        for (int i = 0; i < HorizonNum; i++) {
            int x = topRightRect->left() + (i + 1) * stepSize - GunSize;
            int y1 = topRightRect->bottom();
            int y2 = bottomRightRect->top() - GunSize;
            createWaterGun(x, y1, 2);
            createWaterGun(x, y2, 4);
        }
        stepSize = (centerY - corridorWidth / 2) / VerticalNum;  // 纵向边界上的步长
        for (int i = 0; i < VerticalNum; i++) {
            int y = topLeftRect->top() + i * stepSize;
            int x1 = topLeftRect->right();
            int x2 = topRightRect->left() - GunSize;
            createWaterGun(x1, y, 1);
            createWaterGun(x2, y, 2);
        }
        for (int i = 0; i < VerticalNum; i++) {
            int y = bottomLeftRect->top() + (i + 1) * stepSize - GunSize;
            int x1 = bottomLeftRect->right();
            int x2 = bottomRightRect->left() - GunSize;
            createWaterGun(x1, y, 3);
            createWaterGun(x2, y, 4);
        }
        
        // track mouse
        setMouseTracking(true);

        timer = new QTimer(this);
        connect(timer, &QTimer::timeout, this, &Scene::running);
        timer->start(500);
    }

    ~Scene() {

    }

public slots:

    void running() {
        for(int i = 0; i < (int)fires.size(); i++) {
            Fire* fire = fires[i];
            if(fire->attackLines.size() > SuppressNeed)
            fire->strength -= (fire->attackLines.size() - SuppressNeed);
            if(fire->strength <= 0) {
                for(auto line : fire->detectLines) delete(line);
                for(auto line : fire->infoLines) delete(line);
                for(auto line : fire->commandLines) {
                    for(auto waterGun : waterGuns) {
                        if(waterGun->state == Attack && waterGun->X + GunSize / 2 == line->x2() && waterGun->Y + GunSize / 2 == line->y2()) {
                            waterGun->state = Idle;
                        }
                    }
                    delete(line);
                }
                for(auto line : fire->attackLines) delete(line);
                fires.erase(fires.begin() + i);
                // 更新调度
                for(int j = 0; j < (int)fires.size(); j++) {
                    Fire* fire = fires[j];
                    detectFire(fire);
                    putFire(fire);
                }
                continue;
            }
            if(fire->attackLines.size() > SuppressNeed){
                cout << fire->attackLines.size() - 1 << endl;
                if(fire->color == Red)
                    fire->color = Blue;
                else if(fire->color == Blue)
                    fire->color = Red;
            }
        }
        update();
    }

protected:
// ###################### 绘制 #####################
    void paintEvent(QPaintEvent *event) override {
        Q_UNUSED(event);

        QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing, true);  // 启用反锯齿渲染

        // 绘制场景矩形
        painter.setBrush(Qt::gray);
        painter.drawRect(*topLeftRect);
        painter.drawRect(*topRightRect);
        painter.drawRect(*bottomLeftRect);
        painter.drawRect(*bottomRightRect);

        // 绘制处理机矩形
        painter.setBrush(Qt::white);  
        painter.drawRect(*topLeftProcessor);  
        painter.drawRect(*topRightProcessor);  
        painter.drawRect(*bottomLeftProcessor);  
        painter.drawRect(*bottomRightProcessor);  
        painter.setFont(QFont("Arial", 6));
        painter.drawText(*topLeftProcessor, Qt::AlignCenter, "Processor-1");  
        painter.drawText(*topRightProcessor, Qt::AlignCenter, "Processor-2");  
        painter.drawText(*bottomLeftProcessor, Qt::AlignCenter, "Processor-3");  
        painter.drawText(*bottomRightProcessor, Qt::AlignCenter, "Processor-4");  

        // 绘制红外传感器矩形
        painter.setBrush(Qt::black);
        painter.drawRect(*topSensor);
        painter.drawRect(*bottomSensor);
        painter.drawRect(*leftSensor);
        painter.drawRect(*rightSensor);

        // 绘制水枪
        painter.setPen(Qt::blue);
        for (int i = 0; i < (int)waterGuns.size(); i++) {
            WaterGun* waterGun = waterGuns[i];
            if(waterGun->state == Attack)
                painter.setBrush(QColor(50, 160, 67));
            else if(waterGun->state == Idle)
                painter.setBrush(Qt::transparent);
            painter.drawEllipse(waterGun->X, waterGun->Y, waterGun->size, waterGun->size);
        }

        // 绘制火焰
        painter.setPen(Qt::yellow);
        for(int i = 0; i < (int)fires.size(); i++) {
            Fire* fire = fires[i];
            if(fire->color == Blue)
                painter.setBrush(Qt::blue);
            else if(fire->color == Red)
                painter.setBrush(Qt::red);
            painter.drawEllipse(fire->X, fire->Y, fire->size, fire->size);
        }

        // 画红外传感器探测线
        for(int i = 0; i < (int)fires.size(); i++) {
            Fire* fire = fires[i];
            QPen pen;
            pen.setWidth(2);
            pen.setStyle(Qt::CustomDashLine);
            pen.setDashPattern({7, 3}); 
            pen.setColor(Qt::red);
            painter.setPen(pen);
            for(auto line : fire->detectLines) {
                painter.drawLine(*line);
            }
        }

        // 画传感器向处理机发送信息的线
        for(int i = 0; i < (int)fires.size(); i++) {
            Fire* fire = fires[i];
            QPen pen;
            pen.setWidth(2);
            pen.setStyle(Qt::CustomDashLine);
            pen.setDashPattern({7, 3}); 
            pen.setColor(QColor(233, 233, 65));
            painter.setPen(pen);
            for(auto line : fire->infoLines) {
                painter.drawLine(*line);
            }
        }
        
        // 画处理机向水枪发送指令的线
        for(int i = 0; i < (int)fires.size(); i++) {
            Fire* fire = fires[i];
            QPen pen;
            pen.setWidth(2);
            pen.setColor(QColor(50, 160, 67));
            painter.setPen(pen);
            for(auto line : fire->commandLines) {
                painter.drawLine(*line);
            }
        }

        // 画水枪射击线
        for(int i = 0; i < (int)fires.size(); i++) {
            Fire* fire = fires[i];
            QPen pen;
            pen.setWidth(2);
            pen.setColor(Qt::blue);
            painter.setPen(pen);
            for(auto line : fire->attackLines) {
                painter.drawLine(*line);
            }
        }
    }

// ##################################################

    double dis(double x1, double y1, double x2, double y2) {
        return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    }

    // 传感器向处理机发送信息
    void sendInfo(QRect *sensor, QRect *processor, Fire *fire) {
        double x1 = sensor->center().x(), y1 = sensor->center().y();
        while(dis(x1, y1, processor->x()+ ProcessorWidth, processor->y()+ ProcessorHeight) > SendRange) {
            double d2p = dis(x1, y1, processor->x()+ ProcessorWidth, processor->y()+ ProcessorHeight);
            double x = x1, y = y1;
            for(WaterGun * waterGun : waterGuns) {
                double x2 = waterGun->X + GunSize / 2, y2 = waterGun->Y + GunSize / 2;
                double d = dis(x1, y1, x2, y2);
                if(d < SendRange && dis(x2, y2, processor->x()+ ProcessorWidth, processor->y()+ ProcessorHeight) < d2p) {
                    d2p = dis(x2, y2, processor->x()+ ProcessorWidth, processor->y()+ ProcessorHeight);
                    x = x2, y = y2;
                }
            }
            if(x1 == x && y1 == y) { // 不可达
                return;
            }
            QLine *line = new QLine(x1, y1, x, y);
            fire->infoLines.push_back(line);
            x1 = x, y1 = y;
        }
        QLine *line = new QLine(x1, y1, processor->x() + ProcessorWidth / 2, processor->y() + ProcessorHeight / 2);
        fire->infoLines.push_back(line);
    }

    // 水枪是否被墙壁挡住
    bool isLineRectOverlap(const QLineF& line, const QRectF& rect) {
        QLineF topEdge(rect.topLeft(), rect.topRight());
        QLineF bottomEdge(rect.bottomLeft(), rect.bottomRight());
        QLineF leftEdge(rect.topLeft(), rect.bottomLeft());
        QLineF rightEdge(rect.topRight(), rect.bottomRight());
        return (line.intersects(topEdge, nullptr) == 1) || (line.intersects(bottomEdge, nullptr) == 1)||
            (line.intersects(leftEdge, nullptr) == 1) || (line.intersects(rightEdge, nullptr) == 1);
    }

    // 处理机向水枪发送指令
    bool sendCommand(QRect *Processor, WaterGun *tarWaterGun, Fire *fire){
        double x1 = Processor->center().x(), y1 = Processor->center().y();
        while(dis(x1, y1, tarWaterGun->X + GunSize / 2, tarWaterGun->Y + GunSize / 2) > SendRange) {
            double d2g = dis(x1, y1, tarWaterGun->X + GunSize / 2, tarWaterGun->Y + GunSize / 2);
            double x = x1, y = y1;
            for(WaterGun * waterGun : waterGuns) {
                double x2 = waterGun->X + GunSize / 2, y2 = waterGun->Y + GunSize / 2;
                double d = dis(x1, y1, x2, y2);
                if(d < SendRange && dis(x2, y2, tarWaterGun->X + GunSize / 2, tarWaterGun->Y + GunSize / 2) < d2g) {
                    d2g = dis(x2, y2, tarWaterGun->X + GunSize / 2, tarWaterGun->Y + GunSize / 2);
                    x = x2, y = y2;
                }
            }
            if(x1 == x && y1 == y) { // 不可达
                return false;
            }
            QLine *line = new QLine(x1, y1, x, y);
            fire->commandLines.push_back(line);
            x1 = x, y1 = y;
        }
        QLine *line = new QLine(x1, y1, tarWaterGun->X + GunSize / 2, tarWaterGun->Y + GunSize / 2);
        fire->commandLines.push_back(line);
        return true;
    }

    // 水枪灭火
    void putFire(Fire *fire) {
        double x1 = fire->X + FireSize / 2, y1 = fire->Y + FireSize / 2;
        for(WaterGun *waterGun : waterGuns) {
            double x2 = waterGun->X + GunSize / 2, y2 = waterGun->Y + GunSize / 2;
            if(dis(x1, y1, x2, y2) < AttackRange && waterGun->state == Idle) {
                QLineF lineF = QLineF(x1, y1, x2, y2);
                QRectF topLeftRectF = QRectF(topLeftRect->x(), topLeftRect->y(), topLeftRect->width(), topLeftRect->height());
                QRectF topRightRectF = QRectF(topRightRect->x(), topRightRect->y(), topRightRect->width(), topRightRect->height());
                QRectF bottomLeftRectF = QRectF(bottomLeftRect->x(), bottomLeftRect->y(), bottomLeftRect->width(), bottomLeftRect->height());
                QRectF bottomRightRectF = QRectF(bottomRightRect->x(), bottomRightRect->y(), bottomRightRect->width(), bottomRightRect->height());
                if(isLineRectOverlap(lineF, topLeftRectF) || isLineRectOverlap(lineF, topRightRectF) || \
                    isLineRectOverlap(lineF, bottomLeftRectF) || isLineRectOverlap(lineF, bottomRightRectF)) {
                        continue;
                }
                int flag = false;
                if(waterGun->belongProcessor == 1) {
                    flag = sendCommand(topLeftProcessor, waterGun, fire);
                } else if(waterGun->belongProcessor == 2) {
                    flag = sendCommand(topRightProcessor, waterGun, fire);
                } else if(waterGun->belongProcessor == 3) {
                    flag = sendCommand(bottomLeftProcessor, waterGun, fire);
                } else if(waterGun->belongProcessor == 4) {
                    flag = sendCommand(bottomRightProcessor, waterGun, fire);
                }
                if(flag) {
                    QLine *line = new QLine(x1, y1, x2, y2);
                    waterGun->state = Attack;
                    fire->attackLines.push_back(line);
                }
            }
        }
    }

    // 红外传感器探测
    void detectFire(Fire *fire) {
        double distance = 2e9;
        QRect *sensor = nullptr;
        double d2 = (fire->X - topSensor->center().x()) * (fire->X - topSensor->center().x()) + \
                    (fire->Y - topSensor->center().y()) * (fire->Y - topSensor->center().y());
        if(d2 < distance) {
            distance = d2;
            sensor = topSensor;
        }
        d2 = (fire->X - bottomSensor->center().x()) * (fire->X - bottomSensor->center().x()) + \
                (fire->Y - bottomSensor->center().y()) * (fire->Y - bottomSensor->center().y());
        if(d2 < distance) {
            distance = d2;
            sensor = bottomSensor;
        }
        d2 = (fire->X - leftSensor->center().x()) * (fire->X - leftSensor->center().x()) + \
                (fire->Y - leftSensor->center().y()) * (fire->Y - leftSensor->center().y());
        if(d2 < distance) {
            distance = d2;
            sensor = leftSensor;
        }
        d2 = (fire->X - rightSensor->center().x()) * (fire->X - rightSensor->center().x()) + \
                (fire->Y - rightSensor->center().y()) * (fire->Y - rightSensor->center().y());
        if(d2 < distance) {
            distance = d2;
            sensor = rightSensor;
        }
        QLine *line = new QLine(sensor->center().x(), sensor->center().y(), fire->X + FireSize / 2, fire->Y + FireSize / 2);
        fire->detectLines.push_back(line);
        sendInfo(sensor, topLeftProcessor, fire);
        sendInfo(sensor, topRightProcessor, fire);
        sendInfo(sensor, bottomLeftProcessor, fire);
        sendInfo(sensor, bottomRightProcessor, fire);
    }

    void mousePressEvent(QMouseEvent *event) override {
        // 鼠标左键点击时，创建火焰对象
        if(event->button() == Qt::LeftButton){
            int x = event->position().x(), y = event->position().y();
            if(topLeftRect->contains(x, y) || topRightRect->contains(x, y) || \
                bottomLeftRect->contains(x, y) || bottomRightRect->contains(x, y))
                    return;
            Fire *fire = createFire(x, y);
            detectFire(fire);
            putFire(fire);
            update();
        }
    }

private:
    Fire *createFire(int x, int y) {
        Fire* fire = new Fire(this);
        fire->X = x;
        fire->Y = y;
        fires.push_back(fire);
        return fire;
    }

    void createWaterGun(int x, int y, int belong) { 
        WaterGun* waterGun = new WaterGun(belong, this);
        waterGun->X = x;
        waterGun->Y = y;
        waterGuns.push_back(waterGun);
    }

private:
    QRect *topLeftRect;
    QRect *topRightRect;
    QRect *bottomLeftRect;
    QRect *bottomRightRect;
    QRect *topLeftProcessor;
    QRect *topRightProcessor;
    QRect *bottomLeftProcessor;
    QRect *bottomRightProcessor;
    QRect *topSensor;
    QRect *bottomSensor;
    QRect *leftSensor;
    QRect *rightSensor;

    vector<WaterGun*> waterGuns;  // 水枪对象数组
    vector<Fire*> fires;  // 火焰对象数组

    QTimer *timer;
};

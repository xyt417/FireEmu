#include <QtWidgets>
#include <vector>
#include <QMouseEvent>
#include <QTimer>
#include <QLine>
#include <QPen>
#include <cmath>
using namespace std;

// ############## Edit ##############

#define GunSize 10
#define FireSize 10
#define SensorSize 20

#define HorizonNum 8
#define VerticalNum 8

#define ProcessorWidth 50
#define ProcessorHeight 20
#define ProcessorOffsetV 50
#define ProcessorOffsetH 100

#define sendRange 200
#define detectRange 300

// ##################################

#define Idle 0
#define Detect 1
#define Attack 2

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
    }

public:
    int X;
    int Y;
    int size;

    vector<QLine*> detectLines;
    vector<QLine*> infoLines;
    vector<QLine*> attackLines;
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
            int y2 = bottomLeftRect->top();
            createWaterGun(x, y1, 1);
            createWaterGun(x, y2, 3);
        }
        for (int i = 0; i < HorizonNum; i++) {
            int x = topRightRect->left() + (i + 1) * stepSize - GunSize;
            int y1 = topRightRect->bottom();
            int y2 = bottomRightRect->top();
            createWaterGun(x, y1, 2);
            createWaterGun(x, y2, 4);
        }
        stepSize = (centerY - corridorWidth / 2) / VerticalNum;  // 纵向边界上的步长
        for (int i = 0; i < VerticalNum; i++) {
            int y = topLeftRect->top() + i * stepSize;
            int x1 = topLeftRect->right();
            int x2 = topRightRect->left();
            createWaterGun(x1, y, 1);
            createWaterGun(x2, y, 2);
        }
        for (int i = 0; i < VerticalNum; i++) {
            int y = bottomLeftRect->top() + (i + 1) * stepSize - GunSize;
            int x1 = bottomLeftRect->right();
            int x2 = bottomRightRect->left();
            createWaterGun(x1, y, 3);
            createWaterGun(x2, y, 4);
        }
        
        // track mouse
        setMouseTracking(true);

        // timer = new QTimer(this);
        // connect(timer, &QTimer::timeout, this, &Scene::running);
        // timer->start(1000);
    }

    ~Scene() {

    }

public slots:

    void running() {

    }

protected:
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
        painter.setBrush(Qt::transparent);
        painter.setPen(Qt::blue);
        for (int i = 0; i < (int)waterGuns.size(); i++) {
            WaterGun* waterGun = waterGuns[i];
            painter.drawEllipse(waterGun->X, waterGun->Y, waterGun->size, waterGun->size);
        }

        // 绘制火焰
        painter.setBrush(Qt::red);
        painter.setPen(Qt::yellow);
        for(int i = 0; i < (int)fires.size(); i++) {
            Fire* fire = fires[i];
            painter.drawEllipse(fire->X, fire->Y, fire->size, fire->size);
        }

        // 画红外传感器探测线
        for(int i = 0; i < (int)fires.size(); i++) {
            Fire* fire = fires[i];
            painter.setPen(Qt::red);
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
    }

    double dis(double x1, double y1, double x2, double y2) {
        return sqrt((x1 - x2) * (x1 - x2) + \
                    (y1 - y2) * (y1 - y2));
    }

    // 传感器向处理机发送信息
    void sendInfo(QRect *sensor, QRect *processor, Fire *fire) {
        double x1 = sensor->center().x(), y1 = sensor->center().y();
        while(dis(x1, y1, processor->x(), processor->y()) > sendRange) {
            double d2p = dis(x1, y1, processor->x(), processor->y());
            int x, y;
            for(WaterGun * waterGun : waterGuns) {
                double x2 = waterGun->X + GunSize / 2, y2 = waterGun->Y + GunSize / 2;
                double d = dis(x1, y1, x2, y2);
                if(d < sendRange && dis(x2, y2, processor->x(), processor->y()) < d2p) {
                    d2p = dis(x2, y2, processor->x(), processor->y());
                    x = x2, y = y2;
                }
            }
            QLine *line = new QLine(x1, y1, x, y);
            fire->infoLines.push_back(line);
            x1 = x, y1 = y;
        }
        QLine *line = new QLine(x1, y1, processor->x() + ProcessorWidth / 2, processor->y() + ProcessorHeight / 2);
        fire->infoLines.push_back(line);
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

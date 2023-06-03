#include <QtWidgets>

#define Idle 0
#define Detect 1
#define Attack 2

#define CircleSize 10

class WaterGun : public QWidget {
public:
    WaterGun(QWidget *parent = nullptr) : QWidget(parent) {
        size = CircleSize;
        state = Idle;
    }
public:
    int X;
    int Y;
    int state;

    int size;
};

class Scene : public QWidget {
public:
    Scene(QWidget *parent = nullptr) : QWidget(parent) {
        setFixedSize(1200, 800);

        int corridorWidth = 100;  // 走廊宽度
        int centerX = width() / 2;  // 获取窗口中心点的 x 坐标
        int centerY = height() / 2;  // 获取窗口中心点的 y 坐标

        // 围出走廊的矩形区域
        topLeftRect = new QRect(0, 0, centerX - corridorWidth / 2, centerY - corridorWidth / 2);  
        topRightRect = new QRect(centerX + corridorWidth / 2, 0, centerX - corridorWidth / 2, centerY - corridorWidth / 2); 
        bottomLeftRect = new QRect(0, centerY + corridorWidth / 2, centerX - corridorWidth / 2, centerY - corridorWidth / 2);  
        bottomRightRect = new QRect(centerX + corridorWidth / 2, centerY + corridorWidth / 2, centerX - corridorWidth / 2, centerY - corridorWidth / 2);  

        int rectCenterX, rectCenterY;  
        int processorWidth = 80;  
        int processorHeight = 40;  
        rectCenterX = topLeftRect->center().x();  
        rectCenterY = topLeftRect->center().y();  
        topLeftProcessorRect = new QRect(rectCenterX - processorWidth / 2, rectCenterY - processorHeight / 2, processorWidth, processorHeight);  
        rectCenterX = topRightRect->center().x();  
        rectCenterY = topRightRect->center().y();  
        topRightProcessorRect = new QRect(rectCenterX - processorWidth / 2, rectCenterY - processorHeight / 2, processorWidth, processorHeight);  
        rectCenterX = bottomLeftRect->center().x();  
        rectCenterY = bottomLeftRect->center().y();  
        bottomLeftProcessorRect = new QRect(rectCenterX - processorWidth / 2, rectCenterY - processorHeight / 2, processorWidth, processorHeight);  
        rectCenterX = bottomRightRect->center().x();  
        rectCenterY = bottomRightRect->center().y();  
        bottomRightProcessorRect = new QRect(rectCenterX - processorWidth / 2, rectCenterY - processorHeight / 2, processorWidth, processorHeight);  

        // 在横纵两条走廊尽头各添加一个小矩形        
        int sensorSize = 20;  // 小矩形的大小
        topSensor = new QRect(centerX - sensorSize / 2, 0, sensorSize, sensorSize);  // 创建上端小矩形区域
        bottomSensor = new QRect(centerX - sensorSize / 2, height() - sensorSize, sensorSize, sensorSize);  // 创建下端小矩形区域
        leftSensor = new QRect(0, centerY - sensorSize / 2, sensorSize, sensorSize);  // 创建左端小矩形区域
        rightSensor = new QRect(width() - sensorSize, centerY - sensorSize / 2, sensorSize, sensorSize);  // 创建右端小矩形区域
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
        painter.drawRect(*topLeftProcessorRect);  
        painter.drawRect(*topRightProcessorRect);  
        painter.drawRect(*bottomLeftProcessorRect);  
        painter.drawRect(*bottomRightProcessorRect);  
        painter.drawText(*topLeftProcessorRect, Qt::AlignCenter, "Processor-1");  
        painter.drawText(*topRightProcessorRect, Qt::AlignCenter, "Processor-2");  
        painter.drawText(*bottomLeftProcessorRect, Qt::AlignCenter, "Processor-3");  
        painter.drawText(*bottomRightProcessorRect, Qt::AlignCenter, "Processor-4");  

        // 绘制红外传感器矩形
        painter.setBrush(Qt::black);
        painter.drawRect(*topSensor);
        painter.drawRect(*bottomSensor);
        painter.drawRect(*leftSensor);
        painter.drawRect(*rightSensor);
    }

public:
    QRect *topLeftRect;
    QRect *topRightRect;
    QRect *bottomLeftRect;
    QRect *bottomRightRect;
    QRect *topLeftProcessorRect;
    QRect *topRightProcessorRect;
    QRect *bottomLeftProcessorRect;
    QRect *bottomRightProcessorRect;
    QRect *topSensor;
    QRect *bottomSensor;
    QRect *leftSensor;
    QRect *rightSensor;
};
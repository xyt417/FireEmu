#include <QtWidgets>
#include <vector>
using namespace std;

#define Idle 0
#define Detect 1
#define Attack 2

#define GunSize 10

#define HorizonNum 8
#define VerticalNum 6

class WaterGun : public QWidget {
public:
    WaterGun(QWidget *parent = nullptr) : QWidget(parent) {
        size = GunSize;
        state = Idle;
    }

public:
    int X;
    int Y;
    int state;
    int size;
};

// 接着做: 画水枪

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

        // 创建水枪对象并保存在数组中

        // 在矩形边界上均匀绘制水枪
        int stepSize = (centerX - corridorWidth / 2) / HorizonNum;  // 横向边界上的步长
        for (int i = 0; i < HorizonNum; i++) {
            int x = topLeftRect->left() + i * stepSize;
            int y1 = topLeftRect->bottom();
            int y2 = bottomLeftRect->top();
            createWaterGun(x, y1);
            createWaterGun(x, y2);
        }
        for (int i = 0; i < HorizonNum; i++) {
            int x = topRightRect->left() + (i + 1) * stepSize - GunSize;
            int y1 = topRightRect->bottom();
            int y2 = bottomRightRect->top();
            createWaterGun(x, y1);
            createWaterGun(x, y2);
        }

        stepSize = (centerY - corridorWidth / 2) / VerticalNum;  // 纵向边界上的步长
        for (int i = 0; i < VerticalNum; i++) {
            int y = topLeftRect->top() + i * stepSize;
            int x1 = topLeftRect->right();
            int x2 = topRightRect->left();
            createWaterGun(x1, y);
            createWaterGun(x2, y);
        }
        for (int i = 0; i < VerticalNum; i++) {
            int y = bottomLeftRect->top() + (i + 1) * stepSize - GunSize;
            int x1 = bottomLeftRect->right();
            int x2 = bottomRightRect->left();
            createWaterGun(x1, y);
            createWaterGun(x2, y);
        }
        
    }

    ~Scene() {

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

        // 绘制水枪
        painter.setBrush(Qt::transparent);
        painter.setPen(Qt::blue);
        for (int i = 0; i < (int)waterGuns.size(); i++) {
            WaterGun* waterGun = waterGuns[i];
            painter.drawEllipse(waterGun->X, waterGun->Y, waterGun->size, waterGun->size);
        }
    }

private:
    void createWaterGun(int x, int y) { 
        WaterGun* waterGun = new WaterGun(this);
        waterGun->X = x;
        waterGun->Y = y;
        waterGuns.push_back(waterGun);
    }

private:
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
    vector<WaterGun*> waterGuns;  // 水枪对象数组
};

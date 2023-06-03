#include <Scene.h>
int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    Scene window;
    window.show();

    return app.exec();
}

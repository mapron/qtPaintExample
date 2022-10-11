#include <QWidget>

class MainWindow : public QWidget

{
public:
    MainWindow(QWidget* parent = nullptr);

protected:
    void paintEvent(QPaintEvent* event) override;
};

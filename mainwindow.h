#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QString"
#include "QColor"
#include "QFont"
#include "document.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();



protected:
    void save();
    void save_as();
    void open();
    void set_text_color();
    void set_font();
    void close_file();

    SLTex::Document<QString> mydoc;
    SLTex::MiP<QString> mysyntax;
protected slots:


private slots:
    void on_textBrowser_textChanged();

private:
    Ui::MainWindow *ui;


    void __init__Actions();
    void __init__Menus();
    int page_count();

    QMenu *fileMenu;
    QMenu *editMenu;
    QMenu *settingsMenu;
    QMenu *languageMenu;
    QMenu *helpMenu;
    QMenu *aboutMenu;


    QAction *saveFileAction;
    QAction *saveAsFileAction;
    QAction *openFileAction;
    QAction *closeFileAction;

    QAction *languagePythonAction;
    QAction *languageRubyAction;
    QAction *languagePerlAction;
    QAction *languageJuliaAction;
    QAction *languageRustAction;
    QAction *languageCAction;
    QAction *languageCppAction;
    QAction *languageJavaAction;

    QAction *setFontAction;
    QAction *setTextColorAction;

    QString currentDocument;
    QColor text_color;
    QFont working_font;



};

#endif // MAINWINDOW_H

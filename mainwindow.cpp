#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QString"
#include "QFile"
#include "QFileDialog"
#include "QTextStream"
#include "QTextDocument"
#include "QColorDialog"
#include "QColor"
#include "QFont"
#include "QFontDialog"
#include "QFontDatabase"
#include "QtAlgorithms"


#include "iostream"
#include "algorithm"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    __init__Actions();
    __init__Menus();
   // mysyntax.set_language("Python");

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::__init__Actions()
{
    saveFileAction = new QAction(tr("&Save File"), this);
    saveFileAction->setShortcuts(QKeySequence::New);
    saveFileAction->setStatusTip(tr("Click this to save your current document"));
    saveFileAction->setToolTip("Save your current working document\nIf this is a new document use ''save as'' ");
    connect(saveFileAction, &QAction::triggered, this, &MainWindow::save);

    saveAsFileAction = new QAction(tr("&Save file as"), this);
    saveAsFileAction->setShortcuts(QKeySequence::New);
    saveAsFileAction->setStatusTip(tr("Click this to save your current document"));
    saveAsFileAction->setToolTip("Save your current working document\nIf this is an existing document use ''Save'' ");
    connect(saveAsFileAction, &QAction::triggered, this, &MainWindow::save_as);

    openFileAction = new QAction(tr("&Open File"), this);
    openFileAction->setShortcuts(QKeySequence::New);
    openFileAction->setStatusTip(tr("Select a file to open"));
    openFileAction->setToolTip("Opens a selected file");
    connect(openFileAction, &QAction::triggered, this, &MainWindow::open);

    closeFileAction = new QAction(tr("&Close File"), this);
    closeFileAction->setShortcuts(QKeySequence::New);
    closeFileAction->setStatusTip(tr("Closes the current document"));
    closeFileAction->setToolTip("Closes the current file");
    connect(closeFileAction, &QAction::triggered, this, &MainWindow::close_file);

    languagePythonAction = new QAction(tr("&Python"), this);
    languagePythonAction->setShortcuts(QKeySequence::New);
    languagePythonAction->setToolTip("Enabling this option will add the markup (color)\nAnd an indentation level to your python code.\nIt will also attempt to allow for auto-completetion\nBy expanding your imported modules!");
    languagePythonAction->setStatusTip(tr("Gives your code a pythonic markup"));
    //connect(languagePythonAction, &QAction::triggered, this, &MainWindow::);

    languageRubyAction = new QAction(tr("&Ruby"), this);
    languageRubyAction->setShortcuts(QKeySequence::New);
    languageRubyAction->setToolTip("Enabling this option will add the markup (color)\nAnd an indentation level to your ruby code\nIt will also attempt to allow for auto-completetion\nBy expanding your imported modules!");
    languageRubyAction->setStatusTip(tr("Gives your code a Ruby style markup"));
    //connect(languageRubyAction, &QAction::triggered, this, &MainWindow::);

    languagePerlAction = new QAction(tr("&Perl"), this);
    languagePerlAction->setShortcuts(QKeySequence::New);
    languagePerlAction->setToolTip("Enabling this option will add the markup (color)\nAnd an indentation level to your Perl code\nIt will also attempt to allow for auto-completetion\nBy expanding your imported modules!");
    languagePerlAction->setStatusTip(tr("Gives your code a Perl style markup"));
    //connect(languagePerlAction, &QAction::triggered, this, &MainWindow::);

    languageJuliaAction = new QAction(tr("&Julia"), this);
    languageJuliaAction->setShortcuts(QKeySequence::New);
    languageJuliaAction->setToolTip("Enabling this option will add the markup (color)\nAnd an indentation level to your Julia code\nIt will also attempt to allow for auto-completetion\nBy expanding your imported modules!");
    languageJuliaAction->setStatusTip(tr("Gives your code a Julia style markup"));
    //connect(languageJuliaAction, &QAction::triggered, this, &MainWindow::);

    languageRustAction = new QAction(tr("&Rust"), this);
    languageRustAction->setShortcuts(QKeySequence::New);
    languageRustAction->setToolTip("Enabling this option will add the markup (color)\nAnd an indentation level to your Rust code\nIt will also attempt to allow for auto-completetion\nBy expanding your imported modules!");
    languageRustAction->setStatusTip(tr("Gives your code a Rust style markup"));
    //connect(languageRustAction, &QAction::triggered, this, &MainWindow::);

    languageCAction = new QAction(tr("&C"), this);
    languageCAction->setShortcuts(QKeySequence::New);
    languageCAction->setToolTip("Enabling this option will add the markup (color)\nAnd an indentation level to your C code\nIt will also attempt to allow for auto-completetion\nBy expanding your imported modules!");
    languageCAction->setStatusTip(tr("Gives your code a C style markup"));
    //connect(languageCAction, &QAction::triggered, this, &MainWindow::);

    languageCppAction = new QAction(tr("&C++"), this);
    languageCppAction->setShortcuts(QKeySequence::New);
    languageCppAction->setToolTip("Enabling this option will add the markup (color)\nAnd an indentation level to your C++ code\nIt will also attempt to allow for auto-completetion\nBy expanding your imported modules!");
    languageCppAction->setStatusTip(tr("Gives your code a C++ style markup"));
    //connect(languageCppAction, &QAction::triggered, this, &MainWindow::);

    languageJavaAction = new QAction(tr("&Java"), this);
    languageJavaAction->setShortcuts(QKeySequence::New);
    languageJavaAction->setToolTip("Enabling this option will add the markup (color)\nAnd an indentation level to your Java code\nIt will also attempt to allow for auto-completetion\nBy expanding your imported modules!");
    languageJavaAction->setStatusTip(tr("Gives your code a Java style markup"));
    //connect(languageJavaAction, &QAction::triggered, this, &MainWindow::);


    setTextColorAction = new QAction(tr("Text color"), this);
    setTextColorAction->setShortcuts(QKeySequence::New);
    setTextColorAction->setToolTip("Clicking this button enables you to change the color\nof your text.");
    setTextColorAction->setStatusTip(tr("Change the color of your text"));
    connect(setTextColorAction, &QAction::triggered, this, &MainWindow::set_text_color);


    setFontAction = new QAction(tr("Select font"), this);
    setFontAction->setShortcuts(QKeySequence::New);
    setFontAction->setToolTip("Clicking this button enables you to change the font\nof your text.");
    setFontAction->setStatusTip(tr("Change the font of your text"));
    connect(setFontAction, &QAction::triggered, this, &MainWindow::set_font);
}

void MainWindow::__init__Menus()
{
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(saveFileAction);
    fileMenu->addSeparator();
    fileMenu->addAction(saveAsFileAction);
    fileMenu->addSeparator();
    fileMenu->addAction(openFileAction);
    fileMenu->addSeparator();
    fileMenu->addAction(closeFileAction);
    fileMenu->setToolTipsVisible(true);

    editMenu = menuBar()->addMenu(tr("&Edit"));

    settingsMenu = menuBar()->addMenu(tr("&Settings"));
    settingsMenu->addAction(setTextColorAction);
    settingsMenu->addSeparator();
    settingsMenu->addAction(setFontAction);
    settingsMenu->addSeparator();
    languageMenu = settingsMenu->addMenu(tr("Languages"));
    languageMenu->addAction(languagePythonAction);
    languageMenu->addSeparator();
    languageMenu->addAction(languageRubyAction);
    languageMenu->addSeparator();
    languageMenu->addAction(languagePerlAction);
    languageMenu->addSeparator();
    languageMenu->addAction(languageJuliaAction);
    languageMenu->addSeparator();
    languageMenu->addAction(languageRustAction);
    languageMenu->addSeparator();
    languageMenu->addAction(languageCAction);
    languageMenu->addSeparator();
    languageMenu->addAction(languageCppAction);
    languageMenu->addSeparator();
    languageMenu->addAction(languageJavaAction);
    languageMenu->addSeparator();
    languageMenu->setToolTipsVisible(true);
    settingsMenu->setToolTipsVisible(true);

    helpMenu = menuBar()->addMenu(tr("&Help"));

    aboutMenu = menuBar()->addMenu(tr("&About"));



}

void MainWindow::save()
{

 QTextDocument *doc = ui->textBrowser->document();
 QString temp = doc->toPlainText();
 mydoc.save_file(temp, mydoc.get_working_document());
}

void MainWindow::save_as()
{
    QString filename = QFileDialog::getSaveFileName(this, tr("Save file as"), tr(""));
    QTextDocument *doc = ui->textBrowser->document();
    QString temp = doc->toPlainText();
    mydoc.save_file_as(temp, filename);
}

void MainWindow::open()
{
   QString filename = QFileDialog::getOpenFileName(this, tr("Open FIle"), tr("Text files (*.txt, *.doc)"));
   ui->textBrowser->setText(mydoc.open_file(filename));
}

void MainWindow::close_file()
{
    ui->textBrowser->setText(mydoc.close_file());
}

void MainWindow::set_text_color()
{
    QColor temp = QColorDialog::getColor(Qt::white, this, tr("Select color"));
    ui->textBrowser->setTextColor(mydoc.set_color(temp));
}

void MainWindow::set_font()
{
    bool okay;
    QFont temp = QFontDialog::getFont(&okay, QFont("Times", 12), this, tr("Select font"));
    if(okay)
    {
        ui->textBrowser->setFont(mydoc.set_font(temp));
    }
    else if(!okay)
    {
        ui->textBrowser->setFont(QFont("Time", 12));
    }
}

int MainWindow::page_count()
{

    /*std::cout << t.toStdString() << std::endl;
    int counter = 0;
    if(0 % 250 == 0)
    {
        counter += 1;
    }

    return counter;*/
    return mydoc.page_count(ui->textBrowser->document());
}

void MainWindow::on_textBrowser_textChanged()
{
   int lines = mydoc.line_count(ui->textBrowser->document());
   int words = mydoc.word_count(ui->textBrowser->document());
   int pages = MainWindow::page_count();
   int characters = mydoc.character_count(ui->textBrowser->document());
   ui->lineEdit->setText("Line: " + QString::number(lines) + "\t\t\t\tWords: " + QString::number(words) + /*"\t\t\t\tPages: " + QString::number(pages) +*/ "\t\t\tCharacters: " + QString::number(characters));
}

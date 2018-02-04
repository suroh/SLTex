#ifndef DOCUMENT_H
#define DOCUMENT_H
#include "QFile"
#include "QTextStream"
#include "QFileDialog"
#include "QTextDocument"
#include "QFont"
#include "QColor"

namespace SLTex
{
    template <typename Type>
    class Document
    {
        public:
            Document();
            Type get_working_document();
            QColor set_color(QColor temp);
            QFont set_font(QFont temp);
            void save_file(Type text, Type filepath);
            void save_file_as(Type text, Type filepath);
            Type close_file();
            Type open_file(Type filepath);
            int line_count(QTextDocument *text_docs);
            int page_count(QTextDocument *text_docs);
            int word_count(QTextDocument *text_docs);
            int character_count(QTextDocument *text_docs);

        protected:
            void set_working_document(Type filepath);

        private:
            void write_to_file(Type text, Type filepath);
            void create_file(Type text, Type filepath);
            Type read_file(Type filepath);


            Type working_document;
            QFont current_font;
            QColor current_color;
    };


    template <typename Type>
    class MiP
    {
        public:
            MiP();
            MiP(Type lang);
            void set_language(Type lang);
            Type get_language();

        protected:
            Type syntax_color(Type lang);
        private:
            Type language;
    };





}

template <typename Type>
SLTex::Document<Type>::Document()
{

}

template <typename Type>
void SLTex::Document<Type>::set_working_document(Type filepath)
{
    working_document = filepath;
}

template <typename Type>
Type SLTex::Document<Type>::get_working_document()
{
    return working_document;
}

template <typename Type>
QColor SLTex::Document<Type>::set_color(QColor temp)
{
    current_color = temp;
    return current_color;
}

template <typename Type>
QFont SLTex::Document<Type>::set_font(QFont temp)
{
  current_font = temp;
  return current_font;
}

template <typename Type>
int SLTex::Document<Type>::line_count(QTextDocument *text_docs)
{
  int lines = text_docs->blockCount();
  return lines;
}

template <typename Type>
int SLTex::Document<Type>::page_count(QTextDocument *text_docs) // broken
{

    /*int words = word_count(text_docs);
    int pages = 1;
    if(words % 250 == 0)
    {
        pages += 1;
    }
    else if(words % 250 != 0)
    {
       if(pages > 1 && words % 250 != 0)
       {
           pages -= 1;
       }
       else if(pages == 1)
       {
           pages = 1;
       }
    }*/
    int pages = text_docs->pageCount();
    return pages;
}

template <typename Type>
int SLTex::Document<Type>::word_count(QTextDocument *text_docs)
{
    QString temp = text_docs->toPlainText();
    int words = 0;
    words = temp.split(QRegExp("(\\s|\\n|\\r)+"), QString::SkipEmptyParts).count();
    return words;
}

template <typename Type>
int SLTex::Document<Type>::character_count(QTextDocument *text_docs)
{
    int characters = 0;
    QString temp = text_docs->toPlainText();
    for(QString::iterator itt = temp.begin(); itt != temp.end(); itt++)
    {
        characters += 1;
    }
    return characters;
}

template <typename Type>
void SLTex::Document<Type>::save_file(Type text, Type filepath)
{
  write_to_file(text, filepath);
}

template <typename Type>
void SLTex::Document<Type>::save_file_as(Type text, Type filepath)
{
 create_file(text, filepath);
 set_working_document(filepath);
}

template <typename Type>
Type SLTex::Document<Type>::open_file(Type filepath)
{
    set_working_document(filepath);
    QFile inFile;
    QTextStream in(&inFile);
    return read_file(filepath);
}

template <typename Type>
Type SLTex::Document<Type>::read_file(Type filepath)
{
    QFile inFile(filepath);
    QTextStream in(&inFile);
    Type temp;

    if(inFile.exists())
    {
        if(inFile.open(QIODevice::ReadOnly))
        {
            while(!inFile.atEnd())
            {
               temp = inFile.readAll();
            }
            inFile.close();
            return temp;
        }
    }
    else if(!inFile.exists())
    {
        return QString("Error: file does not exist");
    }
}

template <typename Type>
void SLTex::Document<Type>::write_to_file(Type text, Type filepath)
{
    QFile outFile(filepath);
    QTextStream out(&outFile);

    if(outFile.exists())
    {
        if(outFile.open(QIODevice::WriteOnly))
        {
            out << text;
        }
        outFile.close();
    }
    else if(!outFile.exists())
    {
        save_file_as(text, filepath);
    }
}

template <typename Type>
void SLTex::Document<Type>::create_file(Type text, Type filepath)
{
    QFile outFile(filepath);
    QTextStream out(&outFile);
    outFile.open(QIODevice::WriteOnly);
    out << text;
    outFile.close();
}

template <typename Type>
Type SLTex::Document<Type>::close_file()
{
    set_working_document(NULL);
    return QString("");
}

/*
 *
 *
 */

template <typename Type>
SLTex::MiP<Type>::MiP()
{

}

template <typename Type>
SLTex::MiP<Type>::MiP(Type lang)
{
    language = lang;
}

template <typename Type>
void SLTex::MiP<Type>::set_language(Type lang)
{
    language = lang;
}

template <typename Type>
Type SLTex::MiP<Type>::get_language()
{
    return language;
}

template <typename Type>
Type SLTex::MiP<Type>::syntax_color(Type lang)
{
    Type syntax = lang;
    return syntax; // both lines are useless
                   // Only added them to remove warnings
}

#endif // DOCUMENT_H

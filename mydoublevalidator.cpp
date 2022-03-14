#include "mydoublevalidator.h"
#include <iostream>
MyDoubleValidator::MyDoubleValidator(QObject *parent)
    : QDoubleValidator(parent)
{
}

MyDoubleValidator::MyDoubleValidator(double bottom, double top, int decimals, QObject *parent):QDoubleValidator(parent)
{
    setRange(bottom,top,decimals);
}

MyDoubleValidator::~MyDoubleValidator()
{
}

QValidator::State MyDoubleValidator::validate(QString & input, int & pos) const
{
    if(input == "+"){
        return QValidator::Invalid;
    }

    if(bottom() < 0 && input == "-"){
        return QValidator::Intermediate;
    }

    if (input.isEmpty())
    {
        return QValidator::Intermediate;
    }

    bool sign = false;
    QString input2 = input;
    if(input.indexOf("-") == 0){
        sign = true;
        input2 = input.mid(1, input.length() - 1);
    }

    bool OK = false;
    double val = input2.toDouble(&OK);

    if (!OK)
    {
        return QValidator::Invalid;
    }

    int dotPos = input2.indexOf(".");
    if (dotPos > 0)
    {
        if (input2.right(input2.length() - dotPos - 1).length() > decimals())
        {
            return QValidator::Invalid;
        }
    }

    if(sign){
        val = 0 - val;
    }
    if(val <= top() && val >= bottom())
        return QValidator::Acceptable;

    if(val<bottom()){
        if(!sign){
            return QValidator::Intermediate;
        }else{
            return QValidator::Invalid;
        } 
    }

    if(val>top())
        return QValidator::Invalid;
}

void MyDoubleValidator::fixup(QString &s) const
{
    s = QString("%1").arg(bottom());
}
#include "myintvalidator.h"

MyIntValidator::MyIntValidator(QObject* parent) : QIntValidator(parent)
{

}

MyIntValidator::MyIntValidator(int bottom, int top, QObject* parent) : QIntValidator(
                                                            bottom, top, parent)
{


}

MyIntValidator::~MyIntValidator() {

}

void MyIntValidator::setRange(int bottom, int top)
{
    QIntValidator::setRange(bottom, top);
}

QValidator::State MyIntValidator::validate(QString &s, int &n) const
{
    if(s == "+"){
        return QValidator::Invalid;
    }
    return QIntValidator::validate(s, n);
}

void MyIntValidator::fixup(QString &s) const
{
    s = QString("%1").arg(bottom());
}
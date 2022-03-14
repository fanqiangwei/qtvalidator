#ifndef MYINTVALIDATOR_H
#define MYINTVALIDATOR_H

#include <QObject>
#include <QIntValidator>
 
class MyIntValidator : public QIntValidator
{
    Q_OBJECT
public:
    MyIntValidator(QObject* parent = 0);
    MyIntValidator(int bottom, int top, QObject* parent = nullptr);
    ~MyIntValidator();
    virtual void setRange(int bottom, int top);
    virtual State validate(QString &s, int &n) const;
    virtual void fixup(QString &s) const;
 
};
#endif // MYINTVALIDATOR_H
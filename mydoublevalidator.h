#ifndef MYDOUBLEVALIDATOR_H
#define MYDOUBLEVALIDATOR_H

#include <QObject>
#include <QDoubleValidator>

class MyDoubleValidator : public QDoubleValidator
{
    Q_OBJECT
public:
    MyDoubleValidator(QObject *parent);
    MyDoubleValidator(double bottom, double top, int decimals, QObject *parent=nullptr);
    ~MyDoubleValidator();
    virtual QValidator::State validate(QString &input, int &pos) const;
    virtual void fixup(QString &s) const;
};

#endif // MYDOUBLEVALIDATOR_H
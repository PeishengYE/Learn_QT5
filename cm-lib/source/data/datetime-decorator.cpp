#include "datetime-decorator.h"

#include <QVariant>
#include <QDateTime>
     namespace cm {
        namespace data {
            class DateTimeDecorator::Implementation{
                              public:    Implementation(DateTimeDecorator* _dateTimeDecorator,
                                                        const QDateTime&   _value):
                                                dateTimeDecorator(_dateTimeDecorator), value(_value){ }

                                        DateTimeDecorator* dateTimeDecorator{nullptr};
                                        QDateTime value;
            };

            IntDecorator::IntDecorator(
                    Entity* parentEntity, const QString& key,
                    const QString& label, const int& value) :
                     DataDecorator(parentEntity, key, label){
                               implementation.reset(new Implementation(this, value));
            }

            IntDecorator::~IntDecorator(){}

            const int& IntDecorator::value() const{ return implementation->value; }

            IntDecorator& IntDecorator::setValue(const int& value){
                                if(value != implementation->value) { // ...Validation here if required...
                                         implementation->value = value;
                                         emit valueChanged();
                                }
                                return *this;
            }

            QJsonValue IntDecorator::jsonValue() const{
                return QJsonValue::fromVariant(
                            QVariant(implementation->value));
            }

            void IntDecorator::update(const QJsonObject& _jsonObject){
                    if (_jsonObject.contains(key())) {
                        setValue(_jsonObject.value(key()).toInt());
                    } else {
                        setValue(0);
                    }
            }
        }
     }

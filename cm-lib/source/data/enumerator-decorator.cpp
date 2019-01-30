#include "enumerator-decorator.h"

    namespace cm {
        namespace data {
            class EnumeratorDecorator::Implementation{
                              public:    Implementation(EnumeratorDecorator* _EnumeratorDecorator,
                                                        const int&   _value):
                                                EnumeratorDecorator(_EnumeratorDecorator), value(_value){ }

                                        EnumeratorDecorator* EnumeratorDecorator{nullptr};
                                        int value;
            };

            EnumeratorDecorator::EnumeratorDecorator(
                    Entity* parentEntity, const QString& key,
                    const QString& label, const int& value) :
                     DataDecorator(parentEntity, key, label){
                               implementation.reset(new Implementation(this, value));
            }

            EnumeratorDecorator::~EnumeratorDecorator(){}

            const int& EnumeratorDecorator::value() const{ return implementation->value; }

            EnumeratorDecorator& EnumeratorDecorator::setValue(const int& value){
                                if(value != implementation->value) cccccccc { // ...Validation here if required...
                                         implementation->value = value;
                                         emit valueChanged();
                                }
                                return *this;
            }

            QJsonValue EnumeratorDecorator::jsonValue() const{
                return QJsonValue::fromVariant(
                            QVariant(implementation->value));
            }

            void EnumeratorDecorator::update(const QJsonObject& _jsonObject){
                    if (_jsonObject.contains(key())) {
                        setValue(_jsonObject.value(key()).toInt());
                    } else {
                        setValue(0);
                    }
            }
        }
     }

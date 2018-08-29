#ifndef DATETIMEDECORATOR_H
#define DATETIMEDECORATOR_H

#include <data/data-decorator.h>

namespace cm {
        namespace data {
            class CMLIBSHARED_EXPORT DateTimeDecorator : public DataDecorator{
                              Q_OBJECT
                              Q_PROPERTY( QString ui_value READ value WRITE setValue NOTIFY valueChanged )
            public:
                      DateTimeDecorator(  Entity* parentEntity = nullptr,
                                         const QString& key = "SomeItemKey",
                                         const QString& label = "",
                                         const int& value = 0);
                      ~DateTimeDecorator();
                      DateTimeDecorator& setValue(const int& value);
                      const int& value() const;
                      QJsonValue jsonValue() const override;
                      void update(const QJsonObject& jsonObject) override;
            signals:
                      void valueChanged();
            private:
                      class Implementation;
                      QScopedPointer<Implementation> implementation;
            };

        }
}



#endif // DATETIMEDECORATOR_H

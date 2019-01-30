#ifndef DATETIMEDECORATOR_H
#define DATETIMEDECORATOR_H

#include <data/data-decorator.h>
#include <QDateTime>
namespace cm {
        namespace data {
            class CMLIBSHARED_EXPORT DateTimeDecorator : public DataDecorator{
                              Q_OBJECT
                              Q_PROPERTY( QString ui_iso8601String READ toIso8601String NOTIFY valueChanged )
                              Q_PROPERTY( QString ui_prettyDateString READ toPrettyDateString NOTIFY valueChanged )
                              Q_PROPERTY( QString ui_prettyTimeString READ toPrettyTimeString NOTIFY valueChanged )
                              Q_PROPERTY( QString ui_prettyString READ toPrettyString NOTIFY valueChanged )
            public:
                      DateTimeDecorator(  Entity* parentEntity = nullptr,
                                         const QString& key = "SomeItemKey",
                                         const QString& label = "",
                                         const QDateTime& value = QDateTime(QDate(2018,9,1)) );
                      ~DateTimeDecorator();
                      DateTimeDecorator& setValue(const QDateTime& value);
                      QString toIso8601String() const;
                      QString toPrettyString() const;
                      QString toPrettyTimeString() const;
                      QString toPrettyDateString() const;
                      const QDateTime& value() const;
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

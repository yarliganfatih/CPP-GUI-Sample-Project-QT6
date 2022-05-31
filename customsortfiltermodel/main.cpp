#include <QtWidgets>

#include "window.h"

void addMail(QAbstractItemModel *model, const qint64 &user_id, const QString &username, const QDateTime &created_at, const QString &name, const QString &surname, const QString &email, const QString &password, const qint64 &email_confirm, const QString &country, const QString &city, const QString &town )
{
    model->insertRow(0);
    model->setData(model->index(0, 0), user_id);
    model->setData(model->index(0, 1), username);
    model->setData(model->index(0, 2), created_at);
    model->setData(model->index(0, 3), name);
    model->setData(model->index(0, 4), surname);
    model->setData(model->index(0, 5), email);
    model->setData(model->index(0, 6), password);
    model->setData(model->index(0, 7), email_confirm);
    model->setData(model->index(0, 8), country);
    model->setData(model->index(0, 9), city);
    model->setData(model->index(0, 10), town);
}

QAbstractItemModel *createMailModel(QObject *parent)
{
    QStandardItemModel *model = new QStandardItemModel(0, 11, parent);

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("user_id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("username"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("created_at"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("name"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("surname"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("email"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("password"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("email_confirm"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("country"));
    model->setHeaderData(9, Qt::Horizontal, QObject::tr("city"));
    model->setHeaderData(10, Qt::Horizontal, QObject::tr("town"));

    addMail(model, 1, "yarliganfatih", QDateTime(QDate(2021, 12, 31), QTime(17, 03)), "Fatih", "Yarlıgan", "fatih.yarligan@bahcesehir.edu.tr", "2C6B7D5919BC9EA6A28FB2DF77448", 1, "Turkey", "İstanbul", "Beşiktaş");
    addMail(model, 2, "spiderman", QDateTime(QDate(2022, 01, 02), QTime(11, 18)), "Peter", "Parker", "peter-parker@sony.com", "2C6B7D5919BC9EA6A28FB2DF77448", 1, "USA", "New York", "Brooklyn");
    addMail(model, 3, "ironman", QDateTime(QDate(2022, 01, 14), QTime(10, 03)), "Tony", "Stark", "tony@stark.com", "2C6B7D5919BC9EA6A28FB2DF77448", 1, "USA", "California", "California");
    addMail(model, 4, "batman", QDateTime(QDate(2022, 01, 20), QTime(10, 40)), "Bruce", "Wayne", "bruce@wayne.com", "2C6B7D5919BC9EA6A28FB2DF77448", 1, "USA", "Gotham", "Gotham");
    addMail(model, 5, "superman", QDateTime(QDate(2022, 02, 16), QTime(12, 37)), "Clark", "Kent", "clarkkent@gmail.com", "2C6B7D5919BC9EA6A28FB2DF77448", 1, "USA", "Gotham", "Gotham");
    addMail(model, 6, "captain", QDateTime(QDate(2022, 02, 19), QTime(13, 02)), "Steve", "Rogers", "captain@hydra.com", "2C6B7D5919BC9EA6A28FB2DF77448", 1, "USA", "New York", "Brooklyn");
    addMail(model, 7, "hulk", QDateTime(QDate(2022, 03, 12), QTime(17, 13)), "Bruce", "Banner", "hulk@avangers.com", "2C6B7D5919BC9EA6A28FB2DF77448", 1, "USA", "New York", "Manhattan");
    addMail(model, 8, "dr.strange", QDateTime(QDate(2022, 04, 28), QTime(14, 23)), "Stephen", "Strange", "strange@kamartaj.com", "2C6B7D5919BC9EA6A28FB2DF77448", 1, "USA", "New York", "Manhattan");
    addMail(model, 9, "wolverine", QDateTime(QDate(2022, 05, 14), QTime(15, 53)), "Logan", "Howlett", "logan@xmen.com", "2C6B7D5919BC9EA6A28FB2DF77448", 1, "USA", "New York", "Bağcılar"); // :)
    addMail(model, 0, "", QDateTime(QDate(), QTime()), "", "", "", "", 0, "", "", ""); //editable for new

    return model;
}

//! [0]
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Window window;
    window.setSourceModel(createMailModel(&window));
    window.show();
    return app.exec();
}
//! [0]

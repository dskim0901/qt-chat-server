#ifndef TCPSERVER_HPP
#define TCPSERVER_HPP

#include <QObject>
#include <QTcpServer>
#include <QHash>
#include <QTcpSocket>
#include "AeroScope.h"

class TcpServer : public QObject
{
    Q_OBJECT
public:
    explicit TcpServer(QObject *parent = nullptr);

signals:
    void newMessage(const QByteArray &ba);

public slots:
    void sendMessage(const QString &message);

private slots:
    void onNewConnection();
    void onReadyRead();
    void onClientDisconnected();
    void onNewMessage(const QByteArray &ba);

private:
    QString getClientKey(const QTcpSocket *client) const;
private:
    QTcpServer _server;
    QHash<QString, QTcpSocket*> _clients;
    AeroScope*  _aeroscope;
};

#endif // TCPSERVER_HPP

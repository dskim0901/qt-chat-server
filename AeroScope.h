#ifndef AEROSCOPE_H
#define AEROSCOPE_H

#include <QObject>
#include <QTcpServer>
#include <QHash>
#include <QTcpSocket>

#pragma pack (1)
typedef struct P_HEADER
{
	unsigned char			source_code;
	unsigned char			destination_code;
	unsigned short			command_code;
	unsigned int			packet_size;
} P_HEADER;

typedef struct P_SCOPE_STATUS
{
	P_HEADER	p_header;
	char		device_sn[14];
	unsigned int		scope_lon;
	unsigned int		scope_lat;
	unsigned long long	timestamp;
	unsigned char	version;
	unsigned char	statuscode;
} P_SCOPE_STATUS;

typedef struct  P_DRONE_DATA
{
	unsigned long long flight_time;
	unsigned char device_sn[14];
	unsigned char uav_sn[16];
	unsigned int longitude;
	unsigned int latitude;
	unsigned short gps_altitude;
	unsigned short rel_altitude;
	unsigned short lon_speed;
	unsigned short lat_speed;
	unsigned short altitude_speed;
	unsigned short yaw_angle;
	unsigned int app_lon;
	unsigned int app_lat;
	unsigned int home_lon;
	unsigned int home_lat;
	unsigned char product_type[32];
	unsigned int speed;
} P_DRONE_DATA;

typedef struct P_DRONE_INFOS
{
	P_HEADER	p_header;
	unsigned int drone_info_no;
} P_DRONE_INFOS;
#pragma pack()


class AeroScope: public QObject
{
	Q_OBJECT
public:
	explicit AeroScope(QObject* parent = nullptr);

signals:
 
public slots:

private:
   int get_drone_info_packet(unsigned char* packet);

private slots:

};
#endif

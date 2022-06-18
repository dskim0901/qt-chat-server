#include "AeroScope.h"
#include <string.h>
#include <stdio.h>

AeroScope::AeroScope(QObject* parent) : QObject(parent)
{
}

int AeroScope::get_drone_info_packet(unsigned char *packet)
{
	P_DRONE_INFOS p_drone_infos;
	p_drone_infos.p_header.command_code = 0x2;
	p_drone_infos.p_header.source_code = 0x33;
	p_drone_infos.p_header.destination_code = 0x11;
	p_drone_infos.p_header.packet_size = 0xe0;
	p_drone_infos.drone_info_no = 2;


	P_DRONE_DATA p_drone_data0;
	P_DRONE_DATA p_drone_data1;

	p_drone_data0.flight_time = 0x01816b400e28;
	strcpy((char*)&p_drone_data0.device_sn, "\x30\x51\x52\x44\x47\x38\x31\x30\x30\x33\x30\x31\x32\x34");
	strcpy((char*)&p_drone_data0.uav_sn, "\x33\x59\x54\x42\x4A\x33\x42\x30\x30\x33\x30\x36\x44\x56\x00\x00");
	p_drone_data0.longitude = 0x015348d0;
	p_drone_data0.latitude = 0x6101e7;
	p_drone_data0.gps_altitude = 0x0023;
	p_drone_data0.rel_altitude = 0x0;
	p_drone_data0.lon_speed = 0x1;
	p_drone_data0.lat_speed = 0x11;
	p_drone_data0.altitude_speed = 0x0;
	p_drone_data0.yaw_angle = 0xf140;
	p_drone_data0.app_lon = 0x15348c6;
	p_drone_data0.app_lat = 0x6101db;
	p_drone_data0.home_lon = 0x015348ca;
	p_drone_data0.home_lat = 0x6101e2;
	strcpy((char*)p_drone_data0.product_type, "\x4D\x61\x76\x69\x63\x20\x41\x69\x72\x32\x53\x00");
	p_drone_data0.speed = 0x0;

	p_drone_data1.flight_time = 0x01816b47f598;
	strcpy((char*)&p_drone_data1.device_sn, "\x30\x51\x52\x44\x47\x38\x31\x30\x30\x33\x30\x31\x32\x34");
	strcpy((char*)&p_drone_data1.uav_sn, "uav_sn2");
	p_drone_data1.longitude = 0x015348d0;
	p_drone_data1.latitude = 0x6101e7;
	p_drone_data1.gps_altitude = 0x002e;
	p_drone_data1.rel_altitude = 0x0;
	p_drone_data1.lon_speed = 0x0001;
	p_drone_data1.lat_speed = 0x0011;
	p_drone_data1.lat_speed = 0x0002;
	p_drone_data1.altitude_speed = 0x0;
	p_drone_data1.yaw_angle = 0xc970;
	p_drone_data1.app_lon = 0x15348c6;
	p_drone_data1.app_lat = 0x6101db;
	p_drone_data1.home_lon = 0x015348ca;
	p_drone_data1.home_lat = 0x6101e2;
	strcpy((char*)p_drone_data1.product_type, "\x4D\x61\x76\x69\x63\x20\x41\x69\x72\x32\x53\x00");
	p_drone_data1.speed = 0x010bc3bb; //10^7

	int packet_size = 0;
	memcpy(packet, (P_DRONE_INFOS*)&p_drone_infos, sizeof(P_DRONE_INFOS));
	packet_size += sizeof(P_DRONE_INFOS);
	memcpy(&packet[packet_size], (P_DRONE_DATA*)&p_drone_data0, sizeof(P_DRONE_DATA));
	packet_size += sizeof(P_DRONE_DATA);
	memcpy(&packet[packet_size], (P_DRONE_DATA*)&p_drone_data1, sizeof(P_DRONE_DATA));
	packet_size += sizeof(P_DRONE_DATA);

	return packet_size;
}

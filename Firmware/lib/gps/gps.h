#ifndef GPS_H
#define GPS_H



enum gps_status { ACTIVE, VOID, EMPTY };

struct gps_info {
	long time;
	long date;
	long last_fix_time;
	int  satellites_in_view;
	int  height_m;
	
	float latitude_rad,
	      longitude_rad;
	      
	float speed_ms;      // meter per second
	float heading_rad;   // in radians
	
	int sentence_number_last_fix;
	enum gps_status status;
};


struct GpsConfig
{
	long initial_baudrate;
	long operational_baudrate;	
};	

void gps_init(struct GpsConfig *gpsconfig);

char gps_update_info(struct gps_info *gpsinfo);

void gps_wait_for_lock();



#endif // GPS_H
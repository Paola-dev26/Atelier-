#include <stdio.h>

int main() {
    double wind_angle;	
    double wind_speed;
    double fuel;	
    double consumption;	
    double intwing_surface;	
    double pressure;	
    int temperature;	
    int altitude;	
    double ias;	
    double weight;
    printf("Direction relative du vent [-3,14159265 à 3,14159265] : ");
    scanf("%lf", & wind_angle); 

    printf("Vitesse vent [0 à 150] : ");
    scanf("%lf", & wind_speed); 

    printf("fuel [20 à 350000] : ");
    scanf("%lf", & fuel);

    printf("consumption [10 à 15000] : ");
    scanf("%lf", & consumption);


    return 0;

}

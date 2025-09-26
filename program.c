#include <stdio.h>
#include <math.h>

int main() {
    double wind_angle;	
    double wind_speed;
    double fuel;	
    double consumption;	
    double wing_surface;	
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
      
    printf("wing_surface [5 à 900] : ");
    scanf("%lf", & wing_surface);

    printf("pressure [300 à	1050] : ");
    scanf("%lf", & pressure);
    
    printf("temperature [-50 à 50] : ");
    scanf("%lf", & temperature);

    printf("altitude [0	à 19500] : ");
    scanf("%lf", & altitude);

    printf(" ias [0	à 500] :");
    scanf("%lf", &  ias);

    printf("weight [500 à 600000] : ");
    scanf("%lf", & weight );

 return 0;

}

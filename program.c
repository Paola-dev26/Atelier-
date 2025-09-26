#include <stdio.h>
#include <math.h>

int main() {
    double wind_angle;	
    double wind_speed;
    double fuel;	
    double consumption;	
    double wing_surface;	
    double pressure;	
    double temperature;	
    double altitude;	
    double ias;	
    double weight;
    // Calculer et afficher les données suivantes :
    double headwind;
    double pressure_altitude 1;	
    double tas 2;	
    double ground_speed 3;	
    double range 4;	
    double takeoff 5;	
    double wing_loading 6;	
    double rate_of_climb 7;
    double no_return 8;	
    double descent_speed 9;

    bool headwind;
    bool pressure_altitude=1;	
    bool tas=2;	
    bool ground_speed=3;	
    bool range=4;	
    bool takeoff=5;	
    bool wing_loading=6;	
    bool rate_of_climb=7;
    bool no_return=8;	
    bool descent_speed=9;
    
    


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

    printf(" ias [0	à 500] : ");
    scanf("%lf", &  ias);

    printf("weight [500 à 600000] : ");
    scanf("%lf", & weight );

    if
    (headwind=wind_speed*cos(wind_angle);
    pressure_altitude=altitude+(1023-pressure)*30;
    tas=ias*(1+2*pressure_altitude/1000);
    ground_speed=tas - headwind;
    range=	fuel*ground_speed*1.852/consumption;
    takeoff=300*(1+pressure_altitude/1000)*(1-0.01*fmax(0, temperature-15))*(1-headwind/ground_speed)*(weight/1157)²;
    wing_loading=weight/wing_surface;
    rate_of_climb=	700*(1-pressure_altitude/10000)*(1-0.01*fmax(0,temperature-15));
    no_return=range/2;
    descent_speed=ground_speed*tan(3));
    {
        printf("true\n");
    }l
    else
    {
        printf("false\n");
    }



    return 0;


}

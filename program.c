#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int main(void) {
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
    printf("Choisissez la valeur a calculer :\n");
    printf("1) Altitude-pression\n");
    printf("2) Vitesse vraie (TAS)\n");
    printf("3) Vitesse-sol (Ground Speed)\n");
    printf("4) Distance franchissable (Range)\n");
    printf("5) Distance de decollage (Takeoff)\n");
    printf("6) Charge alaire (Wing loading)\n");
    printf("7) Taux de montee (Rate of climb)\n");
    printf("8) Point de non-retour (No return)\n");
    printf("9) Vitesse de descente\n");
    printf("Votre choix (1-9) : ");
    
    int choix;
     scanf("%d", &choix);
    
    bool headwind = false;
    bool pressure_altitude = false;
    bool tas = false;
    bool ground_speed = false;
    bool range = false;
    bool takeoff = false;
    bool wing_loading = false;
    bool rate_of_climb = false;
    bool no_return = false;
    bool descent_speed = false;

         if (choix == 1) pressure_altitude = true;
    else if (choix == 2) tas = true;
    else if (choix == 3) ground_speed = true;
    else if (choix == 4) range = true;
    else if (choix == 5) takeoff = true;
    else if (choix == 6) wing_loading = true;
    else if (choix == 7) rate_of_climb = true;
    else if (choix == 8) no_return = true;
    else if (choix == 9) descent_speed = true;
    else {
        printf("Choix invalide.\n");
        return 0;
    }
    
    do
    {
    printf("Direction relative du vent [-3,14159265 à 3,14159265] : ");
    scanf("%lf", & wind_angle);
    } while (wind_angle <-3,14159265 || wind_angle > 3,14159265);
    
    do
    {
    printf("Vitesse vent [0 à 150] : ");
    scanf("%lf", & wind_speed);
    } while (wind_speed < 0 || wind_speed > 150);

    do
    {
    printf("fuel [20 à 350000] : ");
    scanf("%lf", & fuel);
    } while (fuel < 20 || fuel > 350000);
    
   do
   {
    printf("consumption [10 à 15000] : ");
    scanf("%lf", & consumption);
   } while (consumption < 10 || consumption > 15000);

   do
   {
   printf("wing_surface [5 à 900] : ");
   scanf("%lf", & wing_surface);
   } while (wing_surface < 5 || wing_surface > 900);
   
    do
    {
    printf("pressure [300 à	1050] : ");
    scanf("%lf", & pressure);
    } while (pressure < 300 || pressure > 1050);
      
    do
    {
    printf("temperature [-50 à 50] : ");
    scanf("%lf", & temperature);
    } while (temperature < -50 || temperature > 50);
    
    do
    {
       printf("altitude [0	à 19500] : ");
    scanf("%lf", & altitude);
    } while (altitude < 0 || altitude > 19500);
    
    do
    {
       printf(" ias [0	à 500] : ");
    scanf("%lf", &  ias);
    } while (ias < 0 || ias > 500);
    
    do
    {
    printf("weight [500 à 600000] : ");
    scanf("%lf", & weight );
    } while (weight < 500 || weight > 600000);
    
    if
    headwind=wind_speed*cos(wind_angle);
    pressure_altitude=altitude+(1023-pressure)*30;
    tas=ias*(1+2*pressure_altitude/1000);
    ground_speed=tas - headwind;
    range=	fuel*ground_speed*1.852/consumption;
    takeoff=300*(1+pressure_altitude/1000)*(1-0.01*max(0, temperature-15))*(1-headwind/ground_speed)*(weight/1157)²;
    wing_loading=weight/wing_surface;
    rate_of_climb=700*(1-pressure_altitude/10000)*(1-0.01*max(0,temperature-15));
    no_return=range/2;
    descent_speed=ground_speed*tan(3);
    {
        printf("true\n");
    }l
    else
    {
        printf("false\n");
    }



    return 0;


}

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

    double headwind;	
    double pressure_altitude;	
    double tas;	
    double ground_speed;	
    double range;	
    double takeoff;	
    double wing_loading;	
    double rate_of_climb;
    double no_return;	
    double descent_speed;
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
    
    bool b_wind_angle = false;	
    bool b_wind_speed = false;
    bool b_fuel = false;	
    bool b_consumption = false;	
    bool b_wing_surface = false;	
    bool b_pressure = false;	
    bool b_temperature = false;	
    bool b_altitude = false;	
    bool b_ias = false;	
    bool b_weight = false;

    bool b_headwind = false;
    bool b_pressure_altitude = false;
    bool b_tas = false;
    bool b_ground_speed = false;
    bool b_range = false;
    bool b_takeoff = false;
    bool b_wing_loading = false;
    bool b_rate_of_climb = false;
    bool b_no_return = false;
    bool b_descent_speed = false;

    if (choix == 1 || choix == 2 || choix == 5 || choix == 7) b_pressure_altitude = true;
    if (choix == 2 || choix == 3 ) b_tas = true;
    if (choix == 3 || choix == 4 || choix == 5 || choix == 9 ) b_ground_speed = true;
    if (choix == 4 || choix == 8) b_range = true;
    if (choix == 5) b_takeoff = true;
    if (choix == 6) b_wing_loading = true;
    if (choix == 7) b_rate_of_climb = true;
    if (choix == 8) b_no_return = true;
    if (choix == 9) b_descent_speed = true;
    else {
        printf("Choix invalide.\n");
        return 0;
    }
     // === DÉPENDANCES ===
    if (b_ground_speed || b_range || b_takeoff || b_descent_speed) {
        b_headwind = true;
        tas = true;
    }
    if (b_tas || b_rate_of_climb || b_takeoff)
        b_pressure_altitude = true;
    if (b_no_return)
        b_range = true;
    
    // === SAISIES AVEC BORNES ===
     if (b_headwind) {
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
    }
    
     if (b_pressure_altitude) {
    do
    {
       printf("altitude [0	à 19500] : ");
    scanf("%lf", & altitude);
    } while (altitude < 0 || altitude > 19500);
    
    do
    {
    printf("pressure [300 à	1050] : ");
    scanf("%lf", & pressure);
    } while (pressure < 300 || pressure > 1050);
    }
    
     if (b_tas) {
    do
    {
       printf(" ias [0	à 500] : ");
    scanf("%lf", &  ias);
    } while (ias < 0 || ias > 500);
}
    
     if (b_altitude || b_no_return) {
    
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
}
     if (b_takeoff || b_wing_loading) {
    
    do
    {
    printf("weight [500 à 600000] : ");
    scanf("%lf", & weight );
    } while (weight < 500 || weight > 600000);
}
   if (b_wing_loading) {
   do
   {
   printf("wing_surface [5 à 900] : ");
   scanf("%lf", & wing_surface);
   } while (wing_surface < 5 || wing_surface > 900);
}
   
   if (b_takeoff || b_rate_of_climb) {
    do
    {
    printf("temperature [-50 à 50] : ");
    scanf("%lf", & temperature);
    } while (temperature < -50 || temperature > 50);
}
    
// === Affichage du résultat ===   
if (choix == 1) {
    pressure_altitude = altitude+(1023-pressure)*30;
    printf("Altitude pression = %.2f\n", pressure_altitude);
}
else if (choix == 2) {
    tas = ias*(1+2*pressure_altitude/1000);
    printf("TAS = %.2f\n", tas);
}
else if (choix == 3) {
    ground_speed = 	tas - headwind;
    printf("Vitesse sol = %.2f\n", ground_speed);
}
else if (choix == 4) {
    range = fuel*ground_speed*1.852/consumption;
    printf("Distance franchissable = %.2f\n", range);
}
else if (choix == 5) {
    takeoff = 	300*(1+pressure_altitude/1000)*(1-0.01*fmax(0, temperature-15))*(1-headwind/ground_speed)*(weight/1157)*(weight/1157);
    printf("Distance de décollage = %.2f\n", takeoff);
}
else if (choix == 6) {
    wing_loading = weight/wing_surface;
    printf("Charge alaire = %.2f\n", wing_loading);
}
else if (choix == 7) {
    rate_of_climb = 700*(1-pressure_altitude/10000)*(1-0.01*fmax(0,temperature-15));
    printf("Taux de montée = %.2f\n", rate_of_climb);
}
else if (choix == 8) {
    no_return = range/2;
    printf("Point de non-retour = %.2f\n", no_return);
}
else if (choix == 9) {
    descent_speed = ground_speed*tan(3);
    printf("Vitesse de descente = %.2f\n", descent_speed);
}
else {
    printf("Choix invalide.\n");
}
   return 0;


}

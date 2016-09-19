#include <stdio.h>
#include "libpower.h"
#include "libcomponent.h"
#include "libresistance.h"

int main(int args, char * argv[])
{
  //Effekten i resitansen
  int numberOfComponents;
  float U;
  float totalResistance = 0;

  printf("Ange spänningskälla i V: ");
  scanf("%f", &U);

  printf("Ange komponenter: ");
  scanf("%i", &numberOfComponents);

  int i;
  for(i = 0; i < numberOfComponents; i++) {
    printf("Komponent %i i ohm: ", i + 1);
    float temp;
    scanf("%f", &temp);
    totalResistance += temp;
  }

  printf("Effekt: %f W\n", calc_power_r(U, totalResistance));

  //E12 resistorer
  float resistance_array[3];
  int count = e_resistance(totalResistance, resistance_array);
  printf("Ersättningsresistanser i E12-serien kopplade i serie: ");
  for (i = 0; i < count; i++)
  {
    printf("%.0f ", resistance_array[i]);
  }
  printf("\n");

  //Ersättnigsresitansesn
  char conn;
  int resistors;
  printf("För hur många komponenter vill du beräkna ersättnigsresitansen: " );
  scanf(" %i", &resistors);
  printf("Skall komponenter kopplas i serie 'S' eller parallelt 'P': ");
  scanf(" %c", &conn);
  float arr[resistors];
  printf("Input %i resitances that will be connected '%c'\n",count,conn);
  for(i = 0; i < count; i=i+1){
     printf("Ange %i resistansen: ",i);	
     scanf(" %f",&arr[i]);
  }
  printf("Resultat: %f \n", calc_resistance(count,conn,arr) );

  return 0;
}

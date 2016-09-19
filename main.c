#include <stdio.h>
#include "libpower.h"
#include "libcomponent.h"
#include "libresistance.h"

int main(int args, char * argv[])
{
 
  int numberOfComponents;
  float U;
  float totalResistance = 0;
  char connection;

  printf("Ange spänningskälla i V: ");
  scanf("%f", &U);

  printf("Ange hur många komponenter du vill beräkna ersättnigsresitansen för: ");
  scanf("%i", &numberOfComponents);

  printf("Skall komponenter kopplas i serie 'S' eller parallelt 'P': ");
  scanf(" %c", &connection);

  int i;
  float arr[numberOfComponents];
  for(i = 0; i < numberOfComponents; i++) {
    printf("Komponent %i i ohm: ", i + 1);
    scanf(" %f",&arr[i]);
  }

  //Ersättnigsresitansen
  totalResistance = calc_resistance(numberOfComponents,connection,arr);
  printf("Den totala Resistansen är : %f \n", totalResistance);
  
  //Effekten i resitansen
  printf("Effekt: %f W\n", calc_power_r(U, totalResistance));

  //E12 resistorer
  float resistance_array[3];
  int count = e_resistance(totalResistance, resistance_array);
  printf("Ersättningsresistanser i E12-serien kopplade i serie: ");
  for (i = 0; i < count; i++)
  {
    printf("%.0f | ", resistance_array[i]);
  }
  printf("\n");

  return 0;
}

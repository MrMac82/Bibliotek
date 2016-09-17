#include <stdio.h>
#include "libpower.h"
#include "libcomponent.h"

int main(int args, char * argv[])
{
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

  float resistance_array[3];
  int count = e_resistance(totalResistance, resistance_array);
  printf("Ersättningsresistanser i E12-serien kopplade i serie: ");
  for (int i = 0; i < count; i++)
  {
    printf("%.0f ", resistance_array[i]);
  }
  printf("\n");

  return 0;
}

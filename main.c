#include <stdio.h>
#include "libpower.h"

int main(int args, char * argv)
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
  printf("Effekt: %f\n", calc_power_r(U, totalResistance));
  
  return 0;
}

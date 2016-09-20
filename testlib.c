#include <stdio.h>
#include "libcomponent.h"

int main()
{
  float resistance_array[3];
  float input;

  printf("Ersättningsresistans: ");
  scanf("%f", &input);

  int count = e_resistance(input, resistance_array);

  printf("Resultat: %d\n", count);
  printf("Ersättningsresistanser i E12-serien kopplade i serie: ");
  for (int i = 0; i < count; i++)
  {
    printf("%.0f ", resistance_array[i]);
  }
  printf("\n");

  return 0;
}

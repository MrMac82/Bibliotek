int e_resistance(float orig_resistance, float *res_array)
{
  float e12[] = {
                  10.0, 12.0, 15.0, 18.0, 22.0, 27.0, 33.0, 39.0, 47.0, 56.0, 68.0, 82.0,
                  100.0, 120.0, 150.0, 180.0, 220.0, 270.0, 330.0, 390.0, 470.0, 560.0, 680.0, 820.0,
                  1000.0, 1200.0, 1500.0, 1800.0, 2200.0, 2700.0, 3300.0, 3900.0, 4700.0, 5600.0, 6800.0, 8200.0
                };
  float resistance = orig_resistance;
  int count = 0;

  while (resistance >= 10.0 && count < 3)
  {
    int i;
    for (i = 0; i < sizeof(e12); i++)
    {
      if (e12[i] > resistance)
      {
        resistance = resistance - e12[i-1];
        res_array[count] = e12[i-1];
        break;
      }
    }
    count++;
  }

  return count;
}

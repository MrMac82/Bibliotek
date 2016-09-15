//#include "libresistance.h"
#include <stdio.h>

float calc_resistance(int count, char conn, float *array);

float calc_resistance(int count, char conn, float *array)
{
    float result=-1.0;

	if (count>0)
	{
        if (array!=0)
        {
            int i;
            //parallel resistance is equal to the sum of inverse of individual resistances
            if (conn=='P')
            {
                float inverted=0;
                for(i=0;i<count;i=i+1){
                    if (array[i]==0){
                        break;
                    }
                    inverted=inverted+1/array[i];
                }
                if(i==count)result=1/inverted;
                else result=0;
            }
            //series resistance is equal to the sum of individual resistances
            if (conn=='S')
            {
                result=0;
                 for(i=0;i<count;i=i+1){
                    result=result+array[i];
                }
            }
        }
	}
	return result;
}

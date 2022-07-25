/*
* Naam: Akif Kaynak
* Studentnummer: 0976193
* Klas: TI1C
*/

#include "lenaArray.h" // Add file lenaArray.h
#include "greyScale.h" // Ascii-values
#include <stdio.h>     // Standard Input and Output
#include <stdlib.h>
#include <stdint.h>



float avg_GreyScale(int x2, int y2)
{ //Big and Small lena
  float returnVal = 0;
  float total = 0;
  for (int x = 0; x < x2; x++)
  { // width
    for (int y = 0; y < y2; y++)
    { // length

      total += lena[x][y];
    }
  }

  //printf("%f");
  //printf("%d\n", (y2 * y2));
  

  if (x2 != 0)
  {
    returnVal = total / (x2 * y2);
  }
  else
  {
    returnVal = total / (y2 * y2);
  }
  return returnVal; //Calculates the average of the total value
}

int printing;
int totalGreyScale;

void printImg(int start, int end)
{ //Prints all the lines
  for (int vertical = start; vertical <= end; vertical++)
  {
    for (int horizontal = start; horizontal <= end; horizontal++)
    {                                               //X-value will print all the characters untill the y-loop has ended
      totalGreyScale += lena[vertical][horizontal]; //Adds the GrayScale value to the totalGrayScale

      printing = ((lena[vertical][horizontal] * 10) / 256); //Multiply lena[x][y] by the length of GrayScale array and dividing it by length of an array
      printf("%c", greyScale[printing]);                    //Select grayscale and print it
    }

    printf("\n");
  }
}

int main(void)
{

  float avg_Lena = avg_GreyScale(512, 512); //Value of this float is equal to the value of the above function

  printf("The average gray value of the original image = %f\n", avg_Lena); // Print the average with decimals

  float avg_ReducedLena = avg_GreyScale(100, 400); //Value of this float is equal to the value of the above function

  printf("The average gray value of the cropped image = %f\n", avg_ReducedLena); // Print the average with decimals

  printImg(100, 400);
  printImg(0, 511);
  return 0;
}
#include <stdio.h>
#include <stdlib.h>
struct monthlySales
{
  unsigned int month;
  float sales;
};

  /* data */

// Driver code
int main()
{
  static const uint32_t NUM_OF_MONTH = 12;
  char monthlyName[12][64] = 
  {
    "January",
    "February",
    "March",
    "April",
    "May",
    "June",
    "July",
    "August",
    "September",
    "October",
    "November",
    "December"
  };
  struct monthlySales data[NUM_OF_MONTH];
  FILE* file = fopen("salesData.txt", "r");

  if(file == NULL)
  {
    printf("Your dumbs");
    return 0;
  }
  printf("%-20s%-20s\n","Month","Sales");
  for(uint32_t i=0; i < NUM_OF_MONTH; i++)
  {
      char lineData[256];
      if(fgets(lineData, sizeof(lineData), file))
      {
        data[i].sales = atof(lineData);
        data[i].month = i;
        printf("%-20s%5.2f\n", monthlyName[i], data[i].sales);

  
      }
      else
      {
        printf("Not enough data");
      }
  }

  fclose(file);

  return 0;
}
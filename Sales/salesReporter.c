// Ethan Gao 
// KU ID: 3121537
// Lab Session: Thrusday
// Lab: 5
// Collaborators: Frank Gao (Dad)

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
  unsigned int month;
  float sales;
} MonthlySales;

static const uint32_t sMonths = 12;

static const char sMonthName[12][32] = 
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

static MonthlySales sData[sMonths];

void MonthReport(FILE* file)
{
  printf("Monthly Sales Report for 2024 \n\n");
  printf("%-20s%-20s\n","Month","Sales");
  for(uint32_t i=0; i < sMonths; i++)
  {
      char lineData[256];
      if(fgets(lineData, sizeof(lineData), file))
      {
        sData[i].sales = atof(lineData);
        sData[i].month = i;
        printf("%-20s%5.2f\n", sMonthName[sData[i].month], sData[i].sales);
      }
      else
      {
        printf("Not enough data");
      }
  }
  return;
}

void SalesSummary()
{
  int minSalesIndex = 0;
  int maxSalesIndex = 0;
  double sumSales = sData[0].sales;
  for(uint32_t i=1; i < sMonths; i++)
  {
    if (sData[i].sales < sData[minSalesIndex].sales)
    {
      minSalesIndex = i;
    }
    else if(sData[i].sales > sData[maxSalesIndex].sales)
    {
      maxSalesIndex = i;
    }
    sumSales += sData[i].sales;
  }

  printf("\nSales summary report: \n\n");
  printf("Minimum sales: %5.2f (%s)\n", sData[minSalesIndex].sales,
    sMonthName[minSalesIndex]);
  printf("Maximum sales: %5.2f (%s)\n", sData[maxSalesIndex].sales,
    sMonthName[maxSalesIndex]);
  printf("Average sales: %5.2f \n", sumSales/sMonths);
  return;
}

void SixMonthAverage()
{
  printf("\nSix-Month moving average report: \n\n");
  const u_int32_t sixMonth = 6;
  for(uint32_t i=0; i < sixMonth+1; i++)
  {
    double sixMonthSum = 0;
    for(uint32_t j=i; j < i+sixMonth; j++)
    {
      sixMonthSum += sData[j].sales;
    }
    char title[64];
    sprintf(title,"%s-%-s ",sMonthName[i],sMonthName[i+5]);
    printf("%-20s%5.2f\n",title, (sixMonthSum/sixMonth));
  }
  return;
}

int SortReport_CompareSales(const void* a, const void* b)
{
  if(((MonthlySales*)a)->sales > ((MonthlySales*)b)->sales)
  { 
    return -1;
  }
  if (((MonthlySales*)a)->sales < ((MonthlySales*)b)->sales)
  {
    return 1;
  }
  return 0;
}

void SortReport()
{
  qsort(sData, sMonths, sizeof(MonthlySales), SortReport_CompareSales);
  printf("\nSales report (highest to lowest): \n\n");
  printf("%-20s%-20s\n","Month","Sales");
  for(uint32_t i=0; i < sMonths; i++)
  {
    printf("%-20s%5.2f\n", sMonthName[sData[i].month], sData[i].sales);
  }
  return;
}

int main()
{
  FILE* file = fopen("salesData.txt", "r");

  if(file == NULL)
  {
    printf("Your dumbs");
    return 0;
  }

  MonthReport(file);
  SalesSummary();
  SixMonthAverage();
  SortReport();

  fclose(file);

  return 0;
}
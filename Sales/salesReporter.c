#include <stdio.h>
#include <stdlib.h>
// Driver code
int main()
{
  char ch;
  FILE* file = fopen("/Sales/salesData.txt", "r");

  if(file == NULL)
  {
    printf("Your dumbs");
    return 0;
  }
  
  while(1) 
  {
      ch = fgetc (file);
      if (ch == EOF)
         break;
      printf ("%c", ch);
   }
  fclose(file);

  return 0;
}
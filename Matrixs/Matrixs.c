// Ethan Gao 
// KU ID: 3121537
// Lab Session: Thrusday
// Lab: 5
// Collaborators: None


#include <stdlib.h>
#define SIZE 5 

void readMatrix(int matrix[SIZE][SIZE], int rows, int cols)
{
  printf("\nEnter elements: \n");
  for (int i = 0; i < rows; i++) 
  {
    for (int j = 0; j < cols; j++) 
    {
      printf("Row: %d, Col: %d\n", i, j);
      scanf("%d", &matrix[i][j]);
    }
  }
}
int main()
{
  int m1[SIZE][SIZE];
  int m2[SIZE][SIZE];

  int cols1, rows1, cols2, rows2;

  printf("Enter rows and columns for the first matrix: ");
  scanf("%d%d", &rows1, &cols1);
  if(rows1 > SIZE || cols1 > SIZE)
  {
    printf("The max rows and cols is 5");
    return -1;
  }
  readMatrix(m1, rows1, cols1);

  printf("Enter rows and columns for the second matrix: ");
  scanf("%d%d", &rows2, &cols2);
  if(rows2 > SIZE || cols2 > SIZE)
  {
    printf("The max rows and cols is 5");
    return -1;
  }
  readMatrix(m2, rows2, cols2);

  printf("Choose the operation:\n");
  printf("1. Add matrices\n2. Multiply matrices\n
    3. Transpose matrix\n4. 4. Print matrix\n");
    scanf("%d", &choice);
  return 0;
}
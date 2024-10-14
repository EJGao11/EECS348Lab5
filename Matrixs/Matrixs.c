// Ethan Gao 
// KU ID: 3121537
// Lab Session: Thrusday
// Lab: 5
// Collaborators: None


#include <stdlib.h>
#define SIZE 5 

static sResultMatrix[SIZE][SIZE];

void readMatrix(int matrix[SIZE][SIZE], int rows, int cols)
{
  printf("\nEnter elements: \n");
  for (int i = 0; i < rows; i++) 
  {
    for (int j = 0; j < cols; j++) 
    {
      printf("Row: %d, Col: %d \n", i, j);
      scanf("%d", &matrix[i][j]);
    }
  }
}

void addMatrix(int matrix1[SIZE][SIZE], int matrix2[SIZE][SIZE], int rows, int cols) 
{
  for (int i = 0; i < rows; i++) 
  {
    for (int j = 0; j < cols; j++) 
    {
      sResultMatrix[i][j] = matrix1[i][j] + matrix2[i][j];
    }
  }
}

void matrixTranspose (int matrix[SIZE][SIZE], int rows, int cols) 
{
  for (int i = 0; i < rows; i++) 
  {
    for (int j = 0; j < cols; j++) 
    {
      sResultMatrix[j][i] = matrix[i][j];
    }
  }
}

void printMatrix(int matrix[SIZE][SIZE], int rows, int cols) 
{
  printf("Matrix:\n");
  for (int i = 0; i < rows; i++) 
  {
    for (int j = 0; j < cols; j++) 
    {
      printf("%d\t", matrix[i][j]);
    }
      printf("\n");
  }
}

int main()
{
  int m1[SIZE][SIZE];
  int m2[SIZE][SIZE];

  int cols1, rows1, cols2, rows2;
  int choice, matrixChoice;

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
  printf("1. Add matrices\n2. Multiply matrices\n3. Transpose matrix\n4. 4. Print matrix\n");
  scanf("%d", &choice);
  
  switch (choice)
  {
    case 1:
      if(rows1 == rows2 && cols1 == cols2)
      {
        addMatrix(m1,m2,rows1,cols1);
        printf("Results: ");
        printMatrix(sResultMatrix,rows1,cols1);
      }
      else
      {
        printf("Can't add matrixs");
      }
      break;

    case 2:
      if(cols1 == rows2)
      {
        multipleMatrix();
      }
      else
      {
        printf("Can't multiple matrixs");
      }
      break;

    case 3:
      printf("Which Matrix do you want to Transpose: ");
      scanf("%d", &matrixChoice);
      if(matrixChoice == 1)
      {
        matrixTranspose(m1,rows1,cols1);
        printf("Results: ");
        printMatrix(sResultMatrix,cols1,rows1);
      }
      else if(matrixChoice == 2)
      {
        matrixTranspose(m2,rows1,cols1);
        printf("Results: ");
        printMatrix(sResultMatrix,cols2,rows1);
      }
      else
      {
        printf("Not a vaild matrix");
      }
      break;

    case 4:
      printf("Which Matrix do you want to Print: ");
      scanf("%d", &matrixChoice);
      if(matrixChoice == 1)
      {
        printMatrix(m1,rows1,cols1);
      }
      else if(matrixChoice == 2)
      {
        printMatrix(m2,rows2,cols2);
      }
      else
      {
        printf("Not a vaild matrix");
      }
      break;

    default:
      printf("Invaild Operations");
      break;
  }
  return 0;
}
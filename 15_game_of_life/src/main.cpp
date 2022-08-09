#include <iostream>
#include<windows.h>


using namespace std;

// creates row boundary
void row_line(int col)
{
    cout << endl;
    for (int i = 0; i < col; i++) {
        cout << " -----";
    }
    cout << endl;
}

// returns the count of alive neighbours
int count_live_neighbour_cell(int **matrix, int dim1,int dim2,int row, int col)
{
    int i, j, count = 0;
    for (i = row - 1; i <= row + 1; i++) 
    {
        for (j = col - 1; j <= col + 1; j++) 
        {
            if ((i == row && j == col) || (i < 0 || j < 0) || (i >= dim1 || j >= dim2)) {
                continue;
            }
            if (matrix[i][j] == 1) {
                count++;
            }
        }
    }
    return count;
}

int main()
{
    int **a, **b,option,row=0,col=0,numberTicks=0,counter=0;
    int i, j;
    int neighbour_live_cell;

   cout << "Welcome to the game!" << endl;
   cout << "\nPlease choose an option" << endl;
   cout << "1. I want a specify the size grid." << endl;
   cout << "2. I choose the default size gride." << endl;
   cin >> option;

   if (option == 1)
   {
       cout << "\nInsert the number of lines: ";
       cin >> row;
       cout << "Insert the number of columns: ";
       cin >> col;

       a = new int* [row];
       for (int i = 0; i < row; i++)
           a[i] = new int[col];

       b = new int* [row];
       for (int i = 0; i < row; i++)
           b[i] = new int[col];
   }
   else if(option == 2)
   {
       row = 20;
       col = 20;

       a = new int* [row];
       for (int i = 0; i < row; i++)
           a[i] = new int[col];

       b = new int* [row];
       for (int i = 0; i < row; i++)
           b[i] = new int[col];
   }
   else
   {
       return 0;
   }
   
   cout << "\nInsert number of ticks: ";
   cin >> numberTicks;

   system("CLS");

   do 
   {
       for (i = 0; i < row; i++) {
           for (j = 0; j < col; j++) {
               a[i][j] = rand() % 2;
           }
       }

       cout << "Current Stage:";
       row_line(col);
       for (i = 0; i < row; i++) {
           cout << ":";
           for (j = 0; j < col; j++) {
               cout << "  " << a[i][j] << "  :";
           }
           row_line(col);
       }

       for (i = 0; i < row; i++) {
           for (j = 0; j < col; j++) {

               neighbour_live_cell = count_live_neighbour_cell(a, row, col, i, j);
               if (a[i][j] == 1 && (neighbour_live_cell == 2 || neighbour_live_cell == 3))
               {
                   b[i][j] = 1;
               }

               else if (a[i][j] == 0 && neighbour_live_cell == 3)
               {
                   b[i][j] = 1;
               }

               else
               {
                   b[i][j] = 0;
               }
           }
       }

       cout << "\nNext Generation:";
       row_line(col);
       for (i = 0; i < row; i++) {
           cout << ":";
           for (j = 0; j < col; j++) {
               cout << "  " << b[i][j] << "  :";
           }
           row_line(col);
       }

       Sleep(1000);
       system("CLS");
       
       counter++;
 
   } while (numberTicks!=counter);



    return 0;
}



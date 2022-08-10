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

bool isValidShape(std::string str)
{
    if (str != "Block" && str != "Blinker" && str != "Beacon" && str != "Boat")
    {
        return false;
    }
    return true;
}

int** DrawShape(std::string nameShape, int X, int Y)
{
    int** matrix = new int* [X];
    for (int i = 0; i < Y; i++)
        matrix[i] = new int[Y];

    if (nameShape == "Block")
    {
        for (int i = 0; i < X; i++) 
        {
            for (int j = 0; j < Y; j++)
            {
                if ((i == 0 && (j == 0 || j == 1)) || (i == 1 && (j == 0 || j == 1)) )
                {
                    matrix[i][j]=1;
                }
                else
                {
                    matrix[i][j] = 0;
                }
           }
       }
    }
    else if (nameShape == "Boat")
    {
        for (int i = 0; i < X; i++)
        {
            for (int j = 0; j < Y; j++)
            {
                if ((i == 0 && (j == 0 || j == 1)) || (i == 1 && (j == 0 || j == 2)) || (i==2 && j==1))
                {
                    matrix[i][j] = 1;
                }
                else
                {
                    matrix[i][j] = 0;
                }
            }
        }
    }
    else if (nameShape == "Blinker")
    {
        for (int i = 0; i < X; i++)
        {
            for (int j = 0; j < Y; j++)
            {
                if (i == X / 2  && (j==1 || j==2 || j==3))
                {
                    matrix[i][j] = 1;
                }
                else
                {
                    matrix[i][j] = 0;
                }
                
            }
        }
    }
    else if (nameShape == "Beacon")
    {
        for (int i = 0; i < X; i++)
        {
            for (int j = 0; j < Y; j++)
            {
                if (i == 0 && j==0 )
                {
                    matrix[i][j] = matrix[i][j + 1]= matrix[i + 1][j]= matrix[i + 2][j + 3]= matrix[i + 3][j + 2]= matrix[i + 3][j + 3] = 1;
                   
                }
                else
                {
                    if (matrix[i][j] != 1)
                    {
                        matrix[i][j] = 0;
                    }
                }

            }
        }
    }
    else if (nameShape == "Glider")
    {
        for (int i = 0; i < X; i++)
        {
            for (int j = 0; j < Y; j++)
            {
                if (i == X / 2 && (j == 1 || j == 2 || j == 3))
                {
                    matrix[i][j] = 1;
                }
                else
                {
                    matrix[i][j] = 0;
                }

            }
        }
    }
    else
    {
        for (int i = 0; i < X; i++)
        {
            for (int j = 0; j < Y; j++)
            {
                matrix[i][j] = 0;
            }
        }
    }

    return matrix;
}

int main()
{
    int **a, **b,option,row=0,col=0,numberTicks=0,counter=0,i,j, neighbour_live_cell;
    std::string desiredShape;

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

   cout << "\nWhat shape do you wanna?\n";

   cin >> desiredShape;
  
   if (!isValidShape(desiredShape))
   {
       return 0;
   }
   system("CLS");

   a = DrawShape("Beacon", row, col);

   do 
   {
       /*for(i=0;i<row;i++)
           for(j=0;j<col;j++)
           { 
               a[i][j] = rand()%2;
           }*/
       
       cout << "Is it fun, isn't it? :D" << endl;
       cout << "\nCurrent Stage (" << counter << ")";
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

       cout << "\nNext Generation ("<<counter+1<<")";
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

   delete[]a;
   delete[] b;

   return 0;
}



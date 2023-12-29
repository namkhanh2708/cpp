#include<iostream>
#include<limits>
#include <cmath>
using namespace std;//no need to use std everywhere
void getdata2();
void select();
void performMatrixOperation();

int main()
{ 
  while(true)
  {
    select();
  }
  return 0;
}

void select()
{
  int getdata;
   cout<<"\n Would you like to work with matrices (1) or numbers(2)?"<<endl;
   cin>> getdata;
   if(getdata==1)
   {
    performMatrixOperation();
   } 

   else if (getdata==2){
    getdata2();
   }
  else{
    if(cin.fail()){
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cout<<"Error 404!"<<endl;
      cin>>getdata;
     }
    }
 }

void getdata2(){//void doesn't return a value(no need to add return at the end)
float x, y;
  cout<<"Enter two numbers x and y: ";
  cin>>x>>y;

  char op;
  cout<<"Enter the math operation: + * - / ^\n ";
  cin>>op;

  switch(op){
    case '+' :cout<<" "<< x+y;
     break;
    case '-' :cout<<" "<< x-y;
     break;
    case '*' :cout<<" "<< x*y;
     break;
    case '/' :cout<<" "<< x/y;
     break;
    case '^' :cout<<" "<< pow(x, y);
    break;
    default: cout<<"Error 404!";
  }
}
  // Function to perform matrix operations
void performMatrixOperation() {
    int matrix1[3][3];
    int matrix2[3][3];
    int result[3][3];

    // ask user to input the first matrix
    int i, j;
    cout << "Enter matrix1 (3x3):\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin>>matrix1[i][j];
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout<<matrix1[i][j] << "\t";
        }
        cout << "\n";
    }

    cout << "Enter matrix2 (3x3):\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin>>matrix2[i][j];
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << matrix2[i][j] << "\t";
        }
        cout << "\n";
    }

  int matrixop;
  cout<<"1. Matrix addition:\n2. Matrix subtraction: \n";
  cin>> matrixop;

  if ( matrixop==1 ){
     cout << "Sum of matrices:" << "\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << matrix1[i][j] + matrix2[i][j] << "\t";
        }
        cout << "\n";
    }
  }
  else if( matrixop == 2){
     cout << "Difference of matrices:" << "\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << matrix1[i][j] - matrix2[i][j] << "\t";
        }
        cout << "\n";
    }
  }
  else{
    if(cin.fail()){
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cout<<"Error 404!"<<endl;
      cin>>matrixop;
     }

  }
}

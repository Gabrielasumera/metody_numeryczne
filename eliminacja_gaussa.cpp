#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
#include <ctime>
#include <cstdlib>


using namespace std;



bool eliminacja_gaussa ( int n, double ** M, double * X )
{

  int i, j, k;
  double m, s;
    
 

  for( i = 0; i < n - 1; i++ )
  {
    for( j = i + 1; j < n; j++ )
    {
      if( M [ i ][ i ] == 0 ) return false;
      m = -M [ j ][ i ] / M [ i ][ i ];
      for( k = i + 1; k <= n; k++ )
        M [ j ][ k ] += m * M [ i ][ k ];
    }
  }



  for( i = n - 1; i >= 0; i-- )
  {
    s = M [ i ][ n ];
    for( j = n - 1; j >= i + 1; j-- )
      s -= M [ i ][ j ] * X [ j ];
    if( M [ i ][ i ]  == 0 ) return false;
         X [ i ] = s / M [ i ][ i ];
  }
  return true;
}


int main( )
{
    
    
  
  double  **M,*X;
  int  i, j;
  int n = 3;

  X  = new double [ n ];
    M = new double * [ n ];
  for( i = 0; i < n; i++ ) M [ i ] = new double [ n + 1 ];

  
   
 


for( int i = 0; i < n; i++ )
     for( int j = 0; j <= n; j++ ) M[ i ][ j ]  = 0;
// wczytanie pliku



ifstream a("a.txt");
    
    while (!a.eof())
        for(int i=0; i<n; i++)
    {
        for (int j=0; j<=n; j++)
    {
        a >> M[i][j];
        }
 
    }
    
        a.close();
 
 
cout<<"Macierz: "<<endl;
     for(int i=0; i<n; i++)
    {
        for (int j=0; j<=n; j++)
    {
        cout<< M[i][j]<< " ";
        }
        cout<<endl;
    }
cout<<endl;


  if( eliminacja_gaussa ( n, M, X ) )
  { 
    cout << "Uklad jest oznaczony" <<endl<<endl;
    for( i = 0; i < n; i++ )
    
      cout << "x" << i + 1 << " = " << X [ i ]
           << endl;
  }
  else 
  cout << "Uk³ad jest sprzeczny lub nieoznaczony\n";
 
  

  return 0;
}

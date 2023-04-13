#include <bits/stdc++.h>
#include <cmath>
#include <iostream>

using namespace std;
 


float f(float x, float y)
{

    return 2x;
}
 

float rungeKutta(float x0, float y0, float x, float h)
{

    int n = ((x - x0) / h);
    float k1, k2;
    float y = y0;


cout<<"\nx0\ty\n";
 cout<<"------------------\n";
    for (int i = 1; i <= n; i++) {


        k1 = h * f(x0, y);

        k2 = h * f(x0 + 0.5 * h,  y + 0.5 * k1);
       
        cout<< x0<<"\t"<< y<< endl;
 
        y = y + 0.5*k1 +  0.5*k2;

        x0 = x0 + h;

    }
   
    cout << x0<<"\t";
    return y;
}
 


int main()
{

    float x0 = 0, y = 0,

          x = 4, h = 0.5;
 
 
 
 

    cout << rungeKutta(x0, y, x, h);

    return 0;
}

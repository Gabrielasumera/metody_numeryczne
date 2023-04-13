#include<iostream>


#define f(x,y) 2*x

using namespace std;
int main()
{
 float x0, y0, xn, h, yn, k1, k2, k3, k4, k;
 int i, n;

 
 cout<<"x0 = ";
 cin>> x0;
 cout<<"y0 = ";
 cin >> y0;
 cout<<" xn = ";
 cin>>xn;
 cout<<" h =  ";
 cin>> h;

n = (xn-x0)/h;


 
 cout<<"\nx0\tyn\n";
 cout<<"------------------\n";
 cout<< x0<<"\t"<< y0<< endl;
 for(i=0; i < n; i++)
 {
  k1 = h * (f(x0, y0));
  k2 = h * (f((x0+h/2), (y0+k1/2)));
  k3 = h * (f((x0+h/2), (y0+k2/2)));
  k4 = h * (f((x0+h), (y0+k3)));
  k = (k1+2*k2+2*k3+k4)/6;
  yn = y0 + k;
  x0 = x0+h;
  cout<< x0<<"\t"<< yn<< endl;
  
  y0 = yn;
 }



 return 0;
}

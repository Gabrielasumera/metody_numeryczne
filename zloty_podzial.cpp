#include <iostream>
#include <cmath>
using namespace std;

double f(double x) {
return  ((x-1) *(x-4)* (x+2) *(x+5))/10;
//x*x*x + 6*x*x -7;
}


double minimum(double(*Fun)(double), double a, double b)
{

double q = 0.618;
double xl = b - q * (b - a);
double xp = a + q * (b - a);


while (b - a > 0.01)
{
if (Fun(xl) > Fun(xp))
{

a = xl;
xl = xp;
xp = a + q * (b - a);

}
else
{

b = xp;
xp = xl;
xl = b - q*(b - a);

}
}
return Fun((a + b) / 2.);
}
int main(int argc, char **argv)
{

cout <<"Minimum wynosi: "<< minimum(f, 1.0, 3.25);
return 0;
}

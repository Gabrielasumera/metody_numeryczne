#include <iostream>
#include <cmath>

using namespace std;


double funkcja(double x)
{
    return x*x - x - 5;
}
double pochodna(double x)
{
    return 2*x - 1;
}

double bisection(double a, double b, double dokladnosc)
{
    double fa,fb,x1,fx1;
    
    fa=funkcja(a);
    fb=funkcja(b);
    
    if(fa*fb>0) cout<<"Zle dane.";
    else
    {
        while(fabs(a-b)>dokladnosc)
        {
            x1 =(a+b)/2;
            fx1 = funkcja(x1);
            
            if(fabs(fx1)<dokladnosc) break;
            
            if(fx1*fa <0)   b=x1;
            
            else{
                a=x1;
                fa=fx1;
            }
            
        }
       
    }
    return (a+b)/2;
}

double newton(double dokladnosc,double x0)
{
    double x1,f1,fx0;
    
    x1 = x0 -1;
    fx0= funkcja(x0);
    
    while((fabs(x1 - x0)) > dokladnosc && (fabs(fx0) > dokladnosc))
    {
        
        f1 = pochodna(x0);
        
        if(fabs(f1)<dokladnosc)
        {
            cout<<"Zalozenia nie zostaly spelnione";
            break;
        }
        
        x1 = x0;
        x0= x0-fx0/f1;
        fx0 = funkcja(x0);
        
    }
    
   return x0;
}

int main()
{
    double a,b,dokladnosc;
    
    cin>>a;
    cin>>b;
    cin>>dokladnosc;
    
    cout<<" METODA BISEKCJI: "<<bisection(a,b,dokladnosc)<<endl;
    cout<<" METODA NEWTONA-RAPHSONA: "<<newton(dokladnosc, a);
       
    return 0;
}


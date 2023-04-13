#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

double funkcja(double x)
{
	return x*x*x  + 2;
}

int main()
{
	double xp, xk,n, h;
	
	cout << "Podaj przedzial <xp, xk>" << endl;
	cin >> xp;
	cin >> xk;
	cout << "Podaj liczbe podprzedzialow:" << endl;
	cin >> n;

	h = ((xk - xp) /(2*n));


	double calka = 0;

	for (int i = 0; i <= n-1; i++)
	{

		calka += (funkcja(xp + 2*h*i) + 4 * funkcja(xp + 2*h *i + h) + funkcja(xp + 2*h*i + 2*h));
	}

	calka = calka * h/3;
	
	cout << "METODA SIMPSONA: " <<endl;
	cout <<"wynik = "<< calka << endl <<endl;

	srand(time(NULL));

	double calka2 = 0;
	double s = 0;
	double xRand, f;

	for (int j = 0; j <= n-1; j++)
	{
		xRand = xp + (float(rand()) / RAND_MAX) * (xk - xp);
		f = funkcja(xRand);
		s+= f;
		
		cout<<"Wylosowana liczba "<<endl;
		cout<< "x[" <<j<<"] = "<<xRand<<endl;
		
	}

	calka2 = (s/n )* (xk - xp);

	cout <<endl << "METODA MONTE CARLO: " << endl;
	cout <<"wynik = "<< calka2 << endl <<endl;


	return 0;
}

#include<iostream>
#include<conio.h>

using namespace std;

int main()
{
	double x[100];
	double y[100];
	double	x_punktu, y_punktu = 0.0;
	double l;
	int i, j, n;


	cout << "Wpisz liczbe znanych punktow: ";
	cin >> n;
	cout << "Wpisz wspolrzedne punktow:" << endl;
	for (i = 0;i < n;i++)
	{
		cout << "x" << i << " = ";
		cin >> x[i];
		cout << "y" << i << " = ";
		cin >> y[i];
	}
	cout << "Wpisz wspolrzedna x punktu ,dla ktorego szukamy wartosci: ";
	cin >> x_punktu;

	//funkcja interpolujaca

	for (i = 0;i < n;i++)
	{
		double l = 1.0;
			
		for (j = 0;j < n;j++)
		
			if (i != j);
			
				//double l = 1.0;
				l = l * (n - x[j]) / (x[i] - x[j]);

			

			y_punktu = y_punktu + l * y[i];

		
	}
	cout << endl << "Wartosc funkcji interpolujacej w punkcie  " << x_punktu << " wynosi " << y_punktu;

	return 0;
}

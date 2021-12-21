#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <math.h>
#include <time.h>
#include <iomanip>
#include<fstream>

#define realResult 0.8862073482595212338
#define a 0
#define b 3
#define delta 0.0001
#define e 2.7182818284590452
using namespace std;

double f(double x)
{
	return pow(e, -pow(x, 2));
}

double MonteCarloMethod(int N)
{
	double random;
	double x;
	double sum = 0.0;
	double I = 0.0;
	//Итак, бросаем N точек, равномерно распределенных на [a, b], для каждой точки 𝑢𝑖 вычисляем f(𝑢𝑖). 
	for (int i = 1; i <= N; i++)
	{
		random = double(rand()) / double(RAND_MAX);
		x = a + (b - a) * random;
		sum += f(x);
		I = sum / N;
	}
	return ((b - a) * I);;
}

//f(x) = e^-x^2,  [a,b] = [0, 3],   delta = 10^(-4)
int main()
{
	cout.precision(15);
	cout << "N6." << endl;
	srand(time(0));

	//cout << "[";
	double MonteCarlo = 0.0;
	double Expected = 0.0;
	for (int n = 1; n <= 600; n++)
	{
		MonteCarlo = 0;
		for (int i = 1; i <= 100; i++) //выборка
		{
			MonteCarlo += MonteCarloMethod(n);

		}
		MonteCarlo = MonteCarlo / 100.0;
		//cout << "[" << (int)n << "," << abs(MonteCarlo - realResult) << "],"; //вывод точек для графика
	}

	cout << "Real integral result: " << realResult << endl;
	cout << "Monte-Carlo method result: " << MonteCarlo << endl;
	cout << "Monte-Carlo method error: " << abs(realResult - MonteCarlo) << endl;
	cout << "_________________________________________________________" << endl;

	return 0;
}
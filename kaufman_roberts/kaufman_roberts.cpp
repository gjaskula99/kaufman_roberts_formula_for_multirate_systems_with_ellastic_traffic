#include "stdafx.h"
#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	const int V = 10; //Pojemność
	const int M = 2; //Liczba klas ruchu
	int A[M] = { 0 }; //Ruch oferowanyk A
	int T[M] = { 0 }; //Liczba żądanych jednostek T
	A[0] = 5;
	T[0] = 1;
	A[1] = 10;
	T[1] = 5;

	double kauff[V + 1] = { 0.0 };
	double G = 1;
	kauff[0] = 1;

	for (int n = 1; n <= V; n++) //Pojemność
	{
		for (int i = 0; i < M; i++) //Klasy
		{
			cout << n << " " << T[i] <<  " " << n - T[i] << " ";
			if ((n - T[i]) == 0) kauff[n] += 1.0;
			else if ((n - T[i]) < 0) kauff[n] += 0.0;
			else kauff[n] += ( (double)A[i] * (double)T[i] * kauff[n - T[i]] ) / (double)n;
		}
		cout << kauff[n] << "\n";
		G += kauff[n];
	}

	cout << G << "\n";
	for (int n = 0; n <= V; n++) //Normalizacja
	{
		kauff[n] /= G;
		cout << kauff[n] << "\n";
	}
	return 0;
}

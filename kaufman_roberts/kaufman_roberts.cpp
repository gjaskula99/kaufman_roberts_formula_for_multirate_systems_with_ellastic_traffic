#include "stdafx.h"
#include <iostream>
#include <string>
#include <math.h>
#include <fstream>

using namespace std;

int main()
{
	fstream input;
	string input_name;
	int V = 1, M = 1;
	int* A = new int[M];
	int* T = new int[M];
	cout << "Enter input file name: ";
	cin >> input_name;
	input.open(input_name, ios::in);
	if (input.is_open() && input.good())
	{
		
		input >> V;
		input >> M;
		cout << "V = " << V << "\t";
		cout << "M = " << M << "\n";
		int counter = 0;
		while (!input.eof() && counter < M)
		{
			input >> A[counter];
			input >> T[counter];
			cout << "A[" << counter << "] = " << A[counter] << "\t";
			cout << "T[" << counter << "] = " << T[counter] << "\n";
			counter++;
		}
	}
	else
	{
		cout << "Error opening file " << input_name << "\n";
		return -1;
	}


	double* kauf = new double[V + 1];
	for (int i = 0; i < V + 1; i++) kauf[i] = 0.0;
	double G = 1;
	kauf[0] = 1;

	for (int n = 1; n <= V; n++)
	{
		for (int i = 0; i < M; i++)
		{
			if ((n - T[i]) == 0) kauf[n] += 1.0;
			else if ((n - T[i]) < 0) kauf[n] += 0.0;
			else kauf[n] += ( (double)A[i] * (double)T[i] * kauf[n - T[i]] ) / (double)n;
		}
		G += kauf[n];
	}

	fstream output;
	output.open("output.txt", ios::out);
	if (output.is_open() && output.good())
	{
		for (int n = 0; n <= V; n++)
		{
			kauf[n] /= G;
			cout << "E(V = " << n << ") = " << kauf[n] << "\n";
			output << kauf[n] << "\n";
		}
	}
	else
	{
		cout << "Error creating or opening output file\n";
		return -1;
	}
	
	return 0;
}

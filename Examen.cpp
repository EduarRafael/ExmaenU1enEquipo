#include <iostream>
#include <fstream>
#include <ctype.h>
#include <cstdlib>
#include <sstream>
#include <stdlib.h>

using namespace std;

int main() {

	char cadena[500];
	char cadena2[500];
	float cordenadas[50];
	float cordenadas2[50];
	float A[100][100];
	float B[100][100];
	float C[100][100];
	//primer txt
	ifstream fe("EstRch.txt");

	int contador = 0;
	int verificador = 0;
	int palabras = 0;
	int tem = 0;

	cout << "Primer txt" << endl;

	while (!fe.eof()) {
		contador++;
		if (contador > 9) {
			verificador++;
			if (verificador > 1) {
				//aqui se guarda x/y
				palabras++;
				fe >> cadena;
				//cout << cadena << endl;
				cordenadas[palabras - 1] = atof(cadena);
			}
			else if (verificador == 1) {
				fe >> cadena;
			}

			if (verificador == 3) {
				verificador = 0;
			}
		}
		else {
			fe >> cadena;
		}
	}
	palabras = palabras / 2;
	

	//llenar la matriz a 
	for (int i = 0; i < palabras; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			A[i][j] = cordenadas[tem];
			tem++;
			if (j == 0) {
				cout << "x: " << A[i][j] << " ";
			}
			else {
				cout << "y: " << A[i][j] << endl;
			}

		}
	}
	tem = 0;
	fe.close();
	palabras = 0;


	cout << " " << endl;
	cout << " " << endl;
	cout << "Segundo txt" << endl;
	int contador2 = 0, verificador2 = 0;
	ifstream fe2("Problem10-Fisher.txt");
	while (!fe2.eof()) {
		contador2++;
		if (contador2 > 28) {
			verificador2++;
			if (verificador2 > 1) {
				//aqui se guarda x/y
				palabras++;
				fe2 >> cadena2;
				//cout << cadena2 << endl;
				cordenadas2[palabras - 1] = atof(cadena2);
			}
			else if (verificador2 == 1) {
				fe2 >> cadena2;
			}

			if (verificador2 == 3) {
				verificador2 = 0;
			}

		}
		else {

			fe2 >> cadena2;
		}
	}

	palabras = palabras / 2;
	for (int i = 0; i < palabras; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			B[i][j] = cordenadas2[tem];
			tem++;
			if (j == 0) {
				cout << "x: " << B[i][j] << " ";
			}
			else {
				cout << "y: " << B[i][j] << endl;
			}

		}
	}

	fe2.close();


	system("PAUSE");
	return 0;
}

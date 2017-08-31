/*
Se implementará el metodo de solucion de sistemas de ecuaciones iterativo gauss - seidel

	|			|
	|	2x + y  |  10
	|	3x + 4y |  20
	|			|
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <stdlib.h>
#include <windows.h>
#include "Diseno.h"

using namespace std;

void Ec_System_Init(vector <float>& , vector<float> & , vector<float> &, vector<float> &, vector<float> &);
void imprimirVector(vector<float> matriz, vector<float> resultados);
bool val_System(vector <float> , int dimensions);
void evolveVariables(vector <float> & , vector<float> independent , vector<float> &variables , const int varNum);

int getDimensions(vector <float>);

int main(){
    float error = 0;
    int bandera = 0, i = 1;

	//Hacer validaciones: que los elementos de la diagonal principal sean distintos a 0
	//					  que el valor de cada elemento de la diagonal se superior a la suma
	//					  del valor absoluto de sus elementos restantes

	//matrix guardara los numeros de las ecuaciones
	vector<float> matrix;

	//independent guardara los numeros independientes
	vector<float> independent;

	//variables guardara las variables, osea los resultados, en un principio estan en 0
	//Se hará un push_back segun el orden de la matriz
	//Ejem: 2x + 3y; 4x + 5y; dos ecuaciones (orden 2), dos push_back() variables.size() = 2;
	vector<float> variables;
	vector<float> variables_an;
	vector<float> errores;


	//Usuario ingresa valores de la ecuacion y se inicializan los vectores
	Ec_System_Init(matrix , independent , variables, variables_an, errores);
    cout << "Porcentaje de error:" ;
    cin >> error;
	//Se valida los elementos de la diagonal principal no sean 0
	//Implementar pivoteo parcial, para poder intentar cumplir con los criterios de convergencia
	if(!val_System(matrix , getDimensions(independent) ) ){
		cout << "Un elemento de la diagonal principal es 0" << endl;
		return 0;
	}

	//ciclo iterativo, crear vector error; hacer un while mientras el error sea mayor al aceptable
	while(bandera != variables.size()){
        bandera = 0;
		//cout << "Iteracion " << (i + 1) << endl;
		i++;
		evolveVariables(matrix , independent , variables , variables.size());
		for(int j = 0; j < variables.size(); j++){
            errores[j] = (variables[j] - variables_an[j])/variables[j]*100;
            if(errores[j] < 0){
                errores[j] = errores[j] * (-1);
            }
            if(errores[j] < error){
                bandera++;
            }
		}
        for(int j = 0; j < variables.size(); j++){
			variables_an[j] = variables[j];
		}
	}

	for(int j = 0; j < variables.size(); j++){
			cout << "Valor de la variable x subindice" << j << ": " << variables[j] << endl;
			cout << "Cuenta con un error del : " << errores[j] << "%" << endl;
	}
	return 0;
}

void Ec_System_Init(vector <float> &matrix , vector<float> &independent, vector<float> &variables, vector<float> &v, vector<float> &e){

	/*
	Prueba 1
	matrix.push_back(5);
	matrix.push_back(-2);
	matrix.push_back(1);
	matrix.push_back(3);


	Igualaciones de las ecuaciones respectivamente
		5x - 2y = 13
		x + 3y = 6
	independent.push_back(13);
	independent.push_back(6);
	*/

	/*
	Prueba 2
	matrix.push_back(3);
	matrix.push_back(-0.1);
	matrix.push_back(-0.2);
	matrix.push_back(0.1);
	matrix.push_back(7);
	matrix.push_back(-0.3);
	matrix.push_back(0.3);
	matrix.push_back(-0.2);
	matrix.push_back(-10);

	independent.push_back(7.85);
	independent.push_back(-19.30);
	independent.push_back(71.40);
	*/
	system(size);
	system("cls");
	//amountEcuations, es la cantidad de variables, por lo que amEc*amEc = numero total de elementos en matrix
	//amountEcuations, numero de elementos en independent y en variables
	int amEc;
	cout << "Ingrese el numero de ecuaciones (el orden de la matriz): ";
	cin >> amEc;
	while(amEc < 0){
		cout << "Ingrese el numero de ecuaciones (el orden de la matriz): ";
		cin >> amEc;
		system("cls");
	}
	system("cls");
	std::vector<float> maTemporal(amEc*amEc, 0), resTemporal(amEc,0);
	/*
	for(int i = 0; i < amEc*amEc; i++){
		float elem;
		cout << "Ingrese el elemento " << i << endl;
		cin >> elem;
		matrix.push_back(elem);
		system("cls");
	}
	*/
	for(int i = 0; i < amEc*amEc; i++){
		float elem;
		imprimirVector(maTemporal,resTemporal);
		std::cout << "Ingrese el elemento " << i << std::endl;
		std::cin >> elem;
		maTemporal.at(i) = elem;
		system("cls");
	}
	matrix = maTemporal;
	/*
	for(int i = 0; i < amEc; i++){
		float elem;
		cout << "Ingrese el elemento independiente de la ecuacion " << i << endl;
		cin >> elem;
		independent.push_back(elem);
		system("cls");
	}*/
	for(int i = 0; i < amEc; i++){
		float elem;
		imprimirVector(maTemporal,resTemporal);
		cout << "Ingrese el elemento independiente de la ecuacion " << i << endl;
		cin >> elem;
		resTemporal.at(i) = elem;
		system("cls");
	}
	independent = resTemporal;
	cout << "\t\t\tMatriz con la que se estara trabajando, presione una tecla para continuar";
	imprimirVector(matrix, independent);
	system("pause");
	//Variables contendrá el resultado, en un comienzo estan en 0
	for(int i = 0; i < independent.size(); i++){
		variables.push_back(0);
		v.push_back(0);
		e.push_back(0);
	}

}

void imprimirVector(std::vector<float> matriz, std::vector<float> resultados)
{
	int i = 0, g =0;
	std::string apertura= "\t\t\t\t";
	for(std::vector<float>::size_type j = 0; j != matriz.size(); j++) {
		if(j == 0){
			std::cout << apertura << "[" << matriz[j] << "\t";
		}
		else if((j+1)% resultados.size() == 0){
			 std::cout << matriz[j] << "]" << "\t";
			 std::cout << "[" << resultados[g++] << "]" << std::endl; 
			 if((j+1) != matriz.size())
			 	std::cout << apertura << "[";
		}else
    		std::cout << matriz[j] << "\t";
	}
}

bool val_System(vector <float> matrix , int dimensions){

	int row = 0;
	int increase = dimensions;
	bool stop_Increase = 1;

	for( ; row < matrix.size(); row += increase){

		if(stop_Increase != 0){
			increase++;
			stop_Increase = 0;
		}

		if(matrix[row] == 0){
			return 0;
		}
	}

	return 1;
}

int getDimensions(vector <float>independent){
	return independent.size();
}

void evolveVariables(vector <float> &matrix , vector<float> independent , vector<float> &variables , const int varNum){
	int row = 0;
	//Ayuda a obtener la diagonal utilizando row
	int decreaser = varNum;
	int rowHelper;
	for(int i = 0; i < varNum; i++){
		rowHelper = 0;
		float suma = 0;
		//cout << independent[i];
		for( ; row < varNum*i + varNum; row++){
			if(rowHelper == i){
				rowHelper++;
				continue;
			}
			suma += -1*matrix[row]*variables[rowHelper];
			//cout << " + " << -1*matrix[row] << " * " << variables[rowHelper];
			rowHelper++;
		}
		//cout << endl;
		suma = independent[i] + suma;
		//cout << suma << "/" << matrix[row-decreaser];
		variables[i] = suma / matrix[row - decreaser];
		//cout << " = " << variables[i] << endl << endl;
		decreaser--;
	}
	//cout << endl;
}

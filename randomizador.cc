#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>
#include <vector>
#include <cmath>

/*
	Generar media,moda,etc...
*/


int menuOperaciones();
void llamarFunc(std::vector<float> &vec, int cantidad, float medAritmetica, int opc);
void randomDevice(int min, int max, int cantidad, int longitud);
float mediaAritmetica(std::vector<float> &vec, int cantidad);
float mediaGeometrica(std::vector<float> &vec, int cantidad);
float mediaArmonica(std::vector<float> &vec, int cantidad);
float desviacionMedia(std::vector<float> &vec, int cantidad, float medAritmetica);
float desviacionEstandar(std::vector<float> &vec, int cantidad, float medAritmetica);
float varianza(std::vector<float> &vec, int cantidad);
void moda(std::vector<float> &vec, int cantidad);


int menuOperaciones()
{
	int inp;
	do{
		std::cout << "Eliga la operacion a calcular\n0)Media Aritmetica\n1)Media Geometrica\n2)Media Armonica\n3)Desviacion Media\n4)Desviacion estandar\n5)Varianza\n6)Moda\n7)Imprimir numeros generados\n8)Salir\n:";
		std::cin >> inp;
	}while(inp > 8 || inp < 0);
	return inp;
}


void randomDevice(int min, int max, int cantidad, int longitud, std::vector<float> &vec)
{
	std::srand(std::time(0));
	std::mt19937 gen(std::time(0));
	std::uniform_real_distribution<double> d(min, max);
	for(int n = 0; n < cantidad; ++n){
		vec.push_back(d(gen));
    }
}

float mediaAritmetica(std::vector<float> &vec, int cantidad)
{
	float suma = 0.0;
    for (auto i : vec)
        suma = suma + i;
    suma = suma/cantidad;
    return suma;
}

float mediaGeometrica(std::vector<float> &vec, int cantidad)
{
	long long suma = 1.0;
    for (auto i : vec)
        suma = suma * i;
    std::cout << suma << std::endl;
    suma = pow(suma, 1/cantidad);
    return suma;
}

float mediaArmonica(std::vector<float> &vec, int cantidad)
{
	float suma = 0.0;
    for (auto i : vec)
        suma = suma + (1/i);
    suma = cantidad/suma;
    return suma;
}

float desviacionMedia(std::vector<float> &vec, int cantidad, float medAritmetica)
{
	float dm = 0.0;
    for (auto i : vec)
        dm = dm + abs(i-medAritmetica);
    dm = dm/cantidad;
    return dm;
}

float desviacionEstandar(std::vector<float> &vec, int cantidad, float medAritmetica)
{
	float s = 0.0;
    for (auto i : vec)
        s = s + (pow(i-medAritmetica, 2));
    s = s /cantidad;
    return pow(s,.5);
}

float varianza(std::vector<float> &vec, int cantidad, float medAritmetica)
{
	return pow(desviacionEstandar(vec, medAritmetica, cantidad), 2);
}

void moda(std::vector<float> &vec, int cantidad)
{
	
	std::vector <float> 	valores;
	std::vector <int> 	frecuencias;
	std::vector <float> 	moda;
	
	int maxfrec, cont = 0, frec;
	
	valores.push_back(vec[0]);
	for(int i = 1; i < cantidad; i++){
		cont = 0;
		for(int j = 0; j < valores.size(); j++){
			if(vec[i] == valores[j])
				break;
			cont++;
		}
		if(cont == valores.size())
			valores.push_back(vec[i]);
	}
	for(int i = 0; i < valores.size(); i++){
		frec = 0;
		for(int j = 0; j < cantidad; j++){
			if(valores[i] == vec[j])
				frec++;
		}
		frecuencias.push_back(frec);
		if(i == 0)
			maxfrec = frecuencias[0];
		if(frecuencias[i] > maxfrec)
			maxfrec = frecuencias[i];
	}
	
	std::cout << "Moda: " << std::endl;
	for(int i = 0; i < valores.size(); i++){
		if(frecuencias[i] == maxfrec)
			std::cout << valores[i] << std::endl;
	}
}

void llamarFunc(std::vector<float> &vec, int cantidad, float medAritmetica, int opc)
{
	switch(opc){
		case 0 :
			std::cout << "Media Aritmetica: " << medAritmetica << std::endl;
			break;
		case 1 :
			std::cout << "Media Geometrica: " << mediaGeometrica(vec, cantidad) << std::endl;
			break;
		case 2:
			std::cout << "Media Armonica: " << mediaArmonica(vec, cantidad) << std::endl;
			break;
		case 3:
			std::cout << "Desviacion Media: " << desviacionMedia(vec, cantidad, medAritmetica) << std::endl;
			break;
		case 4:
			std::cout << "Desviacion Estandar: " << desviacionEstandar(vec, cantidad, medAritmetica) << std::endl;
			break;
		case 5:
			std::cout << "Varianza: " << varianza(vec, cantidad, medAritmetica) << std::endl;
			break;
		case 6:
			moda(vec, cantidad);
			break;
		case 7 :
			std::cout << "Valores generados:\n"; 
			for(auto v : vec)
				std::cout << v << " ";
			std::cout << "\n"; 
			break;
		default: break;
	}
}

int main()
{
	int x = 0, y = 0, cantMax = 0, cantDig = 0, opc;
	std::vector<float> vec;
	float medAritmetica;
	do{
		std::cout << "Inserte la cantidad de numeros a generar: " << std::endl;
		std::cin >> cantMax;
	}while(cantMax <= 0 );
	system("cls");
	do{
		std::cout << "Seleccione la opcion:\n1)2 Digitos\n2)3 Digitos\n3) Especificar Digitos" << std::endl;
		std::cin >> x;
	}while(x <= 0 || x > 3);
	system("cls");
	if(x == 1)
		cantDig = 2;
	else if(x == 2)
		cantDig = 3;
	else{
		do{
			std::cout << "Inserte la cantidad de digitos posibles" << std::endl;
			std::cin >> cantDig;
		}while(cantDig <= 0);
		system("cls");
	}
	if(cantDig > 1){
		for(int i = 1; i <= cantDig; ++i)
			y = y + (pow(10,i)*9);
		y = (y + 9)/10;
	}else{y = 9;}
	randomDevice(-y, y, cantMax, cantDig, vec);
	medAritmetica = mediaAritmetica(vec, cantMax);
	do{
		opc = menuOperaciones();
		llamarFunc(vec, cantMax, medAritmetica, opc);
		system("pause");
		system("cls");
	}while(opc != 8);
	return 0;
}
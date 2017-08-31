#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>
#include <vector>


/*
	Generar media,moda,etc...
*/


void randomDevice(int min, int max, int cantidad, int longitud);

void randomDevice(int min, int max, int cantidad, int longitud, std::vector<float> &vec)
{
	std::srand(std::time(0));
	std::mt19937 gen(std::time(0));
	std::uniform_real_distribution<float> d(min, max);
	for(int n = 0; n < cantidad; ++n){
		vec.push_back(d(gen));
    }
}

int main()
{
	int x = 0, y = 0, cantMax = 0, cantDig = 0;
	std::vector<float> vec;
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
	for(auto n : vec){
    	std::cout << n << "Tipo: " << n.type() << std::endl;
    }
	return 0;
}
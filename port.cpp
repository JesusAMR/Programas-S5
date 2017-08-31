#include <iostream>
#include <vector>
#include <cstdlib>

/*
	[1,2][10]
	[3,4][20]

	[1,2,3][10]
	[4,5,6][20]
	[7,8,9][30]
	
	123456789

*/

void imprimirVector(std::vector<float> matriz, std::vector<float> resultados);

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

int main(int argc, char** argv)
{
	std::vector<float> mat1{1.3,2.4,3005.5,4.3,1.3,2.4,3.5,4,5.6,5,1.3,2.4,3.5,4,5.6,10.5}, res1{10.5,3.5,5.6,5.99};
	//std::vector<float> maTemporal;
	int i = 0, ecuac = atoi(argv[1]), g =0, amEc=0;
	std::string apertura= "\t\t\t\t";
	//for(float i = 1; i <= (ecuac*ecuac); i+=1.5){mat1.push_back(i);}
	//for(float i = 10; i <= (ecuac*10.5) ; i+=10.5){res1.push_back(i);}
	std::cout << "Ingrese el numero de ecuaciones (el orden de la matriz): ";
	std::cin >> amEc;
	while(amEc < 0){
		std::cout << "Ingrese el numero de ecuaciones (el orden de la matriz): ";
		std::cin >> amEc;
		system("cls");
	}
	system("cls");
	std::vector<float> maTemporal(amEc*amEc, 0), resTemporal(amEc,0);
	for(int i = 0; i < amEc*amEc; i++){
		float elem;
		imprimirVector(maTemporal,resTemporal);
		std::cout << "Ingrese el elemento " << i << std::endl;
		std::cin >> elem;
		maTemporal.at(i) = elem;
		system("cls");
	}
	for(int i = 0; i < amEc; i++){
		float elem;
		imprimirVector(maTemporal,resTemporal);
		std::cout << "Ingrese el elemento independiente de la ecuacion " << i << std::endl;
		std::cin >> elem;
		resTemporal.at(i) = elem;
		system("cls");
	}
	imprimirVector(mat1,res1);
	return 0;
}
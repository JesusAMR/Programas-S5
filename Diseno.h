#ifndef DISENO_H_INCLUDED
#define DISENO_H_INCLUDED
#include <iostream>
#include <stdio.h>
#define ENTER 13
void gotoxy(int x,int y){
      HANDLE hcon;
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);
      COORD dwPos;
      dwPos.X = x;
      dwPos.Y= y;
      SetConsoleCursorPosition(hcon,dwPos);
}

//Sirve para poder centrar textos
int centrar(char text[]){
    return (100 - strlen(text))/2;
}


char size[] = "MODE 100,40";


//Como se menciona, es una funcion para imprimir la portada de nuestro programa, simplemente imprimi los datos del equipo.
void Portada(){
    //Se imprime la animacion con los nombres de los integrantes del equipo
    int i = centrar("1791278 Rodrguez Quintanilla Luis Guillermo");
    int opc;

    gotoxy(centrar("Universidad Autonoma de Nuevo Leon"),1);printf("Universidad Aut%cnoma de Nuevo Le%cn",162,162);
    gotoxy(centrar("Facultad de Ciencias Fisico Matematicas"),2);printf("Facultad de Ciencias F%csico Matem%cticas",161,160);
    gotoxy(centrar("Circuitos Digitales"),4);printf("Circuitos Digitales");
    gotoxy(centrar("Producto Integrador"),5);printf("Producto Integrador");
    gotoxy(centrar("Equipo #5"),7);printf("Equipo #5");
    gotoxy(centrar("Integrantes:"),8);printf("Integrantes:");

    gotoxy(i,9);printf("1791276 Banda Reyes Eder Rodrigo");
    gotoxy(i,10);printf("1791339 Bustos Vargas Luis Roberto");
    gotoxy(i,11);printf("1631152 Morf%cn Cano Karla Mariel",161);
    gotoxy(i,12);printf("1791278 Rodr%cguez Quintanilla Luis Guillermo", 161);
    gotoxy(i,13);printf("1677963 Rodr%cguez Galindo Daniela",161);
    gotoxy(i,14);printf("1791319 S%cnchez Arias Daniel",160);
    gotoxy(i,15);printf("1730096 Aguilera Ru%cz Alejandro",161);
    gotoxy(i,16);printf("1638131 Abarca Villareal Carlos Alejandro");
    gotoxy(i,17);printf("1739918 Gonzales Candela Fernando Abiel\n");

    gotoxy(centrar("Presione Enter para continuar..."), 20); printf("Presione Enter para continuar...");
    do{
            std::cin >> opc;
    }while(opc != ENTER);
    system("cls");
}

#endif
from math import sqrt

def menuOpcion():
    opcion = input("Eliga la operacion a calcular\n0)Media Aritmetica\n1)Media Aritmetica Ponderada\n2)Media Geometrica\n3)Media Armonica\n4)Desviacion Media\n5)Desviacion estandar\n6)Varianza\n7)Moda\n:")

def mediaAritmetica(lista, cantLista):
    suma = 0.0
    for i in lista:
        suma = suma + i
    suma = suma/cantLista
    return float(suma)

def mediaArimeticaPonderada(lista):
    #ponderacion = input("Ingrese la ponderacion a considerar\n:")
    #for i in 

def mediaGeometrica(lista, cantLista):
    suma = 1.0
    for i in lista:
        suma = suma * i
    suma = suma**(1/cantLista)
    return suma

def mediaArmonica(lista, cantLista):
    suma = 0.0
    for i in lista:
        suma = suma + (1/i)
    suma = cantLista/suma
    return suma

def desviacionMedia(lista, medAritmetica, cantLista):
    dm = 0.0
    for i in lista:
        dm = dm + abs(i-medAritmetica)
    dm = dm/cantLista
    return float(dm)

def desviacionEstandar(lista, medAritmetica, cantLista):
    s = 0.0
    for i in lista:
        s = s + ((i-medAritmetica)**2)
    s = s /cantLista
    return sqrt(s)

def varianza(lista, medAritmetica, cantLista):
    return desviacionEstandar(lista, medAritmetica, cantLista)**2
condicion = 0
condicion = input("Desea\n0)Usar lista predefinida\n1)Ingresar datos de una lista\n:")

if condicion:
    lista = []
    numVariables = input("Ingrese el numero de variables \n:")
    for i in range(0,numVariables):
        temporal = input("Ingrese la variable "+str(i)+ "\n:")
        lista.append(temporal)
else:
    lista = [138,146,168,146,161,164,158,126,173,145,150,140,138,142,135,132,147,176,147,142,144,136,163,135,150,125,148,119,153,156,149,152,154,140,145,157,144,165,135,128]

lista.sort()
medAritmetica = mediaAritmetica(lista, len(lista))

condicion = input("Desea imprimir la lista ordenada\n0)Si\n1)No\n:")
if not condicion:
    for x in lista:
        print x

print "La media aritmetica es de : " + str(medAritmetica)

print "La desviacion media es de : " + str(desviacionMedia(lista, medAritmetica, len(lista)))

print "La desviacion estandar es de : " + str(desviacionEstandar(lista, medAritmetica, len(lista)))

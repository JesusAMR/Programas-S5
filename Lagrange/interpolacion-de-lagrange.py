def obtenerOperandos(x, vectorx, pos):
    j = 0
    lista = [1,1]
    for i in vectorx:
        if(j != pos):
            lista[0] = float(float(lista[0]) * (float(x) - float(i)))
            lista[1] = float(float(lista[1]) * (float(vectorx[pos]) - float(i)))
        j = j + 1
    return lista

    
def obtenerDivision(x, vectorx, pos):
    div = obtenerOperandos(x, vectorx, pos)
    """print "Dividendo:", div[0]
    print "Divisor:", div[1]"""
    if (div[1] != 0):
        division = float(float(div[0])/float(div[1]))
        #print "Division:", division
        return division
    else:
        return "NO"

def obtenerResultado(vectorx, vectory, x):
    res = 0
    pos = 0
    for coefy in vectory:
        div = obtenerDivision(x, vectorx, pos)
        if(div == "NO"):
            return "No se puede resolver por Interpolacion de Lagrange"
            break
        else:
            #print "Coeficiente y*div:", coefy*div
            res = res + div*coefy
            #print "Res parcial:", res
        pos = pos + 1
    return res

cantidad = ("Introduce cantidad de tabulaciones: ")
vectorx = []
vectory = []
for i in range(0,cantidad):
    print "Tabulacion ", i+1
    vectorx.append(input("x = "))
    vectory.append(input("y = "))

x = input("Introduce el valor de x: ")
res = obtenerResultado(vectorx, vectory, x)
print "Resultado:", res

"""
ay que validar que las x que te dan a calcular esten dentro de los intervalos que te dan
que dos x de las que te dan no sean iguales con una y diferente
"""
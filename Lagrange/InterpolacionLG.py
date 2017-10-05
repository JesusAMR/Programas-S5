#!/Python27/python
# -*- coding: utf-8 -*-

import cgi, cgitb

cgitb.enable()

form = cgi.FieldStorage()

grad = form.getvalue('grad')
cantx = form.getvalue('valx')
tabulaciones = int(grad)
cantx = int(cantx)
vectorx = []
vectory = []
vectorvalx = []
resultados = []
nombrex = "x"
nombrey = "y"
nombrevalx = "valorx"

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

for i in range(1,int(tabulaciones)+1):
    genx = nombrex + str(i)
    geny = nombrey + str(i)
    vectorx.append(float(form.getvalue(genx)))
    vectory.append(float(form.getvalue(geny)))

for i in range(0,cantx):
    valx = nombrevalx + str(i+1)
    vectorvalx.append(float(form.getvalue(valx)))
    resultados.append(obtenerResultado(vectorx, vectory, vectorvalx[-1]))

print "Content-Type: text/html"
print
print "<html>"
print """<!DOCTYPE html>
<html lang="es">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <link rel="stylesheet" href="Estilo.css">
    <title>METODO DE LAGRANGE</title>
</head>"""
print "<body>"

print "<p align = 'center'> <font size = '10'> Método de Lagrange </font>"
print "<br><br>"
print "<p align = 'center'> <font size = '5'> Tabulaciones: %s </font>" %(tabulaciones)
print "<br>"
print "<br><br>"
print "<div align='center'>"
print "<table border='1'>"
print "<tr>"
print "<th>Valor   X</th>"
print "<th>Resultado</th>"
for i in range(0,cantx):
    print "<tr>"
    print "<td>%s</td>"%(vectorvalx[i])
    print "<td>%s</td>"%(resultados[i])
    print "</tr>"
print "</table>"
print "<br><br>"
print "<a href = 'IndexLG.html'><input type = 'button' value = 'Regresar' name = 'regresar'/></a>"
print "</div>"
print "</body>"
print "</html>"

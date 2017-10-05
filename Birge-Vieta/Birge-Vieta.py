#!/Python27/python
# -*- coding: utf-8 -*-

import cgi, cgitb

cgitb.enable()

form = cgi.FieldStorage()
grad = form.getvalue('grad')
coe = int(grad)
bandera  = 1
iter = 500
nombre   = "text"

coefOriginal      = []

for i in range(0,int(grad)+1):
    gen = nombre + str(i)
    coefOriginal.append(float(form.getvalue(gen)))

numRaices = len(coefOriginal) - 1
vectorTemporalR = []
vectorFinalX = []
coeficientes = []

for coef in coefOriginal:
    coeficientes.append(float(coef)/float(coefOriginal[0]))

def eliminarRaicesDuplicadas(vector):
    tempVector = list(set(vector))
    limpiarVec(vector)
    for v in tempVector:
        vector.append(v)

def reduccionPol(coefAct, vecTempX, vecTempR, longCoef):
    vecTempResultados = []
    vecTempResultados2 = []
    primerDato = True
    x = 0.1
    if not vecTempX:
        vecTempX.append(x)
    for coef in coefAct:
        if coef == coefAct[0] and primerDato:
            vecTempResultados.append(coef)
            primerDato = False
        else:
            p = (vecTempResultados[-1]*vecTempX[-1])+coef
            if round(p,3) == 0:
                limpiarVec(vecTempR)
                for v in vecTempResultados:
                    vecTempR.append(v)
                return True
            else:
                vecTempResultados.append(p)
    for coef in vecTempResultados:
        if coef == 1:
            vecTempResultados2.append(1)
        else:
            vecTempResultados2.append((vecTempResultados2[-1]*vecTempX[-1])+coef)

    if not len(vecTempResultados2)-1 == 0:
        vecTempResultados2.pop()
    x = float(vecTempX[-1]) -( float(vecTempResultados[-1])/float(vecTempResultados2[-1]))
    vecTempX.append(x)

def redondearVec(vector):
    for i in range(0, len(vector)):
        vector[i] = round(vector[i],3)

def limpiarVec(vector):
    while(vector):
        vector.pop(0)

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
    <title>METODO DE BIRGE-VIETA</title>
</head>"""
print "<body>"

print "<p align = 'center'> <font size = '10'> Método de Birge - Vieta </font>"
print "<br><br>"
print "<p align = 'center'> <font size = '5'> Ecuación: </font>"
print "<br><br>"
for i in range(0,int(grad)+1):
    if coe != 0:
        print "(%d)x<sup>%d</sup> + "%(coefOriginal[i],coe)
    else:
        print " (%d) = 0"%(coefOriginal[i])
        print "<br> <br>"
    coe = coe - 1
print "<p align = 'center'> <font size = '5'>Grado: %s </font>" %(grad)
print "<br><br><br>"

while(True):
    vectorTemporalX = []
    if bandera >= iter:
        break
    while(True):
        bandera = bandera + 1
        if reduccionPol(coeficientes, vectorTemporalX, vectorTemporalR, coeficientes.__len__()-1):
            break
        if bandera >= iter:
            break
    #redondearVec(coeficientes)
    if not bandera >= iter:
        vectorFinalX.append(round(vectorTemporalX[-1],3))
    limpiarVec(coeficientes)
    for v in vectorTemporalR:
        coeficientes.append(v)
    if len(vectorFinalX) == numRaices:
        break
print "<div align='center'>"
if bandera >= iter:
    print "<p> La ecuacion contiene raíces imaginarias<br><br>"
    #vectorFinalX.pop()
eliminarRaicesDuplicadas(vectorFinalX)
print "<table border = '1'>"
print "<tr>"
print "<th colspan='2'>Raíces</th>"
print "</tr>"
for i in range(0,len(vectorFinalX)):
    print "<tr>"
    print "<td align = 'center'>%sx<sub>%s</sub></td>" % ("\t\t",i+1)
    print "<td align = 'center'>%s%s</td>" % ("\t\t",vectorFinalX[i])
    print "</tr>"
print "</table>"
print "<br><br>"
print "<p align = 'center'> <font size = '5'> P<sub>%s</sub>(x) = :"%(grad)
for i in range(0, len(vectorFinalX)):
    print "(x + (%s))"%(vectorFinalX[i]*-1)
for i in range(len(vectorFinalX), int(grad)):
    print "(x + r<sub>%s</sub>)"%(i+1)
print "</font>"
print "<div align = 'center'>"
print "<br><br>"
print "<a href = 'IndexBV.html'><input type = 'button' value = 'Regresar' name = 'regresar'/></a>"
print "</div>"
print "</div>"
print "</body>"
print "</html>"

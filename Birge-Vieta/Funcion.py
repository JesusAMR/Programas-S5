#!/Python27/python
# -*- coding: utf-8 -*-

import cgi, cgitb

cgitb.enable()

form = cgi.FieldStorage()

grad = form.getvalue('grad')
coe = int(grad)
nombre = "text"
tam = float(800/(int(grad)+1))

print "Content-Type: text/html"
print 
print "<html>"
print """<!DOCTYPE html>
<html lang="en">
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
print "<p align = 'center'> <font size = '5'>Grado: %s </font>" %(int(grad))
print "<br><br>"
print "<br><br>"
print "<form action = 'Birge-Vieta.py' name = 'Valores_pol' method = 'post' align = 'center'>"
print "<input type= 'number' id='grad' name='grad' value = '%d' hidden>"%(int(grad))
for i in range(0,int(grad)+1):
	gen = nombre + str(i)
	print "<input type= 'number' id='numero' name='%s' style = 'width : %dpx; heigth : 5px' placeholder='Coeficiente' min = '-10000000' step = '0.001' required>"%(gen, tam)
	if coe != 0:
		print "x<sup>%d</sup> + "%(coe)
	else:
		print " = 0"
		print "<br> <br>"
	coe = coe - 1
print " <input type = 'submit' id = 'BTNmatriz' value ='Enviar informacion.'>"
print "</form>"
print "<br>"
print "<div align = 'center'>"
print "<a href = 'IndexBV.html'><input type = 'button' value = 'Regresar' name = 'regresar'/></a>"
print "</div>"
print "</body>"
print "</html>"

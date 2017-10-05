#!/Python27/python
# -*- coding: utf-8 -*-

import cgi, cgitb

cgitb.enable()


def solicitudX():
	print "<div align='center'>"
	print "<table>"
	print "<tr>"
	print "<th>Valores x a evaluar</th>"
	print "</tr>"
	for i in range(0,valorx):
		genx = nomvalx + str(i+1)
		print "<tr>"
		print "<td><input type= 'number' name='%s' placeholder='Valor evaluar' min = '-10000000' step = '0.001' required></td>"%(genx)
		print "</tr>"
		print "<br><br>"
	print "</div>"
	print "</table>"


def solicitudTabulaciones():
	print "<div align='center'>"
	print "<table>"
	print "<tr>"
	print "<th>X</th>"
	print "<th>Y</th>"
	print "</tr>"
	for i in range(0,tabulaciones):
		genx = nombrex + str(i+1)
		geny = nombrey + str(i+1)
		print "<tr>"
		print "<td><input type= 'number' name='%s' placeholder='%s' min = '-10000000' step = '0.001' required></td>"%(genx, genx)
		print "<td><input type= 'number' name='%s' placeholder='%s' min = '-10000000' step = '0.001' required></td>"%(geny, geny)
		print "</tr>"
		print "<br><br>"
	print "</div>"
	print "</table>"
	print "<input type= 'number' id='grad' name='grad' value = '%d' hidden>"%(tabulaciones)
	print "<input type= 'number' id='valx' name='valx' value = '%s' step= '0.001' hidden>"%(valorx)
	print "<br><br>"
	print "<input type = 'submit' id = 'BTNmatriz' value ='Enviar informacion.'>"
	print "<br><br>"

form = cgi.FieldStorage()

dat = form.getvalue('num')
valorx = int(form.getvalue('val'))
tabulaciones = int(dat)
nomvalx = "valorx"
nombrex = "x"
nombrey = "y"

print "Content-Type: text/html"
print 
print "<html>"
print """<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <script src="validaciones2.js"></script>
    <link rel="stylesheet" href="Estilo.css">
    <title>METODO DE LAGRANGE</title>
</head>"""
print "<body>"
print "<p align = 'center'> <font size = '10'> Método de Lagrange </font>"
print "<br><br>"
print "<p align = 'center'> <font size = '5'>Tabulaciones: %s </font>" %(tabulaciones)
print "<br><br>"
print "<p align = 'center'> <font size = '5'>Cantidad X's: %s </font>" %(valorx)
print "<form action = 'InterpolacionLG.py' name = 'Valores_pol' method = 'post' align = 'center' onsubmit='return validar()'>"
solicitudX()
solicitudTabulaciones()
print "</form>"
print "<div align = 'center'>"
print "<a href = 'IndexLG.html'><input type = 'button' value = 'Regresar' name = 'regresar'/></a>"
print "</div>"
print "</body>"
print "</html>"
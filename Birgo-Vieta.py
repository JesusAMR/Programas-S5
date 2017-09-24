from math import ceil
#coeficientes = [1, -0.5, -8, 7.5]

def reduccionPol(coefAct, vecTempX, vecTempR, longCoef):
	vecTempResultados = []
	vecTempResultados2 = []
	if not vecTempX:
		x = float(-coefAct[longCoef])/float(coefAct[longCoef-1])
		vecTempX.append(x)
	for coef in coefAct:
		if coef == coefAct[0]:
			vecTempResultados.append(coef)
		else:
			p = (vecTempResultados[-1]*vecTempX[-1])+coef
			if round(p,3) == 0:
				for v in vecTempResultados:
					vecTempR.append(v)
				print vecTempR
				return True
			else:
				vecTempResultados.append(p)
	for coef in vecTempResultados:
		if coef == 1:
			vecTempResultados2.append(1)
		else:
			vecTempResultados2.append((vecTempResultados2[-1]*vecTempX[-1])+coef)
	vecTempResultados2.pop()
	x = float(vecTempX[-1]) -( float(vecTempResultados[-1])/float(vecTempResultados2[-1]))
	vecTempX.append(x)

def redondearVec(vector):
	for i in range(0, len(vector)):
		vector[i] = round(vector[i],3)

def limpiarVec(vector):
	while(vector):
		vector.pop(0)

#coefOriginal = [1, -11, 32, -22]
coefOriginal = [2, -1, -16, 15]

numRaices = len(coefOriginal) - 1
vectorTemporalR = []
vectorFinalX = []
coeficientes = []

for coef in coefOriginal:
	coeficientes.append(float(coef)/float(coefOriginal[0]))

while(True):
	vectorTemporalX = []

	while(True):
		if reduccionPol(coeficientes, vectorTemporalX, vectorTemporalR, coeficientes.__len__()-1):
			break
	redondearVec(coeficientes)
	vectorFinalX.append(round(vectorTemporalX[-1],3))
	limpiarVec(coeficientes)
	for v in vectorTemporalR:
		coeficientes.append(v)
	if len(vectorFinalX) == numRaices:
		break
print vectorFinalX


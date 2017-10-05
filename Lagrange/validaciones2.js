function validar() {
	var x = [], y = [], valEvaluar = [];
	var nomx = "x", nomy = "y", nomvalx = "valorx";
	var cantx = document.forms["Valores_pol"].elements["valx"].value;
	var tabulaciones = document.forms["Valores_pol"].elements["grad"].value;

	for (var i = 1; i <= cantx; i++) {
		valEvaluar.push(document.forms["Valores_pol"].elements[nomvalx+i].value);
	}
	for (var i = 1; i <= tabulaciones; i++) {
		x.push(document.forms["Valores_pol"].elements[nomx+i].value);
		y.push(document.forms["Valores_pol"].elements[nomy+i].value);
	}
	x.sort(function(a,b){return a-b;});

	for(var i = 0; i <= valEvaluar.length; i++){
		for(var j = 0; j <= x.length; j++){
			if(parseFloat(valEvaluar[i]) == parseFloat(x[j])){
				alert("Uno de los valores a evaluar es igual a una de las x en la tabulacion.");
				return false;
			}
		}
	}
	for(var i = 0; i < valEvaluar.length; i++){
		if(!(parseFloat(x[0]) <= parseFloat(valEvaluar[i]) && parseFloat(x[x.length-1]) >= parseFloat(valEvaluar[i]))){
			alert("Uno de los valores a evaluar no esta dentro del rango de las tabulaciones");
			return false;
		}
	}
	return true;
}
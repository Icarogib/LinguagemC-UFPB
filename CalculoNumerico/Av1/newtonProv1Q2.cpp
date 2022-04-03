#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

#define PREC 5

float derivada ( float X ){
	float deriv;	
	
	deriv = -20 * ((-0.2 * exp( -0.2 * X )) - (-0.75 * exp ( -0.75 * X))); 
//	cout << "Derivada: " << deriv << endl;
	return deriv;
}

float expressao ( float X ){
	float resul;
	
	resul = X - ((10 - (20 * (exp( -0.2 * X ) - exp( -0.75 * X ) )) -5 )/derivada( X )); // Xn+1 = Xn - f(x)/f'(x);
//	cout << "Expressao: " << resul << endl;
	
	//se utiliza log(x) quando é ln(x);
	return resul;
}

float expreraiz ( float X ){
	float result;
	
	result = (10 - (20 * (exp( -0.2 * X ) - exp( -0.75 * X ) )) -5 );
	
	return result;
}

int main ( ) {
	
	float intervalos[2], erro;
	float Xval1, raiz, raizant, inter;
	
	cout << "Digite o  intervalo: ";
	cin >> intervalos[0];
//	cout << "\nDigite o segundo intervalo: ";
//	cin >> intervalos[1];
	
	raiz = intervalos[0];
	
	cout << "\nDigite o erro: ";
	cin >> erro;
	
	cout << "\nDigite quantidade maxima de interacoes: ";
	cin >> inter;
	
	cout << setprecision(PREC) << fixed;

//	cout << "Primeiro: " << intervalos[0] << endl << "Segundo: " << intervalos[1] << endl;
//	cout << "\nDigite o valor do X: ";
//	cin >> Xval;
	
	cout << "\nInt\t  A\t\t   Xn\t          Parada\t" << endl;
	
	int i = 0;
	
	while( raiz > erro || raiz < 0){
		
		if ( i == inter ){
			cout << "Numero maximo de interacoes alcancado, falha!" << endl;
			break;
		}

		Xval1 = expressao ( intervalos[0] );
		raiz = expreraiz (Xval1);
		
		cout << i << "\t  " << intervalos[0] << " \t " << Xval1 << " \t " << raiz << endl;
		
		intervalos[0] = raizant = Xval1;
		
		i++;
	}
	
	return 0;
}

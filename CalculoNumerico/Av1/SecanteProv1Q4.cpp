#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

#define PREC 5

float expressao ( float X ){
	float resul;
	
	resul = ( 2200 * log(160000 / (160000 - (2680 * X )))) -( 9.8 * X) - 1000 ;
	
	return resul;
}

float funcao ( float X1, float X2){
	float XIS, f1, f2;
	
//	cout << "X1 e X2: " << X1 << "/" << X2 << endl;
	
	f1 = expressao ( X1 );
	f2 = expressao ( X2 );
//	cout << "F1 e F2: " << f1 << "/" << f2 << endl;
	
	//XIS = X2 - (((X2 - X1) * expressao(X2))/(expressao(X2) - expressao(X1)));
	XIS = (X1 * f2 - X2 * f1)/(f2 - f1);
//	cout << "XIS: " << XIS << endl;
	return XIS;
}

float modulo (float val ){
	float mod;
	
	if( val < 0 )
		mod = val * (-1);
	
	return mod;
}

int main ( ) {
	float intervalos[2], erro, med1;
	float Xval1, Xval2, raiz, inter;
	
	cout << "Digite o primeiro intervalo: ";
	cin >> intervalos[0];
	cout << "\nDigite o segundo intervalo: ";
	cin >> intervalos[1];
	
	raiz = intervalos[1];
	
	cout << "\nDigite o erro: ";
	cin >> erro;
	
	cout << "\nDigite quantidade maxima de interacoes: ";
	cin >> inter;
	
	cout << setprecision(PREC) << fixed;

//	cout << "Primeiro: " << intervalos[0] << endl << "Segundo: " << intervalos[1] << endl;
//	cout << "\nDigite o valor do X: ";
//	cin >> Xval;
	
	cout << "\nInt\t  A\t\t B\t   F(a)\t  \t F(b)\t        F(k+1)\t         Parada\t" << endl;
	
	int i = 0;
	
	while( raiz > erro || raiz < 0){
		
		if( intervalos[0] == intervalos[1] )
			break;
		if ( i == inter ){
			cout << "Numero maximo de interacoes alcancado, falha!" << endl;
			break;
		}		
		
		//calculos
		Xval1 = expressao( intervalos[0] ); //f(x1)
		Xval2 = expressao( intervalos[1] ); //f(x2)
		
		raiz = funcao ( intervalos[0], intervalos[1] ); //funcao secante
		med1 = modulo (expressao ( raiz )); //teste de parada (modulo funcao)
		//=============================
		
		//print
		cout << i << "\t  " << intervalos[0] << "  \t" << intervalos[1] << "    " <<
		Xval1 << " \t" << Xval2 << " \t" << raiz << " \t " << med1 << endl;
	

			
		intervalos[1] = intervalos[0]; //x(k+1) = x(k)
		intervalos[0] = raiz; //x(k) = valor da funcao secante.

		if( med1 < erro )
			break;
	
		i++;
	}
	
	return 0;
}

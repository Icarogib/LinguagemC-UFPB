#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

#define PREC 5

float expressao ( float X ){
	float resul;
	float logval;
	
//	logval = log10(X); //utiliza quando é log na base 10 (x)
//	cout << "\nlog: " << logval;
	
	resul = ((pow(X, 3)) - (9*X )) + 3;
	//se utiliza log(x) quando é ln(x);
	return resul;
}

float media ( float X, float Y, float fX, float fY ){
	float med = 0;
	
	if(fX < 0 )
		fX = fX * (-1);
	if(fY < 0 )
		fY = fY * (-1);
	
//	cout << "FX: " << fX;
//	cout << "FY: " << fY;
	med = (( X * fY ) + (Y * fX))/(fX + fY);
//	cout << "\nmedia: " << med << endl;
//	med = expressao ( med );
	
	
	
	return med;
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
	
	cout << "\nInt\t  A\t\t B\t   F(a)\t  \t F(b)\t        Media\t         F(k+1)\t" << endl;
	
	int i = 0;
	
	while( raiz > erro || raiz < 0){
		
		if( intervalos[0] == intervalos[1] )
			break;
		if ( i == inter ){
			cout << "Numero maximo de interacoes alcancado, falha!" << endl;
			break;
		}
			
		//cout << "\nInteracao: " << i << endl;
		

		Xval1 = expressao( intervalos[0] );
		Xval2 = expressao( intervalos[1] );
		
		//cout << "\nValor A: " << intervalos[0] << endl;
		//cout << "\nValor B: " << intervalos[1] << endl;
		
		//cout << "\nResultado F(a): " << Xval1 << endl;
		//cout << "\nResultado F(b): " << Xval2 << endl;
	
		med1 = media ( intervalos[0], intervalos[1], Xval1, Xval2 );
		raiz = expressao ( med1 );

		//cout << "\nResultado F(k+1): " << raiz << endl;

		cout << i << "\t  " << intervalos[0] << "  \t" << intervalos[1] << "    " <<
		Xval1 << " \t" << Xval2 << " \t" << med1 << " \t " << raiz << endl;
		
		if( raiz > 0 )
			intervalos[0] = med1;
		else	
			intervalos[1] = med1;
		
		i++;
	}
	
	return 0;
}

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

#define PREC 5

//sem implementacao de teste de parada, mas facil implementar

float expressao ( float X ){
	float resul;
	float logval;
	
//	logval = log10(X);
//	cout << "\nlog: " << logval;
	
	resul = (pow(X, 2)) + log(X);
	
	return resul;
}

float media ( float X, float Y ){
	float med = 0;
	
	med = ( X + Y )/2;
//	cout << "\nmedia: " << med << endl;
	med = expressao ( med );
	
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
		
		raiz = media ( intervalos[0], intervalos[1] );
		med1 = (intervalos[0] + intervalos[1])/2;

		cout << i << "\t  " << intervalos[0] << "  \t" << intervalos[1] << "    " <<
		Xval1 << " \t" << Xval2 << " \t" << med1 << " \t " << raiz << endl;
		
		if( raiz < 0 )
			intervalos[0] = (intervalos[0] + intervalos[1])/2;
		else	
			intervalos[1] = (intervalos[0] + intervalos[1])/2;
		
		i++;
	}
	
	return 0;
}

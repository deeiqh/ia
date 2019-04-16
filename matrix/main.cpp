#include<cstdio>
#include"matrix.cpp"

int main()
{
	int filas = 4;
	int columnas = 5;
	
	Matrix<int, float> *matriz2 = new Matrix<int, float> (filas,columnas);
	matriz2->ones();
	matriz2->print_float(',');	
	printf("%s\n", "");
	matriz2 = matriz2->wise_operation(division, matriz2);//al pasar por valor, hace una copia, pero no inicializa
	matriz2->print_float(',');	
	printf("%s\n", "");

	matriz2->wise_operation(power, 4);
	matriz2->print_float(',');

	Matrix<int, float> *matriz3 = new Matrix<int, float> (columnas,1);
	matriz3->ones();
	Matrix<int, float> *matriz_aux = matriz2; 
	matriz2 = matriz2->product(matriz3);
	delete matriz_aux;
	matriz2->print_float(',');	
	printf("%s\n", "");



	return 0;
}


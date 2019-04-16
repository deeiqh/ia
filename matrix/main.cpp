#include<cstdio>
#include"matrix.cpp"

int main()
{
	int filas = 4;
	int columnas = 5;
	Matrix<int, float> matriz(filas, columnas);
	matriz.ones();
	matriz.set(2,3,7) ;
	matriz.print_float(',');
	printf("%s\n","matriz original, arriba" );
	Matrix<int, float> *matriz2;
	matriz2 = matriz.wise_operation(addition, matriz);//al pasar por valor, hace una copia, pero no inicializa
	matriz2->print_float(',');

	return 0;
}


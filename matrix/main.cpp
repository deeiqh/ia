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
	Matrix<int, float> matriz_2(filas, columnas);
	matriz_2.ones();
	matriz.wise_operation(matriz.addition(), matriz_2);
	matriz.print_float(',');
	return 0;
	/*
	int filas = 4;
	int columnas = 5;
	Matrix<int, float> matriz(filas, columnas);
	matriz.ones();
	matriz.set(2,3,7) ;
	matriz.print_float(',');
	printf("%s\n","" );
	Matrix<int, float> C(filas,columnas);
	C = matriz.wise_operation(matriz.addition(), matriz);
	C.print_float(',');
	return 0;
	*/
}


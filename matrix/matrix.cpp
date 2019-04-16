#ifndef MATRIX_CPP
#define MATRIX_CPP

#include"matrix.h"
#include<cstdio>

template<class Index, class Data>
Matrix<Index, Data>::Matrix(Index rows, Index columns):rows(rows), columns(columns){
  array = new Data[rows*columns];
  //printf("%s\n","inicializado!" );
}

template<class Index, class Data>
Matrix<Index, Data>::~Matrix(){
  //printf("%s\n","destruido!!" ); 
  delete[] array;
}

template<class Index, class Data>
Index Matrix<Index, Data>::num_columns(){
  return columns;
}

template<class Index, class Data>
void Matrix<Index, Data>::set(Index row, Index column, Data d){
  array[row*columns+column] = d;
}

template<class Index, class Data>
Data Matrix<Index, Data>::get(Index row, Index column){
  return array[row*columns+column];
}

template<class Index, class Data>
void Matrix<Index, Data>::print_float(char separator){
  for (int r=0; r<rows; r++){
    for(int c=0; c<columns; c++){
      printf("%f%c",get(r,c), separator);
    }
    printf("\n");
  }
}

template<class Index, class Data>
void Matrix<Index, Data>::print_int(char separator){
  for (int r=0; r<rows; r++){
    for(int c=0; c<columns; c++){
      printf("%d%c",get(r,c), separator);
    }
    printf("\n");
  }
}

template<class Index, class Data>
void Matrix<Index, Data>::print_char(char separator){
  for (int r=0; r<rows; r++){
    for(int c=0; c<columns; c++){
      printf("%c%c",get(r,c), separator);
    }
    printf("\n");
  }
}

template<class Index, class Data>
void Matrix<Index,Data>::zeros(){
  for(int i=0; i<rows*columns; i++){
    array[i] = 0;
  }
}

template<class Index, class Data>
void Matrix<Index, Data>::ones(){
  for(int i=0; i<rows*columns; i++){
    array[i] = 1;
  }
}

template<class Index, class Data>
Matrix<Index,Data> *Matrix<Index, Data>::product(Matrix<Index, Data> *B){
  Matrix<Index,Data> *C = new Matrix<Index, Data> (rows, B->num_columns());
  Data sum;
  for(Index f=0; f<rows; f++){
    for(Index k=0; k<B->num_columns();k++){
      sum=0;
      for(Index c=0;c<columns;c++){
        sum += get(f,c) * B->get(c,k);
      }
      C->set(f,k,sum);
    }
  }
  return C;
}

template<class Index, class Data>
Matrix<Index,Data> *Matrix<Index, Data>::wise_operation(Data (*op)(Data, Data), Matrix<Index, Data> *B){//al pasar por valor no inicializa (pero sí destruye) pero dentro hay un puntero al array verdadero y al destruirse le hace free, de tal forma que hay cualquier cosa en ese array, y así se toma el original(matriz). para evitar eso se hace paso por referencia, para que no destruya el puntero "array" que es el original
  Matrix<Index,Data> *C = new Matrix<Index, Data> (rows, columns) ;
  for (int r=0; r<rows; r++){
    for(int c=0; c<columns; c++){
      C->set(r, c, op( get(r,c), B->get(r,c) ) );
    }
  }
  //C.print_float();
  //printf("%s\n","arriba" );
  return C; //al retornar C, esta C se destruye y se pasa una copia sin inicializar. en este caso el objeto copia que se entrega tendra el puntero a "array" ya perdido, apuntando a cualquier cosa, entonces el objeto copia retornado apunta a cualquier cosa. Entonces para no destruir lo creado se pasa por referencia
}

template<class Index, class Data>
void Matrix<Index, Data>::wise_operation(Data (*op)(Data, Data), Data d){
  for(int i=0; i<rows*columns; i++){
    array[i] = op(array[i], d);
  }
}

#endif
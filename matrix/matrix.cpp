#ifndef MATRIX_CPP
#define MATRIX_CPP

#include"matrix.h"
#include<cstdio>

template<class Index, class Data>
Matrix<Index, Data>::Matrix(Index rows, Index columns):rows(rows), columns(columns){
  array = new Data[rows*columns];
}

template<class Index, class Data>
Matrix<Index, Data>::~Matrix(){ delete[] array;}

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
Matrix<Index,Data> Matrix<Index, Data>::product(Matrix<Index, Data> B){
  return B;
}

template<class Index, class Data>
Matrix<Index,Data> Matrix<Index, Data>::wise_operation(Data (*op)(Data, Data), Matrix<Index, Data> B){
  Matrix<Index,Data> C(rows, columns);
  for (int r=0; r<rows; r++){
    for(int c=0; c<columns; c++){
      C.set(r, c, op( get(r,c), B.get(r,c) ) );
    }
  }
  C.print_float();
  printf("%s\n","arriba" );
  return C;
}

template<class Index, class Data>
template<class Function>
void Matrix<Index, Data>::wise_operation(Function op, Data d){
  for(int i=0; i<rows*columns; i++){
    array[i] = op(array[i], d);
  }
}

#endif
#ifndef MATRIX_H
#define MATRIX_H

#include"operations.hpp"

template<class Index, class Data>
class Matrix{
	private:
		Index rows, columns;
		Data *array;
	public:
		Matrix(Index rows, Index columns);
    ~Matrix();
    Index num_columns();
    void set(Index row, Index column, Data d);
    Data get(Index row, Index column) ;
    void print_float(char separator=',');
    void print_int(char separator=',');
    void print_char(char separator=',');
    void zeros();
    void ones();
    Matrix<Index,Data> *product(Matrix<Index, Data> *B);
    Matrix<Index,Data> *wise_operation(Data (*op)(Data, Data), Matrix<Index, Data> *B);
    void wise_operation(Data (*op)(Data, Data), Data d);

};

#endif
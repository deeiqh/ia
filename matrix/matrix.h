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
    void set(Index row, Index column, Data d);
    Data get(Index row, Index column);
    void print_float(char separator=',');
    void print_int(char separator=',');
    void print_char(char separator=',');
    void zeros();
    void ones();
    Matrix<Index,Data> product(Matrix<Index, Data> B);
    ///////////////////////////////////////////////////////////////////////
    addition_class<Data> addition();
    subtraction_class<Data> subtraction();
    product_class<Data> product();
    division_class<Data> division();
    pow_class<Data> pow();
    ///////////////////////////////////////////////////////////////////////
    template<class Function>
    Matrix<Index,Data> wise_operation(Function op, const Matrix<Index, Data> B);
    template<class Function>
    void wise_operation(Function op, Data d);

};

#endif

#ifndef OPERATIONS_HPP
#define OPERATIONS_HPP

#include<cmath>

template<class Data>
Data addition(Data a, Data b){
      return a+b;   
}

template<class Data>
Data subtraction(Data a, Data b){
      return a-b;   
}

template<class Data>
Data product(Data a, Data b){
      return a*b;   
}

template<class Data>
Data division(Data a, Data b){
      return a/b;   
}

template<class Data>
Data power(Data a, Data b){
      return pow(a,b);   
}

#endif
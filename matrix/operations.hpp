
#ifndef OPERATIONS_HPP
#define OPERATIONS_HPP

#include<cmath>

template<class Data>
Data addition(Data a, Data b){
      return a+b;   
}

template<class Data>
class subtraction_class{
  public:
    Data operator()(Data a, Data b){
      return a-b;
    }
};

template<class Data>
class product_class{
  public:
    Data operator()(Data a, Data b){
      return a*b;
    }
};

template<class Data>
class division_class{
  public:
    Data operator()(Data a, Data b){
      return a/b;
    }
};

template<class Data>
class pow_class{
  public:
    Data operator()(Data a, Data b){
      return pow(a,b);
    }
};

#endif
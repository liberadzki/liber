#include <Rcpp.h>
using namespace Rcpp;

//' @title simplify2array1
//' @description Function simplify2array1 mimic the behaviour of simplify2array R function
//' if the dimensions of input numeric vectors from list are equal function transforms vectors into
//' one numeric matrix. Otherwise function throws an error. 
//'
//' @param x - list of numeric vector
//' @return out - numeric matrix 
//' 
//' @export
// [[Rcpp::export]]

NumericMatrix simplify2array1(List x) {
int n=x.size();
NumericVector y=x(0);
int k=y.size();

for (int i=0; i<n; ++i){
NumericVector p=x(i);
  if (k!=p.size())
    stop("cannot simplify");
}
NumericMatrix out(k,n);
  for (int i=0; i<n; ++i){
NumericVector p=x(i);
    for (int j=0; j<k; ++j)
        out(j,i)=p(j);
}
return out;
}

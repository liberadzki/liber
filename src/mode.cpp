#include <Rcpp.h>
using namespace Rcpp;

//' @title mode
//' @description function mode determine the most frequently occurring value in an integer
//' vector 
//'
//' @param  x - integer vector 
//' @return the most frequently occurring value
//'
//' @export
// [[Rcpp::export]]

int mode(IntegerVector x) {
int n=unique(x).size();
NumericVector y(n);
for (int i=0; i<n; ++i)
y[i]=std::count(x.begin(),x.end(),unique(x)[i]);
int m=max(y);
int q=std::distance(y.begin(),std::find(y.begin(),y.end(),m));
return unique(x)[q];
}

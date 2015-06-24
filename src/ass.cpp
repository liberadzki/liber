#include <Rcpp.h>
using namespace Rcpp;

//' @title ass
//' @description function ass()  for some given integer n generates all possible 0-1 assignment
//' vectors of 2n survey participants in such a way that exactly n of them are assigned to group 0 (control)
//' and the other n ones are assigned to group 1 (treatment) 
//'
//' @param n - integer parameter
//' @return p -  matrix with 2n columns and an appropriate number of rows
//'
//' @export
// [[Rcpp::export]]

NumericMatrix ass(int n) {
int z=1;
for (int i=1; i<n+1; ++i)
 z=z*i;
int q=1;
for (int i=1; i<2*n+1; ++i)
 q=q*i;
int d=q/(z*z);
int l=2*n;
NumericVector w(l);
for (int k=n; k<l; ++k)
w(k)=1;   
NumericMatrix p(d,l);
 for (int i=0; i<d; ++i){
std::next_permutation(w.begin(), w.end()); 
    for (int j=0; j<l; ++j)
      p(i,j)=w(j);
}
return p;
}

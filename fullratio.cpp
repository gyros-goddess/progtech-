#include <iostream>  
#ifndef CONTEST   
#include "fullratio.hpp"  
#endif  
  
using namespace std;   
std::ostream& operator << (std::ostream &out, const rational &x) {  
  out << x.nom << "/"<<x.den;   
  return out;   
}  
  
int rational::gcd(int a, int b) {     
      
  if(a<0) a=(-1)*a;        
  if(b<0) b=(-1)*b;        
              
  while(a>0 && b>0) {        
    if(a>b) a=a%b;        
    else b=b%a;        
  }        
  return a+b;        
}      
      
  
rational::rational (int n, int d) {        
  int mkd=gcd(n, d);        
  nom=n/mkd;        
  den=d/mkd;        
  if(den<0){        
    nom=(-1*nom);        
    den=(-1*den);        
  }        
}    
  
  rational operator + (const rational &x, const rational &y) {  
    int a= (x.nom*y.den) + (x.den*y.nom);      
  int b= (x.den *y.den);      
        
  int c=rational::gcd(a,b);    
  return ( rational(a/c, b/c) );     
  }  
 rational operator - (const rational &x, const rational &y) {  
   int a= (x.nom*y.den) - (x.den*y.nom);     
  int b= (x.den *y.den);      
      
  int c=rational::gcd(a,b);    
      
  return ( rational(a/c, b/c) );   
 }  
  
 rational operator * (const rational &x, const rational &y){  
   int a= ( x.nom * y.nom);     
  int b= (x.den * y.den);       
    
  int c=rational::gcd(a,b);                 
      
  return ( rational (a/c, b/c) );  
 }  
 rational operator / (const rational &x, const rational &y) {  
   int a= (x.nom * y.den);     
  int b= (x.den * y.nom);     
    
  int c=rational::gcd(a,b);     
      
  return ( rational(a/c, b/c) );   
 } 

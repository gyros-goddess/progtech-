#include <iostream>  
#ifndef CONTEST  
#include "babyratio.hpp"  
 #endif  
  
 using namespace std;  
  
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
 rational rational::add (rational r) {   
  int a= (nom*r.den) + (den*r.nom);    
  int b= (den *r.den);    
      
  int c=rational::gcd(a,b);  
  return ( rational(a/c, b/c) );      
                                     }  
  
rational rational::sub(rational r){   
int a= (nom*r.den) - (den*r.nom);   
  int b= (den *r.den);    
    
  int c=rational::gcd(a,b);  
    
  return ( rational(a/c, b/c) );    
  }  
  
rational rational:: mul(rational r) {  
  int a= ( nom * r.nom);   
  int b= (den * r.den);     
  
  int c=rational::gcd(a,b);               
    
  return ( rational (a/c, b/c) );    
}  
  
rational rational:: div(rational r) {  
  int a= (nom * r.den);   
  int b= (den * r.nom);   
  
  int c=rational::gcd(a,b);   
    
  return ( rational(a/c, b/c) );  
}  
void rational:: print (){  
  
  if ((nom < 0 && den > 0) || (nom > 0 && den < 0 )){  
    cout << "-" ;   
  }  
      
  
 cout << abs(nom) << "/" <<  abs(den);  
 }

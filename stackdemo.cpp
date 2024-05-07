  
  
 template <typename T>  
 class stack{  
 public:  
  stack(int size) {  
    SIZE = size;   
    arr = new T [SIZE];   
    last = 0;   
 }  
 stack (const stack &s) {   
 SIZE= s.SIZE;   
   arr = new T [SIZE];   
   last = s.last;   
   for ( int i = 0; i < last; i++){  
     arr[i] = s.arr[i];  
   }  
 }  
 ~stack () // destructor - delete arr !!   
{  
 delete [] arr;   
}  
 const stack & operator = (const stack &s) { // ftiaxnw ena idio const gt to t uparxei idi ai exei dikatou oragtamat also diagrafw to array  
 SIZE =s.SIZE;   
last = s.last;   
   delete [] arr;   
   arr=new T[SIZE];  
    for ( int i = 0; i < last; i++){  
     arr[i] = s.arr[i];  
    }  
   return *this; // anaferrte sto ant ths sin ex t  
 }  
  
  
 friend ostream & operator << (ostream &out, const stack &s) {   
   cout << "[" ;   
 for ( int i = 0; i < s.last; i++) {  
   if ( i != (s.last-1) )  
   cout << s.arr[i] << ", ";  
   else cout << s.arr[i];  
  }  
     
   cout << "]";   
 return out; }  
  
  
bool empty () { return last == 0; }  
void push (const T &x) { arr[last++] = x;  //parametros stack   
}  
T pop () {  
          return arr[--last];  }   
int size (){ // metraei posa element sexw sto stack   
  return last;   
}  
  
private:  
T* arr;  
int last; // deixnei pou vriskomai   
int SIZE;   
};  
  
#ifndef CONTEST  
int main () {  
// let’s play with integers...  
stack<int> s(10);  
cout << "s is empty:" << s << endl;  
s.push(42);  
 cout << "s has one element: " << s << endl;  
 s.push(17);  
 s.push(34);  
 cout << "s has more elements: " << s << endl;  
 cout << "How many? " << s.size() << endl;  
  stack<int> t(5);  
 t.push(7);  
 cout << "t: " << t << endl;  
 t = s;  
cout << "popping from s: " << s.pop() << endl;  
 s.push(8);  
stack<int> a(s);  
t.push(99);  
 a.push(77);  
 cout << "s: "<< s << endl;  
 cout << "t:"  << t << endl;  
 cout << "a:"  << a << endl;  
 // now with doubles...  
 stack<double> c(4);  
 c.push(3.14);  
 c.push(1.414);  
 cout << "c contains doubles " << c << endl;  
 // and with characters...  
stack<char> k(4);  
 k.push('$');  
cout << "k contains a character " << k << endl;  
}  
#endif 

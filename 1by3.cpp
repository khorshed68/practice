#include <iostream>
#include <cmath>
using namespace std;
double f(double x){
return 1.0/(1+x*x);
}
int main(){

double a,b,h;
int n;
cout <<"enter the lower limit (a)";
cin>>a;
cout <<"enter the upper limit (b)";
cin>>b;
cout <<"enter steps (h)";
cin>>h;
n=(b-a)/h;
if (n%2!=0){
    cout<<"error"<<endl;
    return 0;
}
double sum =f(a)+f(b);
for (int i=1;i<n;i++){
    double x=a+i*h;
    if (i%2==0)
        sum+=2*f(x);
    else
        sum+=4*f(x);
}
double result=(h/3.0)*sum;
cout<<"integral="<<result<<endl;
return 0;
}

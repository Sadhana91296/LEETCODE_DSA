#include<iostream>
using namespace std;
int main()
{
    int num1=11;
    int num2;
    num2=num1;
    cout<<"num1 :"<<num1<<endl;
    cout<<"num2 :"<<num2<<endl;
    num1=22;
    cout<<"num1 :"<<num1<<endl;
    cout<<"num2 :"<<num2<<endl; 
    //even changing num1 valus it wont change num2 becuase value is not coming from any reference(address)
    //so in reality it only updated variable value, now we use pointer in pointer2.cpp
return 0;
}
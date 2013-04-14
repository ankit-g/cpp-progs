/*
@author vipin kumar
*/
#include<iostream>

using namespace std;

class A
{

public :

A(int i)
{
cout<<"A called :"<<i<<"\n";
}

};

class B:public A
{

public :

B(double d,int k):A(k)
{

cout<<"B called:"<<d<<"\n";
}
};

class C:public B
{

public:

C(char c,double d,int k):B(d,k)
{

cout<<"C called:"<<c<<"\n";
}

};


int main()
{

C c('v',3.7,5);
}


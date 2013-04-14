/*
@author vipin kumar
*/

//by default without defining any access specifier inheritance is private
#include<iostream>

using namespace std;
class Base
{

private:
int m_private;

public :

int m_public;

protected :

int m_protected;

};

class Derived : public Base
{

//public inheritace means
/*
public remains public 
private remains private
protected remains protected
*/

public :

Derived()
{
m_public=1;/*you cannot access private member of base class*/
m_protected=2;
}

};

int main()
{
Derived d;

cout<<d.m_public<<"\n";
/*
you cannot call protected member and private member of base class outside
*/
}




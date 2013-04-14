/*
@author vipin kumar
*/

/*when you are calling constructor of derived class the base constructor is called first*/
/*if you are not defining any constructor then default construcor is created by compiler */
/*the value of a variable can only be set in an initialization list of a constructor belonging to the same class as the variable.*/

#include<iostream>

using namespace std;

class Base
{

public:

int m_base;

Base(int h):m_base(h)
{

}
};

class Derived :public Base

{

public :
double m_derived;

/*base class constructor is called in initialization list */
Derived(double l=0.0,int h=0): Base(h), m_derived(l)
{

}

};

int main()
{

Derived d(3.0,5);

cout<<d.m_derived<<"\n";

cout<<d.m_base<<"\n";
}



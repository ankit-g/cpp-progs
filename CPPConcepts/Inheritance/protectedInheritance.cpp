/*
@author vipin kumar
*/

#include<iostream>
/*
protected inheritance is used least 
*/

class Base

{
public :

int m_public;

private:

int m_private;

protected:

int m_protected;

};

class Derived :protected Base

{

//protected inheritance means

/*
public become protected
protected become protected
private stays private
*/

public :
Derived()
{
m_public=1;//you cannot access private variable from base class
m_protected=2;
}

};

int main()
{

Derived d;
//you can call anything as public also become protected and cant be called outside class
}






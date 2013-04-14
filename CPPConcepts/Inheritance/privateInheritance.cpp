/*
@author vipin kumar
*/
#include<iostream>

using namespace std;

class Base
{

public :
int m_public;

private :

int m_private;

protected:

int m_protected;

};

class Derived :private Base

{

//private inheritance means

/*
public become private
private remains private
protected become private
*/


public :

Derived()
{

m_public =1;/*you cannot access private member*/
m_protected=2;
}

};

int main()
{

Derived d;
//you cannot access anything because everything become private now


}


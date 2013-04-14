/*this is implementation of deep copy in c++ where we are copying an object with all its attribute in a different place*/


#include<string.h>
#include<iostream>
#include<stdio.h>

using namespace std;


struct X
{
private :
int len;
char * ptr;

public:

int getLen()
{
return len;
}

char * getPtr()
{
return ptr;
}

X& set(char *);

X& cat(char *);

X& copy(X&);
void print();
};


X& X::set(char * pc)
{
len=strlen(pc);
ptr=new char[len];
strcpy(ptr,pc);
return *this;
}

X& X::cat(char *pc)
{
len+=strlen(pc);
strcat(ptr,pc);
return *this;
}

X& X::copy(X& x)
{
set(x.getPtr());
return *this;
}

void X::print()
{
cout<<ptr<<endl;

}


int main()
{
X obj1;
obj1.set("ABCD").cat("EFGH");
obj1.print();
cout<<obj1.getLen();
cout<<"\n";
printf("%p",(obj1.getPtr()));
X obj2;
obj2.copy(obj1);

cout<<"\n";
obj2.print();
cout<<obj2.getLen();
cout<<"\n";
printf("%p",(obj2.getPtr()));
return 0;
}





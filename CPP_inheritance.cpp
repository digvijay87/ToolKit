/*
Inheritance: 
Inheritance is a way of creating an object that inherits any class's existing functionalities and adds additional functionality. 
 
If a class is privately derived from a base class, the member functions of the base class cannot be accessed by the derived class in a straightforward fashion. However, the member function of the base class can be accessed by a new member function of the derived class. 
*/
#include <iostream>  
using namespace std;  

class A{
    public:
        int a;
        int b;
        void set(int n, int m)
        {
            a = n;
            b = m;
            return ;
        }
        int get()
        {
            return a;
        }
        
        int sum()
        {
            return a + b;
        }
};

class derivedA : public A{
    public:
        void display()
        {
            cout << a << endl;
        }
};


class derivedB : private A{
    public:
        void setP(int a, int b)
        {
            set(a,b);
        }
        void display()
        {
            cout << sum() << endl;
        }
};

int main()  
{ 
    //nm number;
    //number = one;
    //cout << "mn.one " << number+4 << endl;
    
    A objA;
    objA.set(5,10);
    cout << objA.get() << endl;
    derivedA drvA;
    
    drvA.set(10, 20);
    cout << drvA.get() << endl;
    drvA.display();
    
    
    derivedB drvB;
    drvB.setP(20,30);
    drvB.display();
    return 0;
}  

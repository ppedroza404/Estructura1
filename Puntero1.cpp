// Your First C++ Program

#include <iostream>

using namespace std;

int main() {

    float a=2.0,*b,*c;

    b=&a;
    c=new float;
    *c=*b;
    a=*c+1.5;
    cout << *b << "//" << *c;

    return 0;
}
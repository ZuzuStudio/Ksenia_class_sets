#include <iostream>
#include "sets.h"

using namespace std;


int main(){
    Set a,b,c;

    cout<<"Enter the number of elements and the first set"<<endl;
    cin>>a;
    cout<<endl;

    cout<<"Enter the number of elements and the second set"<<endl;
    cin>>b;
    cout<<endl;

    c = a+b;
    cout<<"Union sets"<<endl;
    cout<<c;
    cout<<endl;

    c=a*b;
    cout<<"Intersection sets"<<endl;
    cout<<c;
    cout<<endl;

    c=a-b;
    cout<<"Difference sets(1-2)"<<endl;
    cout<<c;
    cout<<endl;

    c=b-a;
    cout<<"Difference sets(2-1)"<<endl;
    cout<<c;
    cout<<endl;

    return 0;
}

#include<iostream>
#include<string>

using namespace std;

template <class t>
void display(t x){
    cout<<"template display : "<<x<<endl;
}

void display(int x){
    cout<<"Ecplicit display: "<< x<<endl;
}

int main(){
    display(100);
    display(234.65);
    display('c');

    return 0;
}
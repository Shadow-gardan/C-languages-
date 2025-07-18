#include<iostream>
#include<string>

using namespace std;

void divide(int x, int y, int z){

    cout<<"We are inside the function"<<endl;
    if((x-y) != 0){
        int r = z/(x-y);
        cout<<"Result = " <<r<<endl;
    }
    else{
        throw(x-y);
    }
}

int main(){

    try{
        cout<<"We are inside the try block"<<endl;
        divide(10,20,30);
        divide(20,10,30);
    }

    catch(int i){
        cout<<"Caught the exception"<<endl;
    }

    return 0;
}

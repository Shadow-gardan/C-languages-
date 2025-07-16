#include <iostream>
#include <fstream>
using namespace std;

int main() {

    ofstream outf("Item");
    cout<<"Enter the item name: ";
    string item;
    cin>>item;
    outf<<item<<endl;
    
    cout<<"Enter the item price: ";
    double price;
    cin>>price;
    outf<<price<<endl;
    outf.close();

    ifstream inf("Item");
    inf>>item;
    inf>>price;

    cout<<"\n";

    cout<<"Item Name: "<<item<<endl;
    cout<<"Item Price: "<<price<<endl;

    inf.close();

    return 0;
}
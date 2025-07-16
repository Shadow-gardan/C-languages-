#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

class inventrory{
    char name[20];
    int code;
    float cost;

public:
    void getdata(void) {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter code: ";
        cin >> code;
        cout << "Enter cost: ";
        cin >> cost;
    }

    void putdata(void) {
        cout << setw(10)<< name << endl;
        cout << setw(10) << code << endl;
        cout << setprecision(2)<<setw(10) << cost << endl;
    }

};

int main() {

    inventrory item;
    fstream inoutfile;
    inoutfile.open("stock.dat",ios::ate | ios::in | ios::out | ios::binary);
    inoutfile.seekg(0, ios::beg);

    cout<<"current contents of stock: " << endl;

    while(inoutfile.read((char*)&item, sizeof(item))) {
        item.putdata();
    }

    inoutfile.clear(); // Clear EOF flag

    cout<<"Add an item"<< endl;
    item.getdata();
    char ch;
    cin.get(ch); // To consume the newline character left by previous input
    inoutfile.write((char*)&item, sizeof(item));
    
    inoutfile.seekg(0);

    cout<<"Contents of appended file" << endl;

    while(inoutfile.read((char*)&item, sizeof(item))) {
        item.putdata();
    }

    int last = inoutfile.tellg();
    int n = last / sizeof(item);

    cout<<"number of object"<<endl;
    cout<<"Total bytes int the file: " << last << endl;
    cout<<"Number of objects in the file: " << endl;
    int object;
    cin >> object;
    cin.get(ch); // To consume the newline character left by previous input

    int location = object * sizeof(item);
    if(inoutfile.eof()){
        inoutfile.clear(); // Clear EOF flag
    }

    inoutfile.seekg(location);

    cout<<"Enter new values of the object: " << endl;
    item.getdata();
    cin.get(ch); // To consume the newline character left by previous input
    inoutfile.write((char*)&item, sizeof(item))<<flush;

    inoutfile.seekg(0);
    cout<<"Contents of updated file" << endl;

    while(inoutfile.read((char*)&item, sizeof(item))) {
        item.putdata();
    }

    inoutfile.close();

    

    return 0;
}

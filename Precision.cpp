# include <iostream>
# include <cmath>

using namespace std;

int main() {

    cout<<"Precision set to 3 digits"<<endl;
    cout.precision(3);
    cout.width(10);
    cout<<"Value";
    cout<<"sqrt of value"<<endl;

    for (int i = 1; i <= 10; i++) {
        cout.width(10);
        cout<< endl;
        cout.width(13);
        cout << sqrt(i) << endl;
    }

    cout<<"Precision set to 5 digits"<<endl;
    cout.precision(5);
    cout.precision(5);
    cout<<"sqrt(10) = "<<sqrt(10)<<endl;

    cout.precision(0);
    cout<<"sqrt(10) = "<<sqrt(10)<<"(Default precision)"<<endl;

    return 0;
}

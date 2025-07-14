# include <iostream>
# include <cmath>

using namespace std;

int main() {

    cout.fill('<');
    for(int i = 0; i < 10; i++) {
        cout.width(5);
        cout<<i;
        cout.width(10);
        cout<<1.0 / float(i)<< endl;

        if (i == 0) {
            cout.fill('>');
        }
    }

    cout<<"Padding changed"<< endl;
    cout.fill('#');
    cout.width(15);
    cout<<12.345<< endl;
    return 0;
}

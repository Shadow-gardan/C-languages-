#include <iostream>
using namespace std;

const int size = 3;  // Fixed: Added 'int' to declaration

template <class T>
class vector {
    T* v;

public:
    vector() {
        v = new T[size];
        for (int i = 0; i < size; i++)
            v[i] = 0;
    }

    vector(T* a) {
        v = new T[size];  // Fixed: Allocate memory
        for (int i = 0; i < size; i++)
            v[i] = a[i];
    }

    T operator*(const vector& y) const {  // Fixed: const reference and const function
        T sum = 0;
        for (int i = 0; i < size; i++)
            sum += v[i] * y.v[i];
        return sum;
    }

    ~vector() {  // Fixed: Destructor to free memory
        delete[] v;
    }
};

int main() {
    int a[] = {1, 2, 3};
    int b[] = {4, 5, 6};

    vector<int> v1(a);
    vector<int> v2(b);

    int r = v1 * v2;

    cout << "Dot product: " << r << endl;

    return 0;
}


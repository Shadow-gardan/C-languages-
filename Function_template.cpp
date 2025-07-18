#include<iostream>

using namespace std;

template<class T>
void swap(T &x, T &y){
	T temp =x;
	x =y;
	y =temp;
}

void fun(int m,int n, float a, float b){
	cout<<"m and n before swap : "<< m << " "<<n<<endl;
	swap(m,n#include<iostream>
using namespace std;

// Template for swapping two variables
template<class T>
void swapValues(T &x, T &y){
	T temp = x;
	x = y;
	y = temp;
}

// Updated fun to use references so changes reflect globally
void fun(int &m, int &n, float &a, float &b){
	cout << "m and n before swap : " << m << " " << n << endl;
	swapValues(m, n);
	cout << "m and n after swap  : " << m << " " << n << endl;

	cout << "a and b before swap : " << a << " " << b << endl;
	swapValues(a, b);
	cout << "a and b after swap  : " << a << " " << b << endl;
}

int main(){
	int m = 1, n = 2;
	float a = 11.22, b = 33.44;

	fun(m, n, a, b);

	return 0;
}
);
	cout <<"m and n after swap : "<<m<<" "<<n<<endl;
	
	cout<<"a and b before swap : "<< a << " "<<b<<endl;
	swap(a,b);
	cout <<"m and n after swap : "<<a<<" "<<b<<endl;
	
}

int main(){
	fun(1,2,11.22,33.44);
	return 0;
}

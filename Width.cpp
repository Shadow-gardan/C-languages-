#include<iostream>
#include<string>
using namespace std;



int main(){
	
	int item[4] ={10,8,12,15};
	int cost[4] ={75,34,78,87};
	
	cout.width(5);
	cout<<"Item";
	cout.width(8);
	cout<<"Cost";
	cout.width(15);
	cout<<"Total Cost"<<endl;

	int sum = 0;
	for(int i = 0; i < 4; i++){

		cout.width(5);
		cout<<item[i];
		cout.width(8);
		cout<<cost[i];
		
		int total = item[i] * cost[i];
		cout.width(15);
		cout<<total<<endl;
		sum += total;

	}

	cout<<endl<<"Grand Total Cost: ";
	cout.width(2);
	cout<<sum<<endl;

	return 0;
}

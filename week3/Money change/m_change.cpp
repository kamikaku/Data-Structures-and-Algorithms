#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::vector;
/*
给出一个数值1---1000，用（1，5，10）这几个数来拆分，就是换零钱，
返回的数值是，最少用几张票子来换完


*/


int M_change(int num, vector<int> L){

	int size = L.size();
	int c{};
	for(int i=0;i<size;i++)
	{
		int d = L[i];
		if(num ==0){
			return c;
		}
		if(d<=num){			
			c= c+(int)(num/d);
			num = num%d;
		}
	}
	return c;
}

int main(){
	int num;
	cin>>num;
	vector<int> L{10,5,1};
	cout<<M_change(num,L)<<'\n';
}
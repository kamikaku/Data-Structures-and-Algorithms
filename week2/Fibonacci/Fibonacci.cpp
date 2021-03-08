#include <iostream>
using std::cout;
using std::cin;

int Fibo(const int& n){
	if(n==0 || n==1){
		return n;
	}
	return Fibo(n-2)+Fibo(n-1);
	
}

long long FiboFast(const int& n){
	
	if(n<=1){
		return n;
	}
	long long f1{0};
	long long f2{1};
	
	for(int i=0; i<n; i++){
		long long sum = f1+f2;
		f1=f2;
		f2 = sum;
	}
	
return f1;	
}

int main(){
	
	int n{};
	cin>>n;
	
	cout<<FiboFast(n);
}
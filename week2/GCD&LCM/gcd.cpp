#include <iostream>
using std::cout;
using std::cin;

int NaiveGCD(int a,int b){
	
	int n = a<b?a:b;
	int res{};
	for(int i=1;i<=n;i++){
		
		if(!(a%i) && !(b%i)){
			res = i;
		}
	}
	return res;
	
}

int EuclidGCD(int a,int b){
	
	if(b == 0){
		return a;
	}
	int a1 = a%b;
	return EuclidGCD(b,a1);
}

int main(){
	
	int a{},b{};
	cin>>a;
	cin>>b;
	//int res = NaiveGCD(a,b);
	int res = EuclidGCD(a,b);
	cout<<res<<'\n';

}
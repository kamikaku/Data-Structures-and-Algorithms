#include <iostream>

/*
最小公倍数 一是把从a和b中较大的数到a*b中间的所有数字进行判断，出现的第一个能够整除两个数的就是最小公倍数

第二是用公式，最大公倍数乘以最小公约数是等于两数乘积的，最小公约数可以用欧几里得的辗转相除法

*/


using std::cout;
using std::cin;

long long LCM(int a, int b)//检测10000000 9999999时很慢
{

	long long c = (long long)(a)*b;
	int l = a>b?a:b;
	long long res{};
	for(int i=l; i<c+1; i++){
		if(!(i%a||i%b)){
			res = i;
			break;
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

long long LCM_Fast(int a, int b){
	
	long long c = (long long)(a)*b;
	int gcd = EuclidGCD(a,b);
	long long res = (long long)c/gcd;
	return res;
	
}




int main(){
	int a{},b{};
	cin>>a;
	cin>>b;
	long long res = LCM_Fast(a,b);
	cout<<res<<'\n';
	return 0;
	
}
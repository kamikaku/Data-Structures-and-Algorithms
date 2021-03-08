#include <iostream>

/*
关于Fabonacci的最后一位数是什么，其实每次在计算时至保留最后一位数就行了。
也就是一直保证存储的数是个位数
*/
using std::cout;
using std::cin;

int F_L_d(int n){
	
	if(n<=1){
		return n;
	}
	int f1=0;
	int f2=1;
	for(int i=0;i<n-1;i++){
		int tep = f1;
		f1 = f2;
		f2 = (tep+f2)%10;
	}
	return f2;
	
}

int main(){
	
	int n{};
	cin>>n;
	int res = F_L_d(n);
	cout<<res<<'\n';
	
	return 0;
	
}
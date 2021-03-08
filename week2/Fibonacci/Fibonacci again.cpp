#include <iostream>
#include <vector>
/*
求Fabonacci的对m的余数值。
利用同余的性质 即(a+b) mod c = (a mod c + b mod c)mod c。mod是求余的意思
Fabonacci大数求余 可以吧周期找出来，简化大数
经过推论可以知道 出现0，1则是一个循环的开始，因此需要寻找的是第二次出现0，1时的数，这个数就是用于循环的数
*/
using std::cout;
using std::cin;
using std::vector;



long long period(int m){
	
	if(m<=1){
		return 1;
	}
	long long f1{0};
	long long f2{1};
	long long p{2};
		//cout<<f1<<' '<<f2<<'\n';
	while(true){
		long long tep = ((long long)(f1) + f2)%m;
		f1 = f2%m;
		f2 = tep%m;
		//cout<<f1<<' '<<f2<<'\n';
		if(f1==0&&f2==1){
			break;
		}
		p++;
	}

	
	return p-1;
}

long long getperiod(long long n,int m){ 

    vector<int> storemod; 

    storemod.push_back(0); 

    storemod.push_back(1); 

    for(long long i=2;i<=n;i++){ 

        storemod.push_back((storemod[i-1]+storemod[i-2])%m); 
		
		//cout<<storemod[i-1]<<' '<<storemod[i-2]<<'\n';

        if(storemod[i]==1 && storemod[i-1]==0){ 

            return i-1; 

        } 

    } 
return 0;
} 

long long Fagain(long long n,int m){
	
	if(n<=1){
		return n%m;
	}
	long long f1=0,f2=1;
	
	for(long long i=0;i<n-1;i++){
		long long tep =f1%m;
		f1 = f2%m;
		f2 = (tep+f1)%m;
	}
	return f2;
}

int main(){
	
	long long n{};
	int m{};
	cin>>n;
	cin>>m;
	
	long long p = period(m);
	getperiod(n,m);
	n = (long long)(n)%p;
	long long res = Fagain(n,m);
	//cout<<p<<' '<<n<<'\n';
	cout<<res<<'\n';
	return 0;
	
}
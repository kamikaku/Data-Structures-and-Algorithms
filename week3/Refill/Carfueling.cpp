#include <iostream>
#include <vector>
/*
汽车驶向目的地d，汽车慢油状况下可以行驶m米，在中途有n个加油站。
汽车停靠最少的加油站到达目的地，
输出所停靠加油站的数目
*/

using std::cout;
using std::cin;
using std::vector;

int Numstatiom(vector<int> x, int M){
	int num = 0;//记录车站数
	int cur=0;//记录当前的车站位置 即x的下标
	
	while(cur<x.size()-1)
	{
		int last = cur;
		while(cur<=x.size()&&(x[cur+1]-x[last])<=M){
			cur+=1;
		}
		if(last==cur){
			return -1;
		}
		else if(cur<x.size()-1){
			num+=1;
		}
	}
	
	return num;
} 

int main(){
	
	int D{};
	cin>>D;
	int M{};
	cin>>M;
	int n{};
	cin>>n;
	vector<int> station(n+1);
	station[0]=0;
	for(int i=1;i<n+1;i++){
		int s{};
		cin>>s;
		station[i]=s;
	}
	station.push_back(D);
	//cout<<station[0];
	cout<<Numstatiom(station,M)<<'\n';
	
}
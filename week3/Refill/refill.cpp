#include <iostream>
#include <vector>
/*
根据汽车在路途中进入最少的加油站到达目的地为例子，引出贪心算法

步骤为 提出贪心的方案
检查贪心的方案是否安全
用子问题重复贪心方案
*/

using std::cout;
using std::cin;
using std::vector;

int Numstatiom(vector<int> x, int L){
	int num = 0;//记录车站数
	int cur=0;//记录当前的车站位置 即x的下标
	
	while(cur<x.size()-1)
	{
		int last = cur;
		while(cur<=x.size()&&(x[cur+1]-x[last])<=L){
			cur+=1;
			cout<<cur;
		}
		cout<<last<<'\n';
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
	
vector<int> station{1,3,5,6,7,9};
	
	int L{};
	cin>>L;
	
	cout<<Numstatiom(station,L)<<'\n';
	
}
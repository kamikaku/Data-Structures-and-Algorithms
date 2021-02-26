#include <cstdlib>
#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::cin;


long long MaxPairwiseProduct(const vector<int>& v){
	
	int n = v.size();
	int maxValue=0;
	for(int i=0;i<n; i++){
		for(int j=i+1; j<n; j++){
			if((long long)(v[i])*v[j]>maxValue){
				maxValue = (long long)(v[i])*v[j];
			}
		}
	}
	return maxValue;
}

long long MaxPairwiseProductFast(const vector<int>& v){
	
	int n = v.size();
	int max_index1=-1;
	for(int i=0; i<n; i++){
		
		if(max_index1==-1 || v[i]>v[max_index1])
		max_index1 = i;
	}
	int max_index2 = -1;
	for(int j=0; j<n; j++){
		//if((v[j]!=v[max_index1]) && ((max_index2==-1) || (v[j]>v[max_index2])))
		if((j!=max_index1) && ((max_index2==-1) || (v[j]>v[max_index2])))
		max_index2 = j;
	}
	long long res = (long long )(v[max_index1]) * v[max_index2];
	return res;
}

int main(){
	
	/*while(true){
		int num = rand() % 100 + 2;
		cout<<num<<'\n';
		vector<int> t;
		for(int i=0; i<num; i++){
			t.push_back(rand()%100000);
		}
		for(int j=0; j<num; j++){
			cout<<t[j]<<' ';
		}
		cout<<"\n";
		long long res1 = MaxPairwiseProduct(t);
		long long res2 = MaxPairwiseProductFast(t);
		if(res1 != res2){
			cout<<"wrong answer: "<<res1<<' '<<res2<<'\n';
			break;
		}
		else{
			cout<<"pass\n";
		}
		
	}*/
	
	int n{};
	cin>>n;
	vector<int> a(n);
	for(int i=0; i<n; i++){
		cin>>a[i];
			
	}
	long long res = MaxPairwiseProductFast(a);
	cout<<res<<"\n";
	
}
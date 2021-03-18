#include <iostream>
#include <vector>
using std::cout;
using std::cin;
using std::vector;
/*
最大价值的问题，提供n个物件，给出物件的价值与重量
能够携带的物件有重量限制，找出限制内最大价值的搭配
输出最高的价值
*/

class Object {
public:
	int value;
	int weight;
	double unit_v;
};

//排序
vector<Object> Osort(vector<Object> obj) {
	for (int i = 0; i < obj.size(); i++) {
		for (int j = i; j < obj.size()-1; j++) {
			if (obj[i].unit_v < obj[j + 1].unit_v) {
				Object swap = obj[j + 1];
				obj[j + 1] = obj[i];
				obj[i] = swap;
			}
		}
	}
	return obj;
}

//返回最小
int min(int a, int b) {
	int res = a < b ? a : b;
	return res;
}

//
double M_value(vector<Object> obj, int W) {

	int n = obj.size();
	double allV{};
	for (int i = 0; i < n; i++) {
		if (W == 0) {
			return allV;
		}
		int w = obj[i].weight;
		w = min(w, W);
		double v = obj[i].unit_v;
		double a = (double)w;
		allV = allV + a * v;
		W -= w;
	}
	return allV;
}

int main() {
	int n, W;
	cin >> n >> W;
	vector<Object> Ob(n);
	for (int i = 0; i < n; i++) {
		Object obj;
		cin >> obj.value >> obj.weight;
		obj.unit_v = (double)(obj.value / (double)obj.weight);
		Ob[i] = obj;
	}
	Ob = Osort(Ob);
	double res = M_value(Ob, W);
	std::cout.precision(10);
	cout<<res << '\n';
}

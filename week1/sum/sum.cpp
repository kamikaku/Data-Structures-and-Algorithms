/*####################
问题描述：
输入 两个数字
输出 数字之和

思路：
创建向量v存储所有输入的数字
对v求和
##################*/
#include <iostream>
#include <vector>
int main() {

	int a{};
	std::vector<int> v{};
	while (std::cin >> a) {

		v.push_back(a);
		if (std::cin.get() == '\n') {
			break;
		}
	}
	int sum{};
	for (int i = 0; i < v.size(); i++) {
	
		sum += v[i];
	}

	std::cout << sum << '\n';

}

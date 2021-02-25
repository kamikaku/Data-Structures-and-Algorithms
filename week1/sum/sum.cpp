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

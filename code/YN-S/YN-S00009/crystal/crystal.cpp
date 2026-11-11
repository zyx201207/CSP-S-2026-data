#include <iostream>
using namespace std;

int main() {
	long long m, n;
	std::cin >> n >> m;
	long long a[260470];
	for (int i = 0; i <= n; i++) {
		std::cin >> a[i];
	}
	for (int i = 0; i <= n; i++) {
		std::cout << a[i];
	}

	return 0;
}
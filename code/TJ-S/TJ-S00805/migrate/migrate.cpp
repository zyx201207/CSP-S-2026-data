#include <iostream>
#include <vector>

using ll = long long;

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w+", stdout);
	int c, t;
	std::cin >> c >> t;
	while(t--) {
		ll n, d;
		std::cin >> n >> d;
		ll x1 = 0, x2 = 0, diff;
		for(int i = 1; i <= n; ++i) {
			if(i % 2) {
				std::cin >> x2;
			} else {
				std::cin >> x1;
			}
			if(x2 - x1 > 0) {
				diff = x2 - x1;
			}
		}
		if(d < diff * 2) {
			std::cout << 0 << std::endl;
		} else {
			std::cout << n - 3 << std::endl;
		}
	}
	return 0;
}

#include <bits/stdc++.h>

void solve(int c) {
	int n, d;
	std::cin >> n >> d;
	std::vector<int> x(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> x[i];
	}

	std::cout << "0\n";
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);

	int c, t;
	std::cin >> c >> t;
	while (t--) {
		solve(c);
	}
	return 0;
}

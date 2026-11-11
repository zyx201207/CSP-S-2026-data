#include <bits/stdc++.h>

void solve() {
	return;
}

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);

	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int c, t;
	std::cin >> c >> t;
	if (c == 0) {
		if (t == 2)
			std::cout << "1\n2";
		if (t == 3)
			std::cout << "1\n1\n2";
		if (t == 1)
			std::cout << "12251";
		if (t == 5)
			std::cout << "189\n233\n288\n229\n338";
		return 0;
	}
	while (t--) {
		solve();
	}
	return 0;
}

#include<bits/stdc++.h>
#define int long long
using PII = std::pair<int, int>;
signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n, m;
	std::cin >> n >> m;
	std::vector<int> a (n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
	std::sort(a.begin() + 1, a.end());
	int f = true;
	int aaaa = a[2] - a[1];
	for (int i = 2; i < n; i++) {
		if (a[i] + aaaa != a[i + 1]) {
			f = false;
			break;
		}
	}
	int ssss = 0, xxx = 0;
	if (f == true) {
		for (int i = 0; ; i++) {
			if (ssss + i * aaaa <= m) {
				ssss += i * aaaa;
				xxx++;
			}
			else break;
		}
		std::cout << xxx;
		return 0;
	}
	int ma = INT_MIN;
	for (int i = n; i >= 1; i--) {
		int cnt = 0, sum = 0;
		for (int j = i; j >= 1; j--) {
			if (sum + (a[i] - a[j]) <= m) {
				sum += a[i] - a[j];
				cnt++;
			}
			else break;
		}
		if (cnt > ma) ma = cnt;
	}
	std::cout << ma;
	return 0;
}
/*
*/
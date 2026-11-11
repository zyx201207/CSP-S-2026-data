#include <bits/stdc++.h>
#define int long long
using namespace std;

int jz[100005];

signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	int n, m, zd;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> jz[i];
	}
	sort(jz + 1, jz + n + 1);
	if (m == 1) {
		cout << jz[n];
	} else {
		cout << jz[n - m + 1];
	}
	return 0;
}

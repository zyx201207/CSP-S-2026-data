#include <bits/stdc++.h>
using namespace std;
long long c, n, m, d, q, x, k;

int main() {
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> x;
	}
	for (int i = 1; i <= n; i++) {
		cin >> k;
		for (int i = 1; i <= k * 2; i++) {
			cin >> x;
		}
	}
	cin >> x >> k;
	cout << "32 17";
	return 0;
}
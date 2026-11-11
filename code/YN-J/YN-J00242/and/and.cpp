#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
long long n, a[N], m, ans;
vector<long long>e;

signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		e.push_back(a[i]);
	}
	for (int j = 31; j >= 0; j--) {
		vector<long long>b;
		for (int i = 0; i < e.size(); i++) {
			long long w = e[i];
			if ((w >> j) & 1) {
				b.push_back(w);
			}
		}
		if (b.size() >= m) {
			ans += (1 << j);
			e.clear();
			for (int i = 0; i < b.size(); i++) {
				e.push_back(b[i]);
			}
		}
	}
	cout << ans << '\n';
	return 0;
}

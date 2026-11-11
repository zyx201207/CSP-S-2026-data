#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 5;
int n, m;
int a[N];
void solve() {
	scanf("%lld%lld", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	int id = 0;
	int ans = 0;
	vector<int> v, vec;
	for (int i = 30; i >= 0; i--) {
		for (int j = 1; j <= n; j++) {
			if ((1 << i) & a[j]) {
				v.push_back(a[j]);
			}
		}
		if ((int)v.size() >= m) {
			id = i - 1;
			ans += (1 << i);
			break;
		} else {
			v.clear();
		}
	}
	for (int i = id; i >= 0; i--) {
		for (auto it : v) {
			if ((1 << i) & it) {
				vec.push_back(it);
			}
		}
		if ((int) vec.size() >= m) {
			swap(vec, v);
			ans += (1 << i);
		}
		vec.clear();
	}
	printf("%lld", ans);
}
signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	solve();
	return 0;
}

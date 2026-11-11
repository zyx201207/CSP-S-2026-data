#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n, m, ans, cnt;
vector<ll> a, b;
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	a.assign(n, 0);
	for (int i = 0; i < n; i ++) cin >> a[i];
	for (int v = 29; v >= 0; v --) {
		cnt = 0;
		for (auto x : a) if (x & (1ll << v)) cnt ++;
		if (cnt >= m) {
			ans += (1ll << v);
			b.clear();
			for (auto x : a) if (x & (1ll << v)) b.push_back(x);
			a.swap(b);
		}
	}
	cout << ans;
	return 0;
}

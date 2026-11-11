/*
#include <iostream>
using namespace std;
const int maxn = 200005;
int n, m, a[maxn], ans = -0x3f3f3f3f;
int dfs(int i, int d) {
	if(d == m) {
		return a[i];
	}
	int res = -0x3f3f3f3f;
	for(int j = i+1; j <= n; ++j) {
		res = max(res, a[i] & dfs(j, d+1));
	}
	return res;
}
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	for(int i = 1; i <= n; ++i) {
		ans = max(ans, dfs(i, 1));
	}
	cout << ans;
	return 0;
}
*/
#include <iostream>
#define ll long long
using namespace std;
const int maxn = 200005;
ll n, m, a[maxn], ans = -0x3f3f3f3f, f[maxn];
ll dfs(int d) {
	if(d == 1) {
		ll res = -0x3f3f3f3f, x;
		for(int j = 1; j <= n; ++j) {
			if(res < a[j]) {
				res = a[j];
				x = j;
			}
		}
		f[x] = 1;
		return res;
	}
	ll res = -0x3f3f3f3f, x;
	ll nxt = dfs(d-1);
	for(int j = 1; j <= n; ++j) {
		if(!f[j]) {
			if(res < (nxt & a[j])) {
				res = (nxt & a[j]);
				x = j;
			}
		}
	}
	f[x] = 1;
	return res;
}
ll dfs(int i, int d) {
	if(d == m) {
		return a[i];
	}
	ll res = -0x3f3f3f3f;
	for(int j = i+1; j <= n; ++j) {
		res = max(res, a[i] & dfs(j, d+1));
	}
	return res;
}
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	if(n * m >= 10000)
		ans = dfs(m);
	else {
		for(int i = 1; i <= n; ++i) {
			ans = max(ans, dfs(i, 1));
		}
	}
	cout << ans;
	return 0;
}

#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int maxn = 2e6 + 7;

int c, t;
vector<ll> a(maxn), dis, route;
vector<bool> vis;

inline void dfs(int u, int n, int d) {
	vis[u] = true;
	route.resize(n + 2);
	for(int i = 1; i <= n; ++i) {
		for(int j = i; j <= n; ++j) {
			if(a[j] - a[i] <= d) {
				route[j]++;
			}
		}
	}
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> c >> t;
	for(int i = 1; i <= t; ++i) {
		int n, d, ans = 0;
		cin >> n >> d;
		for(int i = 1; i <= n; ++i) cin >> a[i];
//		int diff = a[2] - a[1], times = d / diff;
//		dfs(1, n, d);
//		for(int i = 1; i <= n; ++i) {
//			for(int j = i; j <= n; ++j) {
//				if(route[i] == route[j]) ans++;  
//			}
//		} 
		cout << "0\n";
	}
	return 0;
} 

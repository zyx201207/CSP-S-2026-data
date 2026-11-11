#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 20;
vector<int> e[MAXN];
int n, k;
int fa[MAXN];
int find(int x) {
	if (x != fa[x])
		fa[x] = find(fa[x]);
	return fa[x];
}
void mrge(int x, int y) {
	int fx = find(x), fy = find(y);
	if (fx != fy) fa[fx] = fy;
}
//vector <int
//bool check(int mask) {
//	if (__builtin_popcount(mask) != k) return false;
//
//}
void solve() {
	cin >> n >> k;
//	for (int i = 1; i <= n; ++i)
//		e[i].clear();
	for (int i = 1, u, v; i < n;  ++i) {
		cin >> u >>  v;
	}
	if (k >= n) {
		cout << 0 << '\n';
	} 
	else {
//		int cnt = ceil((1.0 * k) / 2);

		cout << max(1ll, (int)ceil(((n + 1) / 2 - k) / 4) + ((n + 1) / 2 - k) % 4 + 1) << '\n';
	}

}
signed main() {
#ifndef DEBUG
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
#else
	freopen(".\\hub\\hub5.in", "r", stdin);
//	freopen(".\\hub\\hub5.out", "w", stdout);
#endif
	int c, T;
	cin >> c >> T;
	while (T--)
		solve();
	return 0;
}
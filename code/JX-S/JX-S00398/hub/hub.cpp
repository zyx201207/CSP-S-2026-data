#include <bits/stdc++.h>

using namespace std;
const int N = 1e6 + 6;
const int N2 = 4e3 + 3;
int c;
int n, k;
vector<int> e[N];
int f[N];
int fa[N];
int find(int x) {
    return (fa[x] == x) ? (fa[x]) : (fa[x] = find(fa[x]));
}
void merge(int x, int y) {
    int X = find(x), Y = find(y);
    if (X == Y) return ;
    fa[X] = Y;
    return ;
}
void init() {
	for (int i = 1; i <= n; i++) e[i].clear();
	return ;
}
void sub1() {
	cin >> n >> k;
	init();
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		e[u].emplace_back(v);
		e[v].emplace_back(u);
	}
	int ans = n;
	for (int mask = 1; mask < (1 << n); mask++) {
		if (__builtin_popcount(mask) > k) continue;
		// haiyao panduan liantongkuai shuliang !!!
		int cnt = 0;
		for (int i = 1; i <= n; i++) fa[i] = i;
		for (int i = 1; i <= n; i++) {
            for (int v : e[i]) {
                if ((mask >> (i - 1) & 1) && (mask >> (v - 1) & 1)) merge(i, v);
            }
		}
		for (int i = 1; i <= n; i++) {
            if ((mask >> (i - 1) & 1) && find(i) == i) cnt++;
		}
		if (cnt > 2) continue;
		int sum = 0;
		queue<int> q;
		for (int i = 1; i <= n; i++) {
			f[i] = -1;
			if (mask >> (i - 1) & 1) {
				f[i] = 0;
				q.push(i);
			}
		}
		while (!q.empty()) {
			int u = q.front();
			q.pop();
			sum = max(sum, f[u]);
			for (int v : e[u]) {
				if (f[v] != -1) continue;
				f[v] = f[u] + 1;
				q.push(v);
			}
		}
		ans = min(ans, sum);
	}
	cout << ans << '\n';
	return ;
}
inline void sub2() {
	cin >> n >> k;
	init();
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		e[u].emplace_back(v);
		e[v].emplace_back(u);
	}
	cout << n / k + 1 << '\n';
	return ;
}
signed main() {
	// if in submit
		freopen("hub.in", "r", stdin);
		freopen("hub.out", "w", stdout);
	// endif
	// if in test
        // freopen("hub2.in", "r", stdin);
        // freopen("hub.out", "w", stdout);
	// endif

	ios :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> c >> T;
	while (T--) {
		// solve
		if (c >= 1 && c <= 3) { // 15pts
			sub1();
		}
		else sub2();
	}
	return 0;
}
/*
1 1
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10
*/

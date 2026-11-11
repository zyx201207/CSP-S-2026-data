#include <bits/stdc++.h>
#define int long long
using namespace std;
inline int read() {
	int x = 0, f = 1;
	char ch = getchar();
	while (!isdigit(ch)) {
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while (isdigit(ch)) {
		x = x * 10 + (ch - '0');
		ch = getchar();
	}
	return f * x;
}
const int N = 1e5 + 5, inf = 1e18;
int cc, tt;
int n, k, fa[N], vis[N], ans;
vector<int> e[N];
int mp[N];
void paint(int x) {
	for (int i = 0; i < e[x].size(); ++i)
		if (!vis[e[x][i]] && mp[e[x][i]])
			vis[e[x][i]] = 1, paint(e[x][i]);
}
int find(int x) {
	if (mp[x]) return 0;
	if (vis[x]) return inf;
	vis[x] = 1;
	int res = inf;
	for (int i = 0; i < e[x].size(); ++i)
		res = min(res, find(e[x][i]) + 1);
	vis[x] = 0;
	return res;
}
signed main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cc = read(), tt = read();
	while (tt --) {
		n = read(), k = read(), ans = inf;
		for (int i = 1; i < n; ++i) {
			int a = read(), b = read();
			e[a].push_back(b), e[b].push_back(a);
		}
		for (int s = 0; s < (1 << n); ++s) {
			int cnt = 0;
			vector<int> v;
			for (int j = 0; j < n; ++j) {
				int p = (s >> j) & 1;
				if (p == 1) v.push_back(j + 1), mp[j + 1] = 1;
			}
			for (int j = 0; j < v.size(); ++j) {
				int x = v[j];
				if (!vis[x]) vis[x] = 1, paint(x), ++cnt;
			}
			for (int j = 0; j <= n; ++j) vis[j] = 0;
			if (cnt <= k) {
				int res = 0;
				for (int j = 1; j <= n; ++j) 
					res += find(j);
				ans = min(res, ans);
			}
			for (int j = 0; j <= n; ++j) vis[j] = mp[j] = 0;
		}
		printf("%lld\n", ans);
	}
	return 0;
}

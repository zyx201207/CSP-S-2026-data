#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 7;
int n, m, a[N];
vector<int > g[N];
map<int, int > mp;
int ans;
struct Node {
	int p, l;
	int pos[32];
}b[N];
bool cmp (Node u, Node v) {
	if (u.pos[1] == v.pos[1]) {
		return u.p > v.p;
	}
	return u.pos[1] > v.pos[1];
}
signed main () {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		int now = a[i];
		int len = 0;
		while (now != 0) {
			len++;
			int ge = now % 2;
			if (ge == 1) {
				g[i].push_back(len);
			}
			now /= 2;
		}
	}
	for (int i = 1; i <= n; i++) {
		sort(g[i].begin(), g[i].end(), greater<int>());
	}
	for (int i = 1; i <= n; i++) {
		b[i].l = i;
		b[i].p = g[i].size();
		for (int j = 0; j < g[i].size(); j++) {
			b[i].pos[j + 1] = g[i][j];
		}
	}
	sort(b + 1, b + 1 + n, cmp);
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= b[i].p; j++) {
			mp[b[i].pos[j]]++;
		}
//		cout << '\n';
	}
	for (pair<int, int > po : mp) {
		int u = po.first, v = po.second;
//		cout << u << ' ' << v << '\n';
		u--;
		if (v >= m) { 
//			cout << u << '\n';
			ans += (1 << u);
		}
	}
	cout << ans;
	return 0;
}

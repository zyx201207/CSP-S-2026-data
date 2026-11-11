#include <bits/stdc++.h>
#define ll long long
using namespace std;
int c, n, m, d, q, w[500005], k[505], a, t, x, y, ans, vis1[500005], vis2[505];
struct nd {
	int a, t;
};
struct nd2 {
	int a, t, w;
};
vector<nd > v1[500005], v2[505];
void read(int &a) {
	int x = 0, f = 1;
	char c = getchar();
	while (c < '0' || c > '9') {
		if (c == '-') f = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		x *= 10;
		x += c - '0';
		c = getchar();
	}
	a = x*f;
}
void dfs(int x, int idx, int w) {
	if(w>ans) return;
	if (idx == 0) {
		if (x == y) {
			ans = min(ans, w);
			return;
		}
		for (nd it : v1[x]) {
			if (vis2[it.a] == 0) {
				vis2[it.a] = 1;
				dfs(it.a, 1, w + it.t);
				vis2[it.a] = 0;
			}
		}
	} else {
		for (nd it : v2[x]) {
			if (vis1[it.a] == 0) {
				vis1[it.a] = 1;
				dfs(it.a, 0, w + it.t);
				vis1[it.a] = 0;
			}
		}
	}
	return;
}
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		read(w[i]);
	}
	for (int i = 1; i <= n; i++) {
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++) {
			read(a);
			read(t);
			v1[a].push_back(nd{i, t});
			v2[i].push_back(nd{a, t});
		}
	}
	for (int i = 1; i <= q; i++) {
		read(x);
		read(y);
		ans = 999999;
		dfs(x, 0, w[x] + w[y]);
		cout << ans << endl;
	}
	return 0;
}

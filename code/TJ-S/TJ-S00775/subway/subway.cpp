#include <bits/stdc++.h>

using namespace std;

struct node {
	int v = 0, to = 0, next = 0, same = 0;
} vis[25];

struct T {
	int l = 0, in[25];
} a[500005];

int T, n, m, d, q, l, res, w[10005], cnt[25];

int te, ar, b, x, y, t, sp, z[25][500005];

void add (int u, int v, int type) {
	l++;
	vis[l].v = z[u][type] + z[v][type];
	vis[l].to = v;
	vis[l].same = type;
	vis[l].next = cnt[u];
	cnt[u] = l;
}

int dfs (int now, int spend) {
	if (spend > res) return 0;
	if (now == b) {
		res = min (res, spend);
		return 0;
	}
	for (int x = cnt[t]; x != 0; x = vis[x].next) {
		dfs (vis[x].same, spend + vis[x].v);
	}
	return 0;
}

int main () {
	//freopen ("subway.in", "r", stdin);
	//freopen ("subway.out", "w", stdout);
	cin >> T >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) cin >> w[i];
	for (int i = 1; i <= n; i++) {
		cin >> te;
		for (int j = 1; j <= te; j++) {
			cin >> x >> y;
			z[i][x] = y;
			a[x].l++;
			a[x].in[a[x].l] = i;
			//if (x == 1) cout << a[x].in[l] << endl;;
		}
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k < j; k++) {
				if (z[j][i] && z[k][i]) add (j, k, i), add (k, j, i);
			}
		}
	}
	/*for (int i = 1; i <= l; i++) {
		cout << vis[i].v << " " << vis[i].to << " " << vis[i].next << endl;
	}*/
	while (q--) {
		res = 1e9;
		cin >> ar >> b;
		for (int i = 1; i <= a[ar].l; i++) {
			sp = 1e9;
			dfs (a[ar].in[i], 0);
			res = min (res, sp + )
		}
		cout << endl;
		cout << res + w[ar] + w[b] << endl;
	}
	//fclose (stdin);
	//fclose (stdout);
	return 0;

}

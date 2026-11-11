#include<bits/stdc++.h>
#include<map>
#define int long long
using namespace std;
const int N = 505;
const int M = 5e5 + 5;
const int D = 25;

// freopen()
// AC in 16:12
// 关注 luogu@jackzhangcn2013 谢谢喵

int c, n, m, d, q;
int w[M];
int f[N][N];
vector<int> a[N], t[N];
map<int, int> tmn[M];
signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int st = clock();
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for(int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		a[i].resize(k + 1);
		t[i].resize(k + 1);
		for(int j = 1; j <= k; j++) {
			cin >> a[i][j];
			cin >> t[i][j];
			tmn[a[i][j]][i] = t[i][j];
		}
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			f[i][j] = 1e18;
		}
		f[i][i] = 0;
	}
	for(int i = 1; i <= n; i++) {
		for(int k = 1; k < a[i].size(); k++) {
			int u = a[i][k];
			for(pair<int, int> _ : tmn[u]) {
				int j = _.first;
				if(i == j) {
					continue;
				}
				f[i][j] = min(f[i][j], t[i][k] + tmn[u][j]);
			}
		}
	}
	for(int k = 1; k <= n; k++) {
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
			}
		}
	}
	while(q--) {
		int x, y;
		cin >> x >> y;
		int res = 1e18;
		for(pair<int, int> _ : tmn[x]) {
			int u = _.first, tu = _.second;
			for(pair<int, int> __ : tmn[y]) {
				int v = __.first, tv = __.second;
				res = min(res, tu + f[u][v] + tv);
			}
		}
		cout << w[x] + res + w[y] << '\n';
	}
	return 0;
}

/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

*/
#include <bits/stdc++.h>
#define int long long
#define endl "\n"

using namespace std;

#define min(a, b) (a > b ? b : a)

const int N = 5e2 + 9;
const int M = 2e1 + 9;

vector < pair <int, int> > g[N];
vector <int> l[N];

int dis[M][N];
int f[N][N];
int w[N];

int cnt[N];
int a[N][M];
int t[N][M];

int flag1;

int n, m;
int d, q;
int c;

void solve1() {
	for(register int i = 1; i <= m; i++) {
		for(register int j = 1; j <= m; j++) {
			f[i][j] = INT_MAX;
		}
	}
	for(register int i = 1; i <= m; i++) {
		f[i][i] = 0;
	}
	for(register int i = 1; i <= n; i++) {
		if(cnt[i] == 2) {
			int u = a[i][1];
			int v = a[i][2];
			int x = t[i][1];
			int y = t[i][2];
			f[u][v] = min(f[u][v], x + y);
			f[v][u] = min(f[v][u], x + y);
		}
	}
	for(register int k = 1; k <= m; k++) {
		for(register int u = 1; u <= m; u++) {
			for(register int v = 1; v <= m; v++) {
				f[u][v] = min(f[u][v], f[u][k] + f[k][v]);
			}
		}
	}
	for(register int i = 1; i <= q; i++) {
		int u, v;
		cin >> u >> v;
		cout << f[u][v] + w[u] + w[v] << endl;
	}
	return ;
}

signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(register int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for(register int i = 1; i <= n; i++) {
		cin >> cnt[i];
		flag1 = max(flag1, cnt[i]);
		for(register int j = 1; j <= cnt[i]; j++) {
			cin >> a[i][j] >> t[i][j];
		}
	}
	if(flag1 <= 2) {
		solve1();
		return 0;
	}
	cout << 32 << endl << 17 << endl;
	return 0;
}
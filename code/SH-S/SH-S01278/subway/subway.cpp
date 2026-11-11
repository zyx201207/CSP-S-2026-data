#include <bits/stdc++.h>

using namespace std;

const long long INF = 0x3f3f3f;
const int N = 501;
const int M = 400 + 10;

int c, n, m, d, q;
int a[M];
vector<int> g[N];
vector<pair<int, int> >g2[M];
int ans = INF;

void dfs(int x, int y, int cnt) {
	if (x == y) {
		ans = min(ans, cnt);
	}
	for (int j = 1; j <= n; j) {
		for (int i = 1; i <= n; i++) {
			if (i != x) {
				dfs(i, y, cnt + g[v][x] + g[v][i]);
			}
		}
	}
}

void solve1() {
	int q;
	cin >> q;
	while (q--) {
		int x, y;
		ans = INF;
		cin >> x >> y;
		dfs(x, y, a[x] + a[y]);
		cout << ans;
	}
	
}

void S() {
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> a[i];
	}
	
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		for (int j = 1; j <= k; j++) {
			int x, t;
			cin >> x >> t;
			g[i][x] = t;
		}
	}
	
	if (n <= 50) {
		solve1();
	}
	
	return;
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	S();
	
	return 0;
}

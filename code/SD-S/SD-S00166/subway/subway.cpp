#include <bits/stdc++.h>

using namespace std;

using i64 = long long;
using pii = pair<i64, i64>;

const int N = 205;
const int M = 405;
const int mod = 998244353;

i64 ve[N][N][M];

void solve() {
	memset(ve1, 0x3f, sizeof(ve1));
	memset(ve2, 0x3f, sizeof(ve2));
	
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	
	vector<i64> w(m + 1); 
	vector<vector<int> > dis(m + 1, vector<int>(n + 1, 1e9));
	for (int i = 1; i <= m; i ++) cin >> w[i];
	
	vector<vector<i64> > a(n + 1), t(n + 1);
	vector<vector<pii> > chu(m + 1);
	for (int i = 1; i <= n; i ++) {
		int k;
		cin >> k;
		for (int j = 1; j <= k; j ++) {
			int x, y;
			cin >> x >> y;
			a[i].push_back(x);
			t[i].push_back(y);
			chu[x].push_back({i, y});
		}
	}
	
	for (int i = 1; i <= n; i ++) {
		for (int j = 0; j < a[i].size() - 1; j ++) {
			dis[a[i][j]][i] = dis[a[i][j + 1]][i] = 0;
		}
	}
	for (int i = 1; i <= m; i ++) {
		for (pii j : chu[i]) {
			for (pii k : chu[i]) {
				int x = j.first, u = j.second;
				int y = k.first, v = k.second;
//				cout << x  << ' '<< y << '\n'; 
				if (x == y) continue;
				ve[x][y][i] = u + v;
//				cout << ve[x][y][i] << '\n';
			}
		}
	}
	
	for (int i = 1; i <= q; i ++) {
		int l, r;
		cin >> l >> r;
		cout << w[l] + w[r] << '\n';
	} 
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int T = 1;
//  cin >> T;
	while (T --) {
		  solve();
	}
	
	return 0;
}


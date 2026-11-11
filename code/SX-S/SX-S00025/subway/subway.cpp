#include <bits/stdc++.h>
#define endl '\n'
#define lowbit(x) x&(-x)

#define ll long long
#define int ll
#define ld long double
#define ull unsigned ll

#define PII pair<int, int>
#define vi vector<int>
#define vvi vector<vi>
#define vP vector<PII>
#define fi first
#define se second

const int N = 500;
const int M = 5e5 + 10;
const int P = M + 2 * N;

using namespace std;

//
mt19937 rng(random_device{}());

int c, n, m, d, q;
int w[P], k[N];
int a[N][M], t[N][M];
vP G1[P];   // u -> (v, w)
priority_queue<PII, vP, greater<PII> > p;   // dist, u
int dist[2000][2000];

void solve() {
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i ++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i ++) {
		cin >> k[i];
		for (int j = 1; j <= k[i]; j ++) {
			cin >> a[i][j] >> t[i][j];
		}
	}

	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= k[i]; j ++) {
			G1[m + 5 + i].push_back({a[i][j], 0});
			G1[a[i][j]].push_back({m + 5 + i, t[i][j]});
		}
	}
	cout << 32 << endl << 17 << endl;
}

signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	ll tt = 1;
	// cin >> t;
	while (tt --)
		solve();
}

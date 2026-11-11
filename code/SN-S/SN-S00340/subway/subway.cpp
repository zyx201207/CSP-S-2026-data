/*
Author: fortyqin
*/
#include <bits/stdc++.h>
//#define int long long
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
using namespace std;
using ui = unsigned int;
using ll = long long;
using ull = unsigned long long;
using LLL = __int128;
using uLLL = unsigned __int128;
bool MBE;

const int N = 5e5+10, M = 505;
const ll inf = 1e18;
vector<pair<int, int>> e[N]; // 线路，时间 
int base[N]; // 地铁口到站台的时间
ll dis[M][M]; // 线路，到，线路，最短路
int n; // 地铁线路数
int m; // 地铁口数量
int D; // 
int q; 

void chkmin(ll &x, ll y) {
	x = min(x, y);
}

void start() {
	int c;
	cin >> c >> n >> m >> D >> q;
	for (int i=1; i<=m; ++i) cin >> base[i];
	for (int i=1; i<=n; ++i) {
		int k; cin >> k;
		for (int j=1; j<=k; ++j) {
			int x, t;
			cin >> x >> t;
			e[x].push_back({i, t});
		}
	}
	memset(dis, 0x3f, sizeof dis);
	for (int i=1; i<=n; ++i) dis[i][i] = 0;
	for (int i=1; i<=m; ++i) {
		int u = sz(e[i]);
		if (u <= 1) continue;
		for (int x=0; x+1<u; ++x) {
			for (int y=x+1; y<u; ++y) {
				int v1, t1; tie(v1, t1) = e[i][x];
				int v2, t2; tie(v2, t2) = e[i][y];
				chkmin(dis[v1][v2], (ll)(t1 + t2));
				chkmin(dis[v2][v1], (ll)(t1 + t2));
			}
		}
	}
	for (int k=1; k<=n; ++k) {
		for (int x=1; x<=n; ++x) {
			for (int y=1; y<=n; ++y) {
				chkmin(dis[x][y], dis[x][k] + dis[k][y]);
			}
		}
	}
	while (q--) {
		int s, t;
		cin >> s >> t;
		if (s == t) {
			cout << "0\n";
			return;
		}
		ll B = base[s] + base[t];
		ll ans = inf;
		for (int x=0; x<sz(e[s]); ++x) {
			for (int y=0; y<sz(e[t]); ++y) {
				int v1, t1; tie(v1, t1) = e[s][x];
				int v2, t2; tie(v2, t2) = e[t][y];
				chkmin(ans, B + (ll)t1 + (ll)t2 + dis[v1][v2]);
			}
		}
		cout << ans << '\n';
	}
}

bool MED;
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string name = "subway";
	freopen((name+".in").c_str(), "r", stdin);
	freopen((name+".out").c_str(), "w", stdout);
//	cerr << "-- " << (&MBE - &MED) / 1048576 << " Mib\n";
	int test_cnt = 1;
//	cin >> test_cnt;
	while (test_cnt--) start();
//	cerr << 1000 * clock() / CLOCKS_PER_SEC << " ms\n";
	return 0;
}


#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, l, r) for (int i = l; i <= r; i ++)
#define pil pair<int, ll>
#define pb push_back
#define edl cout <<'\n';
#define debug cout << '*';
#define fi first
#define se second
const int M = 5e5+10;
const int N = 5e2+10;
const ll inf = 2e16;
vector <pil > H[M];
ll G[N][N];
ll ds[N][N];
ll w[M];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int c, n, m, d, q;
	cin >> c >> n >> m>> d >>q;
	rep(i, 1, m) cin >> w[i];
	rep(i, 1, n) {
		int k;
		cin>> k;
		rep(j, 1, k) {
			int aa, tt;
			cin>> aa >>tt;
//			if (i==1&&aa==2) debug 
			H[aa].pb({i, tt});
		}
	}
//	rep(i, 1, m) {
////		cout << H[i].size() <<":";
//		rep(j, 0, (int)H[i].size()-1){
//			cout << H[i][j].fi << '|' << H[i][j].se <<' ';
//		}
//		edl
//	}
	rep(i, 1, n) {
		rep(j, 1, n) {
			if (i!=j) G[i][j] = inf;
		}
	}
	rep(s, 1, m) {
		int sz = H[s].size();
		rep(i, 0, sz-1) {
			int u = H[s][i].fi;
			ll pp = H[s][i].se;
			rep(j, 0, sz-1) {
				int v = H[s][j].fi;
				ll qq = H[s][j].se;
				G[u][v] = min(G[u][v], pp+qq);
			}
		}
	}
	rep(i, 1, n) {
		rep(j, 1, n) {
			ds[i][j] = G[i][j];
		}
	}
	rep(k, 1, n) {
		rep(i, 1, n) {
			rep(j, 1, n) {
				ds[i][j] = min(ds[i][j], ds[i][k] + ds[k][j]);
			}
		}
	}
//	rep(i, 1, n) {
//		rep(j, 1, n) cout << ds[i][j] << ' ';edl
//		
//	}
	while (q --) {
		int x, y;
		cin >> x >>y;
		ll ans = inf;
		int sz1 = H[x].size();
		int sz2 = H[y].size();
		rep(i, 0, sz1-1) {
			int u = H[x][i].fi;
			ll pp = H[x][i].se;
			rep(j, 0, sz2-1) {
				int v = H[y][j].fi;
//				cout << u << ' ' << v <<'\n';
				ll qq = H[y][j].se;
				ans = min(ans, ds[u][v]+pp+qq+w[x]+w[y]);
			}
		}
		cout << ans << '\n';
	}
}

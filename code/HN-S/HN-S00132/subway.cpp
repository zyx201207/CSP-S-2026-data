#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 5e5 + 55, MAXM = 5e2 + 52;
const ll INF = 1e16;

int CaseID, m, n, d, q;

int w[MAXN];
vector<pair<int,int> >e[MAXN];

ll dis[2][MAXM][MAXM];

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> CaseID >> m >> n >> d >> q;
    for(int i = 1; i <= n; i++) {
		cin >> w[i];
    }
    for(int i = 1; i <= m; i++) {
		for(int j = 1; j <= m; j++) {
			dis[0][i][j] = (i == j ? 0LL : INF);
		}
    }
    for(int i = 1, k; i <= m; i++) {
		cin >> k;
		for(int j = 1, v, w; j <= k; j++) {
			cin >> v >> w;
			e[v].push_back({w, i});
		}
    }
    for(int v = 1; v <= n; v++) {
		int esize = e[v].size();
		for(int p1 = 0; p1 < esize; p1++) {
			for(int p2 = 0; p2 < esize; p2++) {
				if(p1 == p2)continue;
				int u1 = e[v][p1].second, u2 = e[v][p2].second;
				ll w = e[v][p1].first + e[v][p2].first;
				dis[0][u1][u2] = min(dis[0][u1][u2], w);
				dis[0][u2][u1] = min(dis[0][u2][u1], w);
			}
		}
    }
    for(int p = 1; p <= m; p++) {
		int cur = p & 1, lst = cur ^ 1;
	    for(int i = 1; i <= m; i++) {
		    for(int j = 1; j <= m; j++) {
				dis[cur][i][j] = min(dis[lst][i][j], dis[lst][i][p] + dis[lst][p][j]);
		    }
	    }
    }
    int cur_m = m & 1;
    for(int i = 1, x, y; i <= q; i++) {
	    cin >> x >> y;
	    ll ans = INF;
	    for(int ix = 0; ix < e[x].size(); ix++) {
			int ux = e[x][ix].second, wx = e[x][ix].first;
			for(int iy = 0; iy < e[y].size(); iy++) {
				int uy = e[y][iy].second, wy = e[y][iy].first;
				//cout << ux << ' ' << wx << ' ' << uy << ' ' << wy << '\n';
				ans = min(ans, dis[cur_m][ux][uy] + wx + wy);
			}
	    }
	    //cout << "ans: ";
	    cout << ans + w[x] + w[y] <<'\n';
    }
    return 0;
}

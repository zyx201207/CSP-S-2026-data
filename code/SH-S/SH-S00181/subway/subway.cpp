#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll INF = 1e18;

ll w[500005];
ll k[502];
ll sk[502];
int a[500005];
ll t[500005];
int cnt = 0;

struct Edge{
	int to;
	ll w;
};
vector<Edge> metro[500005];

ll exc[502][502];
//ll dis[502][502];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	ll c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	
	for (int i = 1; i <= n; i++) {
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++) {
			cnt++;
			cin >> a[cnt] >> t[cnt];
			metro[a[cnt]].push_back({i, t[cnt]});
		}
	}
	
	for (int i = 1; i <= n; i++) {
		sk[i] = sk[i - 1] + k[i];
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) exc[i][j] = 0;
			else exc[i][j] = INF;
		}
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = sk[i - 1] + 1; j <= sk[i]; j++) {
			for (Edge e : metro[a[j]]) {
				if (e.to == i) exc[i][i] = 0;
				exc[i][e.to] = min(exc[i][e.to], e.w + t[j]);
				exc[e.to][i] = min(exc[e.to][i], e.w + t[j]);
//				cerr << i << ' ' << e.to << ' ' << e.w << ' ' << t[j] << endl;
			}
		}
	}
	
	for (int mid = 1; mid <= n; mid++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				exc[i][j] = min(exc[i][mid] + exc[mid][j], exc[i][j]);
			}
		}
	}
//	
//	for (int i = 1; i <= m; i++) {
//		for (Edge e : metro[i]) {
//			cerr << e.to << ' ' << e.w << '\n';
//		}
//		cerr << endl;
//	}
//	cerr << endl;
//	
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= n; j++) {
//			cerr << exc[i][j] << ' ';
//		}
//		cerr << endl;
//	}
	
	for (int T = 0; T < q; T++) {
		int x, y;
		cin >> x >> y;
		
		ll res = INF;
		for (Edge ex : metro[x]) {
			for (Edge ey : metro[y]) {
				res = min(exc[ex.to][ey.to] + ex.w + ey.w, res);
//				cerr << ex.to << ' ' << ey.to << endl;
			}
		}
		
		res += w[x] + w[y];
		
		cout << res << '\n';
	}
}

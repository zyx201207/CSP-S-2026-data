#include <bits/stdc++.h>
using namespace std;

// รปีะมห  

typedef long long ll;
typedef pair<ll, ll> pll;
const int N = 505;
const int M = 5*1e5+5;

struct edge {
	ll a = 0;
	ll t = 0;
};

ll c, n, m, d, q, x, y;
ll w[M], k[M], a[N][M], t[N][M];
bool vis[M];
vector<edge> g[M];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	freopen("subway.in",  "r", stdin);
	freopen("subway.out", "w", stdout);
	
	cin >> c >> n >> m >> d >> q;
	for (int i=1; i<=m; i++) {
		cin >> w[i];
	}
	for (int i=1; i<=n; i++) {
		cin >> k[i];
		for (int j=1; j<=k[i]; j++) {
			cin >> a[i][j] >> t[i][j];
		}
	} 
	
	while (q--) {
		cin >> x >> y;
		
		memset(vis, 0, sizeof(vis));
		queue<pll> q;
		ll ans = 0;
		
		q.push({x, 0});
	}

	return 0;
}


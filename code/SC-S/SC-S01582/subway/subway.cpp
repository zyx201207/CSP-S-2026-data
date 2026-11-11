#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
const int MAXN = 510, MAXM = 5e5 + 10;
const ll INF = 0x3f3f3f3f3f3f3f3f;
ll w[MAXM], dis[MAXN][MAXN], f[MAXN][MAXN];
vector <ll> a[MAXN], t[MAXN];
vector <pair<int, ll>> idx[MAXM];
int k[MAXN], c, n, m, d, q;
signed main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++){
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++){
		cin >> k[i];
		a[i].resize(k[i] + 1);
		t[i].resize(k[i] + 1);
		for (int j = 1; j <= k[i]; j++){
			cin >> a[i][j] >> t[i][j];
			idx[a[i][j]].push_back({i, t[i][j]});
		}
	}
	memset(dis, 0x3f, sizeof(dis));
	for (int i = 1; i <= m; i++){
		for (auto x : idx[i]){
			for (auto y : idx[i]){
				if (x.fi == y.fi){
					continue;
				}
				dis[x.fi][y.fi] = min(dis[x.fi][y.fi], x.se + y.se);
			}
		}
	}
	memset(f, 0x3f, sizeof(f));
	for (int i = 1; i <= n; i++){
		f[i][i] = 0;
	}
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			f[i][j] = min(f[i][j], dis[i][j]);
		}
	}
	for (int o = 1; o <= n; o++){
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++){
				f[i][j] = min(f[i][j], f[i][o] + f[o][j]);
			}
		}
	}
	while (q--){
		int x, y;
		cin >> x >> y;
		ll minn = INF;
		for (auto u : idx[x]){
			for (auto v : idx[y]){
				minn = min(minn, u.se + f[u.fi][v.fi] + v.se);
			}
		}
		cout << minn + w[x] + w[y] << "\n";
	}
	return 0;
}
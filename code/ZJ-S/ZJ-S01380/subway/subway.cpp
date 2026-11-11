#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define pii pair<int,int>
#define fi first
#define se second

const int N = 510;
const int M = 5e5 + 10;
const int inf = 1e18;

int cid,n,m,d,q;
int w[M];
int dis[N][N];
vector <pii> vv[M];

void solve(){
	cin >> m >> n >> d >> q;
	for (int i = 1 ; i <= n ; i++) cin >> w[i];
	for (int i = 1 ; i <= m ; i++){
		int sz; cin >> sz;
		for (int j = 1 ; j <= sz ; j++){
			int u,w;
			cin >> u >> w;
			vv[u].push_back({i,w});
		}
	}	
	for (int i = 1 ; i <= m ; i++)
		for (int j = 1 ; j <= m ; j++)
			dis[i][j] = (i == j ? 0 : inf);
	for (int i = 1 ; i <= n ; i++){
		for (int j = 0 ; j < (int)vv[i].size() ; j++){
			for (int k = j + 1 ; k < (int)vv[i].size() ; k++){
				int u = vv[i][j].fi,v = vv[i][k].fi,w = vv[i][j].se + vv[i][k].se;
				dis[u][v] = min(dis[u][v],w);
				dis[v][u] = min(dis[v][u],w);
			}
		}
	}
	for (int k = 1 ; k <= m ; k++)
		for (int i = 1 ; i <= m ; i++)
			for (int j = 1 ; j <= m ; j++)
				dis[i][j] = min(dis[i][j],dis[i][k] + dis[k][j]);
	//cout << dis[1][1] << ' ' << dis[1][2] << ' ' << dis[2][1] << ' ' << dis[2][2] << endl;
	while (q--){
		int x,y,res = inf;
		cin >> x >> y;
		for (auto i : vv[x])
			for (auto j : vv[y])
				res = min(res,dis[i.fi][j.fi] + i.se + j.se);
		res += w[x] + w[y];
		cout << res << endl;
	}
}
signed main(){
	//freopen("subway7.in","r",stdin);
	//freopen("my.out","w",stdout);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T = 1; cin >> cid;
	while (T--) solve();
	return 0;
}
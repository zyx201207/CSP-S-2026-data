#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll M = 5e5+10; 
const ll N = 500+10;
const ll D =  20+ 3;
const ll Q = 1e5+10;
struct Node{
	ll index;
	ll dist;
};
ll c, n, m, d, q;
ll w[M];
ll k[N];
ll a[N][M];
ll t[N][M];
ll x[Q];
ll y[Q];
map<ll, ll> g[N*D+1000];
// 键值对存在就是连通,第i个站的第j条线路站台表示为i*D+j,第i个站的站厅表示为i*D 
int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subwau.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=m;i++) cin >> w[i];
	for(int i=1;i<=n;i++){
		cin >> k[i];
		for(int j=1;j<=k[i];j++){
			cin >> a[i][j] >> t[i][j];
		}
		for(int u=1;u<=k[i];u++){
			for(int v=j+1;v<=k[i];v++){
				g[a[i][u]*D+j][a[i][v]*D+j] = 0;
				g[a[i][v]*D+j][a[i][u]*D+j] = 0;
			}
		}
		for(int j=1;j<=k[i];j++){
			g[a[i][j]*D][a[i][j]*D+j] = t[i][j];
			g[a[i][j]*D+j][a[i][j]*D] = t[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		cin >> x[i] >> y[i];
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
template<typename T>
T chkmax(T x,T y){
	if(x < y)return y;
	return x;
}
template<typename T>
T chkmin(T x,T y){
	if(x > y)return y;
	return x;
}
#define N 505
#define M 500005
int c,n,m,d,q;
int w[M];
struct node{
	int v,w;
};
vector<node> G[M];
i64 f[N][N];
void solve(){
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++)cin >> w[i];
	for(int i = 1; i <= n; i++){
		int k;
		cin >> k;
		for(int j = 1; j <= k; j++){
			int a,t;
			cin >> a >> t;
			node x;
			x.v = i;
			x.w = t;
			G[a].push_back(x);
		}
	}
	memset(f,0x3f,sizeof(f));
	for(int i = 1; i <= n; i++)f[i][i] = 0;
	for(int i = 1; i <= m; i++){
		for(int x = 0; x < G[i].size(); x++){
			for(int y = 0; y < G[i].size(); y++){
				int u = G[i][x].v,v = G[i][y].v;
				i64 w = G[i][x].w + G[i][y].w;
				f[u][v] = chkmin(f[u][v],w);
				f[v][u] = chkmin(f[v][u],w);
			}
		}
	}
	for(int k = 1; k <= n; k++){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				f[i][j] = chkmin(f[i][j],f[i][k] + f[k][j]);
			}
		}
	}
	while(q--){
		int u,v;
		cin >> u >> v;
		i64 minn = (1ll << 61);
		for(int x = 0; x < G[u].size(); x++){
			for(int y = 0; y < G[v].size(); y++){
				minn = chkmin(minn,G[u][x].w + f[G[u][x].v][G[v][y].v] + G[v][y].w);
			}
		}
		cout << w[u] + w[v] + minn << '\n';
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T = 1;
	//cin >> T;
	while(T--)solve();
	return 0;
}


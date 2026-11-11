#include <bits/stdc++.h>
#pragma GCC optimize(3)
#pragma GCC optimize(2)
#define int long long
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
const int N = 503,M = 5e5+3;
int c,n,m,d,q;
int cost[M];
vector<pii> g[M];   //{编号，距离}
int f[N][N];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=m;++i){
		cin >> cost[i];
	}
	memset(f,0x3f,sizeof f);
	for(int i=1;i<=n;++i) f[i][i] = 0;
	for(int i=1,ln;i<=n;++i){
		cin >> ln;
		for(int j=1,ta,tt;j<=ln;++j){
			cin >> ta >> tt;
			for(pii k : g[ta]){
				f[k.fi][i] = min(f[k.fi][i],tt+k.se);
				f[i][k.fi] = min(f[k.fi][i],tt+k.se);
			}
			g[ta].push_back({i,tt});
		}
	}
	for(int k=1;k<=n;++k){
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				f[i][j] = min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	while(q--){
		int x,y;
		cin >> x >> y;
		int res = f[0][0];
		for(pii i : g[x]){
			for(pii j : g[y]){
				res = min(res,i.se+f[i.fi][j.fi]+j.se+cost[x]+cost[y]); //
			}
		}
		cout << res << "\n";
	}
	return 0;
}
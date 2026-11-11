#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=5e5+7;
int c,n,m,d,q,a[maxn],sz[maxn];
ll f[506][506];
vector< array<int,2> > g[maxn];
void build(){
	for(int i = 1;i<=m;i++){
		for(int j = 0;j<sz[i];j++){
			ll w = g[i][j][1];
			int u = g[i][j][0];
			for(int k = 0;k<sz[i];k++){
				if(k==j)continue;
				w+=g[i][k][1];int v = g[i][k][0];
				if(f[u][v]==0)f[u][v]=w;
				else f[u][v]=min(f[u][v],w);
			}
		}
	}
}
void floyd(){
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=n;j++){
			if(i==j)continue;
			for(int k = 1;k<=n;k++){
				if(k==i || j==k)continue;
				if(f[i][k]==0 || f[k][j]==0)continue;
				if(f[i][j]==0)f[i][j]=f[i][k]+f[k][j];
				else f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i<=m;i++)cin >> a[i];
	for(int k,i = 1;i<=n;i++){
		cin >> k;
		for(int u,w,j = 1;j<=k;j++){
			cin >> u >> w;
			g[u].push_back({i,w}); 
			sz[u]++;
		}
	}
	build();
	floyd();
	while(q--){
		int u,v;
		ll ans=5e18;
		cin >> u >> v;
		for(auto it1 : g[u]){
			int w1=it1[1],x = it1[0];
			for(auto it2 : g[v]){
				int w2=it2[1],y = it2[0];
				ans=min(ans,f[x][y]+w1+w2+a[u]+a[v]);
			}
		}
		cout << ans << "\n";
	}
	return 0;
}

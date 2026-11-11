#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,x,y,w[500005],k[505],a[505][500005],t[505][500005];
bool vis[500005],linevis[505],g[500005][505];
long long ans;
void dfs(int u,long long s) {
	if(u==y) {
		ans=min(ans,s);
		return;
	}
	for(int i=1; i<=n; i++) {
		int l=g[u][i];
		if(linevis[l]) {
			continue;
		}
		linevis[l]=1;
		for(int j=1; j<=k[i]; j++) {
			int v=a[l][j];
			if(v==u||vis[v]) {
				continue;
			}
			vis[v]=1;
			dfs(v,s+t[l][u]+t[l][v]);
			vis[v]=0;
		}
		linevis[l]=0;
	}
	return;
}
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1; i<=m; i++) {
		cin>>w[i];
	}
	for(int i=1; i<=n; i++) {
		cin>>k[i];
		for(int j=1; j<=k[i]; j++) {
			cin>>a[i][j]>>t[i][j];
			g[a[i][j]][i]=1;
		}
	}
	while(q--) {
		ans=LLONG_MAX;
		memset(vis,0,sizeof(vis));
		memset(linevis,0,sizeof(linevis));
		cin>>x>>y;
		dfs(x,w[x]+w[y]);
		cout<<ans<<"\n";
	}
	return 0;
}
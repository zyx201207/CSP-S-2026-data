#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=5e5+5;
int n,m,a[205][405],ans=1e18,sum,t[205][405],c,d,q,w[N],k[N],vis[205][405];
struct node {
	int tp;
	int v;
};
vector<node>g[N];
void dfs(int u,int tar,int l,int f){
	if(u==tar){
		sum+=t[l][u];
		ans=min(ans,sum);
		return ;
	}
	for(node v:g[u]){
		if(vis[v.tp][v.v])continue;
		vis[v.tp][v.v]=1;
		if(v.tp!=l)
			sum+=t[l][u]+t[v.tp][u];
		dfs(v.v,tar,v.tp,u);
		if(v.tp!=l)
			sum-=t[l][u]+t[v.tp][v.v];
	}
}
signed main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i) cin>>w[i];
	for(int i=1;i<=n;++i){
		cin>>k[i];
		for(int j=1;j<=k[i];++j){
			cin>>a[i][j];
			cin>>t[i][a[i][j]];
			if(j>1){
				g[a[i][j-1]].push_back({i,a[i][j]});
				g[a[i][j]].push_back({i,a[i][j-1]});
			}
		}
	}
	while(q--){
		memset(vis,0,sizeof vis);
		ans=1e18;
		int x,y;
		cin>>x>>y;
		sum=0;
		dfs(x,y,0,0);
		ans+=w[x]+w[y];
		cout<<ans<<"\n";
	}
}

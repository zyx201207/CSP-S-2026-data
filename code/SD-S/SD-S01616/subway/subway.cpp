#include<bits/stdc++.h>
#define int long long
using namespace std;
struct N{
	int to,ti;
};
int c,n,m,d,q,x,y;
int w[500005],k[500005],a[500005],t[500005];
int vis[1500005];
vector<N> g[1500005];
int ans=0x3f3f3f3f3f3f3f3f;
void dfs(int x,int y,int sum){
	if(x==y){
		ans=min(ans,sum);
		return ;
	}
	if(sum>=ans) return ;
	for(int i=0;i<g[x].size();i++){
		N h=g[x][i];
		if(!vis[h.to]){
			vis[h.to]=1;
			dfs(h.to,y,sum+h.ti);
			vis[h.to]=0;
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
		g[i+m].push_back({i,w[i]});
		g[i].push_back({i+m,w[i]});
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[j]>>t[j];
			g[i+2*m].push_back({a[j]+m,t[j]});
			g[a[j]+m].push_back({i+2*m,t[j]});
		}
	}
	while(q--){
		cin>>x>>y;
		ans=0x3f3f3f3f3f3f3f3f;
		memset(vis,0,sizeof vis);
		vis[x]=1;
		dfs(x,y,0);
		cout<<ans<<endl;
	}
	return 0;
}


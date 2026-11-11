#include <bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q,ans,f;
int k[510],w[500010],vis[500010];
vector<int> a[510],t[510],b[500010],g[500010];
void dfs(int u,int st,int tar){
	if(u==tar){
		ans=min(ans,st);
		return ;
	}
	vis[u]=1;
	for(int v=0;v<g[u].size();v+=2)if(!vis[g[u][v]])dfs(g[u][v],st+g[u][v+1],tar);
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1,x,y;j<=k[i];j++){
			cin>>x>>y;
			a[i].push_back(x);
			t[i].push_back(y);
			b[x].push_back(i);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<a[i].size()-1;j++){
			g[a[i][j]].push_back(a[i][j+1]);
			g[a[i][j]].push_back(t[i][j]+t[i][j+1]);
			g[a[i][j+1]].push_back(a[i][j]);
			g[a[i][j+1]].push_back(t[i][j]+t[i][j+1]);
		}
	}
	while(q--){
		int x,y;
		for(int i=1;i<=m;i++)vis[i]=0;
		ans=1e18;
		cin>>x>>y;
		dfs(x,0,y);
		cout<<ans+w[x]+w[y]<<'\n';
	}
	return 0;
}


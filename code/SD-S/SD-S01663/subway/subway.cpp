#include<bits/stdc++.h>
using namespace std;

const int N=1e5+505;
int c,n,m,d,q,start,end,ans;
int ww[N],vis[N];
struct srx{
	int to,w;
};
vector <srx> e[N];

void dfs(int u,int sum){
	if(u==end){
		ans=min(ans,sum);
		return ;
	}for(int i=0;i<e[u].size();i++){
		int v=e[u][i].to;
		int w=e[u][i].w;
		if(vis[v]){
			continue;
		}vis[v]=1;
		dfs(v,sum+w);
		vis[v]=0;
	}
}
	
signed main(){

freopen("subway.in","r",stdin);
freopen("subway.out","w",stdout);
ios::sync_with_stdio(false);
cin.tie(0);
cin>>c>>n>>m>>d>>q;
for(int i=1;i<=m;i++){
	cin>>ww[i];
}for(int i=1;i<=n;i++){
	int k;
	cin>>k;
	int x[N],t[N];
	for(int j=1;j<=k;j++){
		cin>>x[j]>>t[j];
	}for(int j=1;j<=k;j++){
		for(int o=j+1;o<=k;o++){
			e[x[j]].push_back({x[o],t[j]+t[o]});
			e[x[o]].push_back({x[j],t[j]+t[o]});
		}
	}
}for(int i=1;i<=q;i++){
	cin>>start>>end;
	ans=0x3f3f3f3f;
	vis[start]=1;
	dfs(start,0);
	vis[start]=0;
	cout<<ans+ww[start]+ww[end]<<"\n";
}

return 0;
}

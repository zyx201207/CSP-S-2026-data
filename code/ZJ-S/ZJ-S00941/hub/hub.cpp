#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,k,st[110][110],ans;
vector<int>e[110];
bool vis[110],vis2[110];
void ffs(int x){
	vis2[x]=1;
	for(int v:e[x]){
		if(!vis[v]||vis2[v])continue;
		ffs(v);
	}
}
void dfs(int nw,int cs){
	if(nw==n+1){
		if(cs!=k)return;
		int ltks=0;
		for(int i=1;i<=n;i++){
			if(vis[i]&&!vis2[i])ffs(i),ltks++;
			if(ltks>2)break;
		}
		for(int i=1;i<=n;i++)vis2[i]=0;
		if(ltks>2)return;
		int mii=0;
		for(int i=1;i<=n;i++){
			int mi=0x3f3f3f3f;
			for(int j=1;j<=n;j++){
				if(vis[j])mi=min(mi,st[i][j]);
			}
			mii=max(mii,mi);
		}
		ans=min(mii,ans);
	}else
	vis[nw]=1,
	dfs(nw+1,cs+1),
	vis[nw]=0,
	dfs(nw+1,cs);
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		ans=0x3f3f3f3f;
		memset(st,0x3f,sizeof st);
		for(int i=1;i<=n;i++)e[i].clear(),st[i][i]=0;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			e[u].push_back(v);
			e[v].push_back(u);
			st[u][v]=st[v][u]=1;
		}
		for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		st[i][j]=min(st[i][j],st[i][k]+st[k][j]);
		dfs(1,0);
		cout<<ans<<'\n';
	}
}

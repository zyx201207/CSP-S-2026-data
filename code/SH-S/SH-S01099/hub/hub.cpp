#include<bits/stdc++.h>
#define N ((int)(100)+10)
using namespace std;
using ll=long long;
int c,T;
int n,k;
vector<int> G[N];
int dis[N][N],st;
bool tag[N],vis[N];
int ans;
void dfs1(int u,int fa,int d){
	dis[st][u]=d;
	for(int v:G[u]){
		if(v==fa)continue;
		dfs1(v,u,d+1);
	}
}
void dfs2(int u,int fa){
	vis[u]=1;
	for(int v:G[u]){
		if(v==fa||!tag[v])continue;
		dfs2(v,u);
	}
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout); 
	scanf("%d%d",&c,&T);
	while(T--){
		scanf("%d%d",&n,&k);
		ans=INT_MAX;
		for(int i=1;i<=n;i++)G[i].clear();
		for(int i=1,u,v;i<n;i++){
			scanf("%d%d",&u,&v);
			G[u].push_back(v);
			G[v].push_back(u);
		}
		for(int i=1;i<=n;i++)st=i,dfs1(i,0,0);
		for(int S=0;S<(1<<n);S++){
			if(__builtin_popcount(S)!=k)continue;
			fill(tag+1,tag+n+1,0);
			fill(vis+1,vis+n+1,0);
			for(int i=1;i<=n;i++)
				if((S>>(i-1))&1)tag[i]=1;
			int cnt=0;
			for(int i=1;i<=n;i++){
				if(!vis[i]&&tag[i])dfs2(i,0),cnt++;
			}
			if(cnt>2)continue;
			int res=0;
			for(int i=1;i<=n;i++){
				int mn=n;
				for(int j=1;j<=n;j++){
					if(!tag[j])continue;
					mn=min(mn,dis[i][j]);
				}
				res=max(res,mn);
			}
			ans=min(ans,res);
		}
		printf("%d\n",ans);
	}
}

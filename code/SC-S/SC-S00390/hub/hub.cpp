#include<bits/stdc++.h>
using namespace std;
const int maxn=4000+10;
const int inf=1e9;
int tid,T,n,k,dis[maxn][maxn],pdis[maxn],ppos[maxn];
bool vis[maxn];
vector<int> e[maxn];
void dfs(int u,int fa,int st){
	for(int i=0;i<(int)e[u].size();i++){
		int v=e[u][i];
		if(v==fa) continue;
		dis[st][v]=dis[st][u]+1;
		dfs(v,u,st);
	}
	return ;
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int u,v;
	cin>>tid>>T;
	while(T--){
		scanf("%d%d",&n,&k);
		for(int i=1;i<n;i++){
			scanf("%d%d",&u,&v);
			e[u].push_back(v);
			e[v].push_back(u);
		}
		for(int i=1;i<=n;i++) dfs(i,0,i);
		int ans=inf;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				vis[i]=vis[j]=true;
				for(int p=1;p<=n;p++){
					pdis[p]=min(dis[i][p],dis[j][p]);
					if(pdis[p]==dis[i][p]) ppos[p]=i;
					else ppos[p]=j;
				}
				for(int p=0;p<=k-2;p++){
					int mx=0,pos=0;
					for(int w=1;w<=n;w++) if(pdis[w]>=mx) mx=pdis[w],pos=w;
					ans=min(ans,mx);
					for(int w=0;w<(int)e[ppos[pos]].size();w++){
						int lw=e[ppos[pos]][w];
						if(vis[lw]) continue;
						if(dis[ppos[pos]][pos]==dis[lw][pos]+1){
							vis[lw]=true;
							for(int pw=1;pw<=n;pw++) if(pdis[pw]>dis[lw][pw]) pdis[pw]=dis[lw][pw],ppos[pw]=lw;
							break;
						}
					}
				}
				for(int p=1;p<=n;p++) vis[p]=false;
			}
		}
		printf("%d\n",ans);
		for(int i=1;i<=n;i++) e[i].clear();
	}
	return 0;
}
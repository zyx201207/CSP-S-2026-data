#include<bits/stdc++.h>
using namespace std;
int c,T,n,k,ans,vis[1100],dis[1100][1100],st[1010],f[1010],in[1100];
int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
vector < int > edge[1010];
void init(int u,int fa,int sum,int rt){
	dis[rt][u]=sum;
	for(int v:edge[u])
		if(v!=fa)
			init(v,u,sum+1,rt);
}
void dfs(int pos,int cnt){
	if(pos==n&&cnt<k)return;
	if(cnt==k){
		for(int i=1;i<=n;i++)f[i]=i;
		for(int i=1;i<=n;i++)in[i]=0;
		for(int i=1;i<=k;i++)in[st[i]]=1;
		for(int i=1;i<=k;i++){
			for(int v:edge[st[i]]){
				if(!in[v])continue;
				int x=find(st[i]),y=find(v);
				if(x!=y)f[x]=y;
			}
		}
		int a=find(st[1]),b=-1,ma=0;
		for(int i=2;i<=k;i++){
			int v=find(st[i]);
			if(v!=a&&v!=b){
				if(b==-1)b=v;
				else return;
			}
		}
		for(int i=1;i<=n;i++){
			if(in[i])continue;
			int mi=1e9;
			for(int j=1;j<=k;j++){
				mi=min(mi,dis[i][st[j]]);
			}
			ma=max(ma,mi);
		}
		ans=min(ans,ma);
		return;
	}
	for(int i=pos+1;i<=n;i++){
		st[cnt+1]=i;
		dfs(i,cnt+1);
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>k;
		for(int i=1;i<=n;i++)edge[i].clear();
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			edge[u].push_back(v);
			edge[v].push_back(u);
		}
		ans=1e9;
		for(int i=1;i<=n;i++)init(i,-1,0,i);
		dfs(0,0);
		cout<<ans<<'\n';
	}
	return 0;
} 
/*
0 2

9 3
1 2
2 8
4 7
6 5
7 9
8 5
5 3
3 9


*/

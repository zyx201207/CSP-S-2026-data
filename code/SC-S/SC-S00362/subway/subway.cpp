#include<bits/stdc++.h>
using namespace std;
const int N=510;
int c,n,m,d,q,ans=INT_MAX;
int w[N],t[N][N];
bool vis[N];
vector<pair<int,pair<int,int>>> g[N];
vector<int> g2[N],no[N];
void dfs(int u,int nowl,int nowc,int en){
	if(nowc>ans) return;
	if(en==u){
		ans=min(ans,nowc+t[nowl][en]);
//		cout<<nowc<<'\n';
		return;
	}
	for(int v:g2[u]){
		if(vis[v]) continue;
		vis[v]=1;
		for(int i:no[v]){
			if(i!=nowl) dfs(v,i,nowc+t[nowl][v]+t[i][v],en);
		}
		dfs(v,nowl,nowc,en);
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%d",&w[i]);
	}
	for(int i=1,k;i<=n;i++){
		scanf("%d",&k);
		for(int j=1,u,w;j<=k;j++){
			scanf("%d%d",&u,&w);
			g2[i].push_back(u);
			no[u].push_back(i);
			t[i][u]=w;
//			g[u].push_back(make_pair(w,make_pair(u,i)));
		}
	}
	for(int i=1,x,y;i<=q;i++){
		scanf("%d%d",&x,&y);
		ans=INT_MAX;
		memset(vis,0,sizeof(vis));
		for(int v:no[x]){
			dfs(x,v,t[v][x],y);
		}
		cout<<w[x]+w[y]+ans<<'\n';
	}
	return 0;
}
/*
5 5
1 2 4 8 9

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

*/
#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
vector<int>g[N];
int n,k;
int a[N];
int dist[N];
bool vis[N];
int ans=n;
void dfs2(int x,int fa,int cost) {
	vis[x]=cost;
	for(auto v:g[x]) {
		if(v==fa||!a[v])continue;
		dist[v]=dist[x]+1;
		dfs2(v,x,cost);
	}
}
void dfs3(int x,int fa) {
	for(auto v:g[x]) {
		if(v==fa)continue;
		dist[v]=dist[x]+1;
		dfs3(v,x);
	}
}
void check(void) {
	memset(vis,0,sizeof(vis));
	int res=0,rt=0;
	for(int i=1; i<=n; i++) {
		if(a[i]) {
			if(!vis[i]){rt++;}
			dist[i]=0;
			dfs2(i,0,rt);
		}
	}
	if(rt>2){
		return;
	}
	for(int i=1;i<=n;i++){
		int rs=n;
		dist[i]=0;
		dfs3(i,0);
		for(int j=1;j<=n;j++){
			if(a[j]){
				rs=min(rs,dist[j]);
			}
		}
		res=max(rs,res);
	}
	ans=min(ans,res);
}
void dfs(int pos,int cost) {
	if(pos==n+1) {
		if(cost==k)
			check();
		return;
	}
	for(int i=1; i>=0; i--) {
		a[pos]=i;
		dfs(pos+1,cost+i);
	}
}
int main() {
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,T;
	scanf("%d%d",&c,&T);
	while(T--) {
		scanf("%d%d",&n,&k);
		for(int i=1; i<=n; i++)g[i].clear();
		for(int i=1,u,v; i<n; i++) {
			scanf("%d%d",&u,&v);
			g[u].push_back(v);
			g[v].push_back(u);
		}
		if(k==2) {
			printf("1\n");
			continue;
		}
		ans=n;
		dfs(1,0);
		printf("%d\n",ans);
	}
	return 0;
}

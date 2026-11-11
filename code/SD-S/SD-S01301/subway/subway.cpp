#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#define ll long long
using namespace std;
struct node{
	int v;
	ll w;
}a[500010][25];
ll jz[500010];
int op,n,m,d,T;
int first[1010];
struct edge{
	int u,v,to;
	ll w;
}q[2010];
int tot=0;
void add_edge(int u,int v,ll w){
	tot++;
	q[tot].u=u;
	q[tot].v=v;
	q[tot].w=w;
	q[tot].to=first[u];
	first[u]=tot;
}
ll dis[1010][1010];
ll vis[1010][1010];
struct nnode{
	int ind;
	ll num;
	bool operator <(const nnode &z) const{
		return num>z.num;
	}
};
priority_queue<nnode> que; 
void dij(int x){
	while(!que.empty()){
		que.pop();
	}
	for(int i=1;i<=n;i++){
		dis[x][i]=1e18;
	}
	dis[x][x]=0;
	que.push({x,0});
	while(!que.empty()){
		nnode t=que.top();
		que.pop();
		if(vis[x][t.ind]) continue;
		vis[x][t.ind]=1;
		for(int k=first[t.ind];k;k=q[k].to){
			if(q[k].w+dis[x][t.ind]<dis[x][q[k].v]){
				dis[x][q[k].v]=q[k].w+dis[x][t.ind];
				que.push({q[k].v,dis[x][q[k].v]});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>op>>n>>m>>d>>T;
	for(int i=1;i<=m;i++)cin>>jz[i];
	for(int j=1;j<=n;j++){
		int k;
		cin>>k;
		for(int i=1;i<=k;i++){
			int u,w;
			cin>>u>>w;
			a[u][++a[u][0].v].v=j;
			a[u][a[u][0].v].w=w;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=a[i][0].v;j++)
		{
			for(int k=j+1;k<=a[i][0].v;k++){
				add_edge(a[i][j].v,a[i][k].v,a[i][k].w+a[i][j].w);
				add_edge(a[i][k].v,a[i][j].v,a[i][k].w+a[i][j].w);
			}
		}
	}
//	for(int i=1;i<=tot;i++){
//		cout<<q[i].u<<" "<<q[i].v<<" "<<q[i].w<<"\n";
//	}
	for(int i=1;i<=n;i++)dij(i);
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout<<dis[i][j]<<" ";
//		}
//		cout<<"\n";
//	}
	while(T--){
		int u,v;
		cin>>u>>v;
		ll ans=jz[u]+jz[v];
		ll tem=1e18;
//		cout<<u<<" "<<v<<" "<<a[u][0].v<<" "<<a[v][0].v<<"\n";
		for(int i=1;i<=a[u][0].v;i++){
			for(int j=1;j<=a[v][0].v;j++){
//				cout<<a[u][i].v<<" "<<a[v][j].v<<"\n";
				tem=min(tem,a[u][i].w+a[v][j].w+dis[a[u][i].v][a[v][j].v]);
			}
		}
		cout<<ans+tem<<"\n";
	}
	return 0;
}


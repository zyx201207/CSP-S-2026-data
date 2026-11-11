#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,tot,dis[500005],vis[500005],head[500005];
int opt,d,w[500005],x,y,qq,k;
priority_queue<pair<int,int>> q,p;
struct node{
	int nxt,v,w;
}a[500005];
struct node1{
	int id,t;
}b[500005];
void add(int u,int v,int w){
	a[++tot].v=v,a[tot].w=w;
	a[tot].nxt=head[u];
	head[u]=tot;
}
void dij(int s){
	for(int i=1;i<=m;i++) dis[i]=1e11,vis[i]=0;
	q=p,dis[s]=0,q.push({0,s});
	while(!q.empty()){
		int u=q.top().second;q.pop();
		for(int i=head[u];i;i=a[i].nxt){
			int v=a[i].v,w=a[i].w;
			if(vis[v]) continue;
			vis[v]=1;
			if(dis[u]+w<=dis[v]){
				dis[v]=dis[u]+w;
				q.push({-dis[v],v});
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>opt>>n>>m>>d>>qq;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int i=1;i<=k;i++) cin>>b[i].id>>b[i].t;
		for(int i=1;i<k;i++)
			for(int j=i+1;j<=k;j++){
				add(b[i].id,b[j].id,b[i].t+b[j].t);
				add(b[j].id,b[i].id,b[i].t+b[j].t);
			}
	}
	while(qq--){
		cin>>x>>y;
		dij(x);
		cout<<dis[y]+w[x]+w[y]<<'\n';
	}
	return 0;
}

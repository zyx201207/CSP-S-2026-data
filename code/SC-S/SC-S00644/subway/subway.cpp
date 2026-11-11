#include <bits/stdc++.h>
using namespace std;
const int M=505,N=500005,Nx=1000005;
struct edge{
	int v,w;
};
struct node{
	int id,v;
	friend bool operator < (node x,node y){
		return x.v>y.v;
	}
};
vector<edge> e[Nx];
priority_queue<node> q; 
int walk[N],k[N];
int a[N],t[N];
int dis[Nx],vis[Nx]; 
int c,n,m,d,T;
int cnt;
int dij(int x,int y){
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	dis[x]=0;
	q.push({x,dis[x]});
	while(!q.empty()){
		int tu=q.top().id;
		q.pop();
		if(vis[tu])
			continue;
		for(int i=0;i<e[tu].size();i++){
			int tv=e[tu][i].v;
			int tw=e[tu][i].w;
			if(dis[tv]>dis[tu]+tw){
				dis[tv]=dis[tu]+tw;
				q.push({tv,dis[tv]});
			}
		}
	} 
	return dis[y];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0); 
	cin>>c>>n>>m>>d>>T;
	for(int i=1;i<=m;i++)
		cin>>walk[i];
	cnt=m;
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[j]>>t[j];
			e[a[j]].push_back({++cnt,t[j]});
			e[cnt].push_back({a[j],t[j]});
			if(j!=1){
				e[cnt-1].push_back({cnt,0});
				e[cnt].push_back({cnt-1,0});
			}
		}
	}
	while(T--){
		int u,v;
		cin>>u>>v;
		cout<<dij(u,v)+walk[u]+walk[v]<<'\n';
	}
	return 0;
}
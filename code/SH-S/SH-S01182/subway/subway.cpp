#include<bits/stdc++.h>
#define int long long
using namespace std;
const int M=2e4+10;
const int N=510;
struct node{
	int v,w;
	bool operator<(const node&p)const{return p.w<w;}
};
int w[M],k[N],a[N][M],t[N][M];
int tid,n,m,d,q,AA,BB,x,y;
//ÌØÊâÐÔÖÊA 
int vis[M],dis[M];
vector<node> g[N];
void dijkstra(){
	priority_queue<node> q;
	memset(vis,0,sizeof vis);
	memset(dis,0x3f,sizeof dis);
	dis[x]=0;q.push({x,0});
	while(!q.empty()){
		node t=q.top();q.pop();
		int u=t.v;
		if(vis[u]) continue;
		vis[u]=1;
		for(node x:g[u]){
			int v=x.v,w=x.w;
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				q.push({v,dis[v]});
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>tid>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i]; 
		if(k[i]>2) AA=1;
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
//			if(i==1&&j==1) flag=t[i][j];
//			if(flag!=t[i][j]) BB=1;
		}
	}
	if(!AA){
		for(int i=1;i<=n;i++){
			if(k[i]==1) continue;
			int u=a[i][1],v=a[i][2];
			g[u].push_back({v,t[i][1]+t[i][2]});
			g[v].push_back({u,t[i][1]+t[i][2]});
		}
		for(int i=1;i<=q;i++){
			cin>>x>>y;
			dijkstra();
			cout<<dis[y]+w[x]+w[y]<<'\n';
		}
	}
//	if(!BB){
//		for(int i=1;i<=q;i++){
//			x=read();y=read();
//			bfs(x);
//			write(dis[y]);
//		}
//	}
	
	
	return 0;
}

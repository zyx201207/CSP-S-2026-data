#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#define ll long long
using namespace std;
const int N=3005;
ll n,m,c,d,q,w[N],hh[N],tot,dis[N][N],vis[N];
struct node{
	int to,nex;
	ll w;
}e[N];
void add(int u,int v,int w){
	e[++tot]={v,hh[u],w};
	hh[u]=tot;
}
void dijkstra(int s){
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
	
	memset(vis,0,sizeof vis);
	dis[s][s]=0;
	q.push(make_pair(0,s));
	while(!q.empty()){
		int u=q.top().second;
		q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(int i=hh[u];i;i=e[i].nex){
			int v=e[i].to;
			ll w=e[i].w;
			if(dis[s][v]>dis[s][u]+w){
				dis[s][v]=dis[s][u]+w;
				q.push(make_pair(dis[s][v],v));
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int v,t;
			cin>>v>>t;
			add(i+m,v,t);
			add(v,i+m,t);
		}
	}
	memset(dis,0x3f,sizeof dis);
	for(int i=1;i<=m;i++){
		dijkstra(i);
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		cout<<dis[x][y]+w[x]+w[y]<<'\n';
	}
	return 0;
}
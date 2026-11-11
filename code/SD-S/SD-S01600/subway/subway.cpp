#include<bits/stdc++.h>
using namespace std;
const int N=610;
#define int long long
int c,n,m,d,q;
int dianshu;
int w[510];
struct edge{
	int t,w;
	edge(int to,int wei):t(to),w(wei){}
};
vector<edge> g[N];
int dis[N];
bool vis[N];
int dijkstra(int s,int vvv)
{
	memset(vis,0,sizeof(vis));
	memset(dis,0x3f,sizeof(dis));
	dis[s]=0;
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;
	pq.push(make_pair(dis[s],s));
	while(!pq.empty()){
		int u=pq.top().second;
		pq.pop();
		if(vis[u])continue;
		vis[u]=1;
		if(u==vvv){
			return dis[u];
		}
		for(int i=0;i<g[u].size();i++){
			int tooo=g[u][i].t;
			if(dis[u]+g[u][i].w<dis[tooo]){
				dis[tooo]=dis[u]+g[u][i].w;
				pq.push(make_pair(dis[tooo],tooo));
			}
		}
	} 
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	dianshu=n+m;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int tonow,wnow;
			cin>>tonow>>wnow;
			g[m+i].push_back(edge(tonow,wnow));
			g[tonow].push_back(edge(m+i,wnow));
		}
	}
	for(int i=1;i<=q;i++){
		int xnow,ynow;
		cin>>xnow>>ynow;
		cout<<dijkstra(xnow,ynow)+w[xnow]+w[ynow]<<"\n";
	}
	return 0;
}

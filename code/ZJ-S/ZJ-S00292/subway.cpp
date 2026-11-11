#include<bits/stdc++.h>
using namespace std;
const int maxn=1e7+7;
const int inf=(1<<20)+7;
int c,n,m,d,q;
int s;
int w[maxn],as[maxn];
long long dis[maxn];
bool vis[maxn];
struct edge{
	int v,w;
};
vector<edge> to[maxn];
void dijkstra(int s){
	for(int i=1;i<m*(n+1);i++){
		dis[i]=inf;
		vis[i]=true;
	}
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
	dis[s]=0;
	pq.push({0,s});
	while(!pq.empty()){
		int u=pq.top().second;
		pq.pop();
		if(!vis[u]) continue;
		vis[u]=false;
		for(auto e:to[u]){
			int v=e.v,w=e.w;
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				pq.push({dis[v],v});
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		int sa;
		cin>>sa;
		w[i]=sa;
	}
	int k;
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			as[j]=a;
			to[a+m*i].push_back({a,t});
			to[a].push_back({a+m*i,t});
			if(j==1) continue;
			to[as[j-1]+m*i].push_back({a+m*i,0});
			to[a+m*i].push_back({as[j-1]+m*i,0});
		}
	}
	int r[q+1];
	int x,y;
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		dijkstra(x);
		r[i]=dis[y]+w[x]+w[y];
	}
	for(int i=1;i<=q;i++){
		cout <<r[i]<<"\n";
	}
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
struct edge{
	long long v,w;
	bool operator<(const edge &p)const{
		p.w<w;
	}
};
vector<edge> g[200005];
long long c,n,m,d,q;
long long w[300000];
int k[505];
long long a[505][5005];
long long t[505][5005];
long long dis[300000];
int vis[300000];
void dijkstra(long long s){
	priority_queue<edge> q;
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	dis[s]=0;
	q.push({s,0});
	while(!q.empty()){
		auto t=q.top();q.pop();
		if(vis[t.v]==1) continue;
		vis[t.v]=1;
		for(auto xx:g[t.v]){
			if(dis[xx.v]>dis[t.v]+xx.w){
				dis[xx.v]=dis[t.v]+xx.w;
				q.push({xx.v,xx.w});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k[i];j++){
			for(int l=j+1;l<=k[i];l++){
				g[a[i][j]].push_back({a[i][l],t[i][j]+t[i][l]});
				g[a[i][l]].push_back({a[i][j],t[i][j]+t[i][l]});
			}
		}
	}
	for(int i=1;i<=q;i++){
		long long x,y;
		cin>>x>>y;
		long long ans=0;
		ans+=w[x]+w[y];
		dijkstra(x);
		ans+=dis[y];
		cout<<ans<<'\n';
	}
	return 0;
} 

#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5,M=5e5+510,inf=0x3f3f3f3f3f3f3f3f;
int c,n,m,mx,q,w[N],k,x,y,ans,d[M];//m个站，n条线路
bool vis[M];
struct node{
	int v,w;
}; 
struct edge{
	int v,dis;
	bool operator<(const edge&o)const{
		if(dis==o.dis) return v<o.v;
		return dis>o.dis;
	}
};
vector<node> e[M];
void dij(){
	for(int i=1;i<=n+m;i++){
		vis[i]=0;
		d[i]=inf;
	}
	d[x]=0;
	priority_queue<edge> q;
	q.push({x,0});
	while(!q.empty()){
		int u=q.top().v;
		q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		if(u==y) break;
		for(auto i:e[u]){
			int v=i.v;
			int w=i.w;
			if(d[u]+w<d[v]){
				d[v]=d[u]+i.w;
				q.push({v,d[v]});
			}
		}
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>mx>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>x>>y;
			e[i+m].push_back({x,y});
			e[x].push_back({i+m,y});
		}
	}
	while(q--){
		cin>>x>>y;
		ans=w[x]+w[y];
		dij();
		cout<<ans+d[y]<<'\n';
	}
	return 0;
}
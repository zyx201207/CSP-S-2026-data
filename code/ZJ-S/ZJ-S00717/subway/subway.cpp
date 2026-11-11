#include<bits/stdc++.h>
using namespace std;
struct node{
	long long dis,id;
	bool operator<(const node &b) const{
		return dis>b.dis;
	}
};
struct edge{
	long long v,w;
};
priority_queue<node> q;
long long c,n,m,d,qq,w[130010],k[505],a,t,x,y,dis[130510],vis[130510];
vector<edge> e[130510];
void dij(long long st){
	for(long long i=1;i<=n+m;i++) dis[i]=0x3f3f3f3f3f3f3f3f,vis[i]=0;
	q.push({0,st});
	dis[st]=0;
	while(!q.empty()){
		auto u=q.top();
		q.pop();
		if(vis[u.id]) continue;
		vis[u.id]=1;
		for(auto tt:e[u.id]){
			if(dis[u.id]+tt.w<dis[tt.v]){
				dis[tt.v]=dis[u.id]+tt.w;
				q.push({dis[tt.v],tt.v});
			}
		}
	}
	return ;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>qq;
	for(long long i=1;i<=m;i++){
		cin>>w[i];
	}
	for(long long i=1;i<=n;i++){
		cin>>k[i];
		for(long long j=1;j<=k[i];j++){
			cin>>a>>t;
			e[a].push_back({i+m,t});
			e[i+m].push_back({a,t});
		}
	}
	while(qq--){
		cin>>x>>y;
		dij(x);
		cout<<dis[y]+w[x]+w[y]<<"\n";
	}
	return 0;
}
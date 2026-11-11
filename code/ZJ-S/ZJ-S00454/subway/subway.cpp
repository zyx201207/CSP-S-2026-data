#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int N=5e2+10,M=5e5+10;
struct point{
	int v,w;
	bool operator<(const point& o)const{
		return w>o.w;
	}
};
int n,m,d,q;
int a[N];
bool vis[N+M];
int dis[N+M];
vector<point> e[N+M];
void Dijkstra(int x){
	memset(dis,0x7f,sizeof(dis));
	dis[x]=0,vis[x]=true;
	priority_queue<point> q;
	q.push({x,0});
	while(!q.empty()){
		int k=q.top().v;q.pop();
		vis[k]=false;
		for(auto t:e[k]){
			int v=t.v,w=t.w;
			if(!vis[v]&&dis[v]>dis[k]+w) dis[v]=dis[k]+w,q.push({v,dis[v]}),vis[v]=true;
		}
	}
	return;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	int __;
	cin>>__>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>a[i];
	for(int i=1,k,v,w;i<=n;i++){
		cin>>k;
		while(k--){
			cin>>v>>w;
			e[m+i].push_back({v,w});
			e[v].push_back({m+i,w});
		}
	}
	int u,v;
	while(q--){
		cin>>u>>v;
		Dijkstra(u);
		cout<<dis[v]+a[u]+a[v]<<'\n';
	}
	cout<<flush;
	fclose(stdin),fclose(stdout);
	return 0;
}

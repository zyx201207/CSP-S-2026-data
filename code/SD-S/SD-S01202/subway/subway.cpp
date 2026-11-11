#include<bits/stdc++.h>
#define ll long long 
#define pli pair<ll,int>
using namespace std;
const int N=5e3,INF=1e9;
ll c,n,m,d,Q,w[N],t[N][N],st,ed,dis[N],a[N];
struct node{
	ll v,id;
};
vector<node> g[N];
priority_queue<pli,vector<pli>,greater<pli> > q; 
void Dijstra(int u,int last){
	q.push({0,st});
	while(!q.empty()){
		u=q.top().second;
		q.pop();
		for(int i=0;i<g[u].size();i++){
			int v=g[u][i].v,id=g[u][i].id;
			if(dis[v]!=INF&&v!=st) continue;
			if(last!=id){
				if(dis[v]>((u!=st?w[u]:0)+dis[u]+t[id][u])){//(u!=st?w[u]:0)
					dis[v]=(u!=st?w[u]:0)+dis[u]+t[id][u];
					q.push({dis[v],v});
				}
			}else{
				if(dis[v]>(dis[u])){
					dis[v]=dis[u];
					q.push({dis[v],v});
				}
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>m>>n>>d>>Q;
	//测试点编号、地铁线路数、地铁站数
	for(int i=1;i<=n;i++){
		scanf("%lld",&w[i]);//从每个地铁站的地铁口走到站厅需要的时间
	}
	for(int i=1;i<=m;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[j];
			g[a[j-1]].push_back({a[j],i});
			g[a[j]].push_back({a[j-1],i});
			cin>>t[i][a[j]];//该地铁站 j 的站厅走到第 i 条线路的站台需要的时间
		}
	}
	while(Q--){
		for(int i=1;i<=n;i++){
			dis[i]=INF;
		}
		cin>>st>>ed;
		dis[st]=w[st];
		Dijstra(st,0);
		cout<<dis[ed]+w[ed]<<"\n";
	}
	return 0;
}

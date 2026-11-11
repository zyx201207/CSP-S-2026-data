#include<bits/stdc++.h>
using namespace std;
#define int long long
struct node{
	int di,u,dt,lstw;
	bool operator<(const node&s)const{
		return di<s.di;
	}
};
priority_queue<node> pq;
struct edge{
	int v,w,dt,lt;
};
struct d{
	int w,dt;
};
vector<edge> vec[500001];
vector<d> g[500001];
int c,n,m,d,q,w[500001],k[500001],dis[500001],dtz[500001];
void dijkstra(int st,int dts){
	memset(dis,0x3f3f3f3f,sizeof(dis));
	dis[st]=0;
	pq.push({0,st,dts,0});
	while(!pq.empty()){
		int u=pq.top().u,D=pq.top().di,dt=pq.top().dt,lw=pq.top().lstw;
		pq.pop();
		for(auto i:vec[u]){
			int v=i.v,w=i.w,dtv=i.dt,lt=i.lt;
			if(dt==dtv){
				if(D<dis[v]){
					dis[v]=D+w-lw;
					dtz[v]=dtv;
					pq.push({dis[v],v,dt,w});
				}
			}
			else{
				if(D+lw+lt<dis[v]){
					dis[v]=D+lt+w;
					dtz[v]=dtv;
					pq.push({dis[v],v,dtv,w});
				}
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1,lst,lstt;j<=k[i];j++){
			int a,t;
			cin>>a>>t;
			if(j!=1){
				vec[lst].push_back({a,t,i,lstt});
				vec[a].push_back({lst,t,i,lstt});
			}
			g[a].push_back({t,i});
			lst=a,lstt=t;
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		int ans=0x3f3f3f3f;
		for(auto i:g[x]){
			dijkstra(x,i.dt);
			int s=dis[y]+i.w;
			ans=min(ans,s+w[x]+w[y]);
		}
		cout<<ans<<'\n';
	}
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
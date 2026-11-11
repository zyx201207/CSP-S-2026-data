#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=505,M=5e5+5;
const int Nt=202,Mt=404;
const int Nt2=505,Mt2=5e5+5;
int Case,n,m,D,Q;
int w[Mt2],k[Nt2];
vector<int>a[Nt2],t[Nt2];
map<pair<int,int>,int>b;
vector<pair<int,int> >e[3*Mt2];
int vis[3*Mt2],dis[3*Mt2];
int tot;
priority_queue<pair<int,int> >pq;
void dijkstra(int s){  //  m log tot
	memset(dis,0x3f,sizeof dis);
	dis[s]=0;
	memset(vis,0,sizeof vis);
	pq.push({0,s});
	while(!pq.empty()){
		auto tmp=pq.top(); pq.pop();
		int u=tmp.second;
		if(vis[u]) continue;
		vis[u]=1;
		for(auto ed:e[u]){
			int vv=ed.first,ww=ed.second;
			if(dis[vv]>dis[u]+ww){
				dis[vv]=dis[u]+ww;
				pq.push({-dis[vv],vv});
			}
		}
	}
}
signed main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>Case>>n>>m>>D>>Q;
	for(int i=1;i<=m;i++){ // 地铁口 &地铁站 1~m  对应的站厅 m+1 ~ 2m 每个站台 2m+1 + 
		cin>>w[i];
		e[i].push_back({i+m,w[i]});
		e[i+m].push_back({i,w[i]});
	}
	tot=2*m+1;
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int ta,tt; cin>>ta>>tt;
			if(!b[{i,ta}]) b[{i,ta}]=++tot;
			a[i].push_back(b[{i,ta}]);
			t[i].push_back(tt);
			e[ta+m].push_back({b[{i,ta}],tt});
			e[b[{i,ta}]].push_back({ta+m,tt});
		}
		for(int u:a[i]){
			for(int v:a[i]){
				if(u==v) continue;
				e[u].push_back({v,0});
				e[v].push_back({u,0});
			}
		}
	}
	for(int i=1;i<=Q;i++){
		int x,y; cin>>x>>y;
		dijkstra(x);
		cout<<dis[y]<<'\n';
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/

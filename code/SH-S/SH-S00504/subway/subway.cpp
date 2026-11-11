// Congragulates 1st Anniversary of game "Devil Connection"
// 2026-10-31 Sat.(6nd)
//
// Devilun  = 6666
// Summoner = 2010
// Cpyadoel = 520
//
// [(Devilun & Summoner & Cpyadoel) | (2026 ^ 1031)] - 6 = 999

#include <bits/stdc++.h>
using ll = long long;

using namespace std;

constexpr int N = 505; // subway cnt
constexpr int M = 500005; // station cnt
constexpr ll INF = 0x3F3F3F3F3F3F3F3F;

struct path{
	int dest;
	ll t;
};
int test_pt, n, m, d, q;
int ground_to_station[M];
vector<path> station_paths[M];

struct graph{
	// 节点为线路 
	ll dis[N][N];
	graph(){
		memset(dis, 0x3F, sizeof(dis));
		for(int i=1;i<N;++i){
			dis[i][i]=0;
		}
	}
	
	void add_path(int u, int v, ll w){
		dis[v][u]=dis[u][v]=min(dis[u][v], w);
	}
	
	void floyd(){
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				for(int k=1;k<=n;++k){
					dis[j][k]=min(dis[j][k], dis[j][i]+dis[i][k]);
				}
			}
		}
	}
};

graph p2p_g;

int main(){
	cin.tie(0)->sync_with_stdio(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out","w",stdout);
	
	cin>>test_pt>>n>>m>>d>>q;
	
	// 建s2p图 
	for(int i=1;i<=m;++i) cin>>ground_to_station[i];
	
	for(int i=1;i<=n;++i){
		int k;
		cin>>k;
		for(int j=1;j<=k;++j){
			int station, t;
			cin>>station>>t;
			station_paths[station].push_back({i, t});
		}
	}
	
	// 建p2p图 
	for(int i=1;i<=m;++i){
		for(int u=1;u<station_paths[i].size();++u){
			for(int v=0;v<u;++v){
				const auto& p1=station_paths[i][u];
				const auto& p2=station_paths[i][v];
				p2p_g.add_path(p1.dest, p2.dest, 0ll+p1.t+p2.t);
			}
		}
	}
	
	p2p_g.floyd();
	
	for(int i=1;i<=q;++i){
		int s, e;
		cin>>s>>e;
		
		ll ans = INF;
		for(const auto& p1: station_paths[s]){
			for(const auto& p2: station_paths[e]){
				ll dis = p1.t + p2p_g.dis[p1.dest][p2.dest] + p2.t;
				if(dis<ans){
					ans=dis;
//					cout<<p1.dest<<' '<<p2.dest<<' '<<p1.t <<' '<< p2p_g.dis[p1.dest][p2.dest]<<' '<<p2.t<<' '<<dis<<endl;
				}
//				ans=min(ans, );
			}
		}
		
//		cout<<ground_to_station[s]<<' '<<ans<<' '<<ground_to_station[e]<<endl;
		cout<<ground_to_station[s]+ans+ground_to_station[e]<<'\n';
	}
	
	return 0;
}

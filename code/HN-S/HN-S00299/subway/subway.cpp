#include <bits/stdc++.h>

#define pb push_back
#define fst first
#define sec second

using namespace std;

using ll = long long;
using ull =unsigned long long;
using i128 = __int128;
using p_q =priority_queue<pair<ll,int> >;

namespace sharweek{

const int N = 505,M = 5e5+50;
const ll inf = 1e18;
ll dis[N+M];
bool vis[N+M];
ll d2[N][N];
ll w1[M];
vector<pair<int,ll> > g[N+M];//i:line,N+i:station
p_q pq;

void mian(){
	int C,n,m,d,q;cin>>C>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w1[i];
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=1;j<=k;j++){
			int st;ll w;
			cin>>st>>w;
			g[i].pb({st+N,w});
			g[st+N].pb({i,w});
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) d2[i][j]=inf;
		d2[i][i]=0;
	}
	
	for(int i=1;i<=m;i++){
		for(pair<int,ll> qwq1:g[N+i]){
			for(pair<int,ll> qwq2:g[N+i]){
				int v1=qwq1.fst,v2=qwq2.fst;ll w=qwq1.sec,ww=qwq2.sec;
				if(v1==v2) continue;
				d2[v1][v2]=min(w+ww,d2[v1][v2]);
			}
		}
	}
	
	/*for(int s=1;s<=n;s++){
		//for(int i=N+1;i<=N+m;i++) dis[i]=inf,vis[i]=0;
		for(int i=1;i<=n;i++) dis[i]=inf,vis[i]=0;
		while(!pq.empty()) pq.pop();
		dis[s]=0;
		pq.push({0,s});
		while(!pq.empty()){
			int u=pq.top().sec;
			pq.pop();
			if(vis[u]) continue;
			vis[u]=1;
			for(int i=1;i<=n;i++){
				if(vis[i]) continue;
				if(d2[s][u]+d2[u][i]<d2[s][i]){
					d2[s][i]=d2[u][i]+d2[s][u];
					pq.push({-d2[s][i],i});
				}
			}
		}
	}*/
	
	for(int k=1;k<=n;k++){
		for(int j=1;j<=n;j++){
			for(int i=1;i<=n;i++){
				d2[i][j]=min(d2[i][j],d2[i][k]+d2[k][j]);
			}
		}
	}
	
	/*for(int s=1;s<=n;s++){
		for(int i=N+1;i<=N+m;i++) dis[i]=inf,vis[i]=0;
		for(int i=1;i<=n;i++) dis[i]=inf,vis[i]=0;
		while(!pq.empty()) pq.pop();
		dis[s]=0;
		pq.push({0,s});
		while(!pq.empty()){
			int u=pq.top().sec;
			pq.pop();
			if(vis[u]) continue;
			vis[u]=1;
			for(pair<int,ll> qwq:g[u]){
				int v=qwq.fst;ll w=qwq.sec;
				if(vis[v]) continue;
				if(dis[u]+w<dis[v]){
					dis[v]=dis[u]+w;
					pq.push({-dis[v],v});
				}
			}
		}
		for(int i=1;i<=n;i++){
			d2[s][i]=dis[i];
		}
	}
	*/
	while(q--){
		int x,y;cin>>x>>y;
		ll ans=w1[x] + w1[y],mn=inf;
		for(pair<int,ll> qwq1:g[N+x]){
			for(pair<int,ll> qwq2:g[N+y]){
				int v1=qwq1.fst,v2=qwq2.fst;ll w=qwq1.sec,ww=qwq2.sec;
				mn=min(mn,w+ww+d2[v1][v2]);
			}
		}
		cout<<ans+mn<<"\n";
	}
}

}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	int _=1;
	//cin>>_;
	while(_-->0){
		sharweek::mian();
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


0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

*/

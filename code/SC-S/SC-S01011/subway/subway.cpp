#include<bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
using ll=long long;
const int N=5e5+5,M=505;//范围修改！！！
const ll inf=1e18;
int c,n,m,d,Q,W[N],k[N];
unordered_map<int,int> a[M],t[M];
ll dis[M][M];
vector<pii>G[M];
vector<int> mp[N],to[N];
//struct question{
//	int s,t;
//}q[N];
void djkstra(int S){
	dis[S][S]=0;
	bitset<M>vis(0);
	priority_queue<pair<ll,int>> q;
	q.push({0,S});
	while(!q.empty()){
		int u=q.top().second;
		q.pop();
		if(!vis[u])vis[u]=1;
		else continue;
		for(int i=1;i<=k[u];++i){
			for(auto v:mp[a[u][i]]){
				if(dis[S][v]>dis[S][u]+t[u][a[u][i]]+t[v][a[u][i]]){
					dis[S][v]=dis[S][u]+t[u][a[u][i]]+t[v][a[u][i]];
					q.push({-dis[S][v],v});
				}
			}
		}
	}
	return;
}
void ini(){
	cin>>c>>n>>m>>d>>Q;
	for(int i=0;i<M;++i){
		for(int j=0;j<M;++j){
			dis[i][j]=inf;
		}
	}
	for(int i=1;i<=m;++i){
		cin>>W[i];
	}
	for(int i=1;i<=n;++i){
		cin>>k[i];
		for(int j=1;j<=k[i];++j){
			int o,p;
			cin>>o>>p;
//			cin>>a[i][j]>>t[i][a[i][j]];
			a[i][j]=o;t[i][a[i][j]]=p;
			mp[a[i][j]].push_back(i);
		}
	}
	for(int i=1;i<=n;++i)
		djkstra(i);
//	cout<<dis[1][1]<<" "<<dis[1][2]<<" "<<dis[2][2]<<" "<<dis[2][1]<<"\n";
//	for(int i=1;i<=Q;++i)
//		cin>>q[i].s>>q[i].t;
	return;
}
void solve(int S,int T){
	ll ans=inf;
	for(auto u:mp[S]){
		for(auto v:mp[T]){
			ans=min(ans,dis[u][v]+t[u][S]+t[v][T]);
		}
	}
	cout<<ans+W[S]+W[T]<<"\n";
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	ini();
	while(Q--){
		int S,T;
		cin>>S>>T;
		solve(S,T);
	}
	return 0;
}
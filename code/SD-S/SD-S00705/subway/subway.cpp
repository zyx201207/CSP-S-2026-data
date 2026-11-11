#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
const int N = 505,M = 5e5+5;
const i64 inf = 1e18;
int n,m,c,q,d,k[N];
i64 dis[N][N],w[M];
vector<pair<int,i64> > e[M];
int main(){
	freopen("subway.in","r",stdin);freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i = 1;i<=m;i++) cin>>w[i];
	for(int i = 1;i<=n;i++){
		cin>>k[i];
		for(int j = 1,v;j<=k[i];j++){
			i64 t;
			cin>>v>>t;
			e[v].emplace_back(i,t);
		}
	}
	for(int i = 1;i<=n;i++) for(int j = 1;j<=n;j++) dis[i][j] = inf;
	for(int i = 1;i<=n;i++) dis[i][i] = 0;
	for(int i = 1;i<=m;i++){
		for(auto pii : e[i]){
			int v1;i64 t1;tie(v1,t1) = pii;
			for(auto ppi : e[i]){
				int v2;i64 t2;tie(v2,t2) = ppi;
				dis[v1][v2] = min(dis[v1][v2],t1+t2);
			}
		}
	}
	for(int k = 1;k<=n;k++)
		for(int i = 1;i<=n;i++)
			for(int j = 1;j<=n;j++)
				dis[i][j] = min(dis[i][j] , dis[i][k] + dis[k][j]);
	for(int i = 1,u,v;i<=q;i++){
		cin>>u>>v;
		if(u == v){
			cout<<"0\n";
			continue;
		}
		i64 ans = 0,di = inf;
		ans += w[u]+w[v];
		for(auto pii : e[u]){
			int v1;i64 t1;tie(v1,t1) = pii;
			for(auto ppi : e[v]){
				int v2;i64 t2;tie(v2,t2) = ppi;
				di = min(di,dis[v1][v2] + t1+t2);
			}
		}
		ans += di;
		cout<<ans<<"\n";
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e2+10,M=5e5+10;
const int inf=1e18;
int n,m,D,Q;
int a[M];
vector<pair<int ,int > >e[N+M];
int ans[M];
int U[M],V[M];
int d[N+M],v[N+M];
void dij(int s){
	for(int i=1;i<=n+m;i++) d[i]=inf,v[i]=0;
	priority_queue<pair<int ,int > >que;
	d[s]=0;que.push({-d[s],s});
	while(que.size()){
		int x=que.top().second;que.pop();
		if(v[x]) continue;
		v[x]=1;
//		cerr<<x<<" "<<"Debug\n";
		for(auto now:e[x]){
			int y=now.first;
			int dis=now.second;
			if(d[y]>d[x]+dis){
//				cerr<<x<<' '<<y<<'\n';
				d[y]=d[x]+dis;
				que.push({-d[y],y});
			}
		}
	}
//	cerr<<"OK!\n";
}
void bfs(int s){
	for(int i=1;i<=n+m;i++) d[i]=inf,v[i]=0;
	queue<int >que;
	v[s]=1;d[s]=0;
	que.push(s);
	while(que.size()){
		int x=que.front();que.pop();
		for(auto now:e[x]){
			int y=now.first;
			int dis=now.second;
			if(v[y]) continue;
//			if(d[y]<=d[x]+dis) continue;
			v[y]=1;
			d[y]=d[x]+dis;
			que.push(y);
		}
	}
}
void solve(){
	int Case;cin>>Case;
	cin>>n>>m>>D>>Q;
	for(int i=1;i<=m;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=1;j<=k;j++){
			int x,t;cin>>x>>t;
			e[i].push_back({n+x,t});
			e[n+x].push_back({i,t});
//			cerr<<i<<' '<<n+x<<'\n';
		}
	}
	
	for(int i=1;i<=Q;i++) cin>>U[i]>>V[i],ans[i]=inf;
//	for(int i=1;i<=Q;i++) cerr<<U[i]<<' '<<V[i]<<'\n';
	for(int j=1;j<=n;j++){
		if(12<=Case&&Case<=19) bfs(j);
		else dij(j);
		for(int i=1;i<=Q;i++){
//			cerr<<U[i]<<' '<<V[i]<<'\n';
//			cerr<<n+U[i]<<' '<<n+V[i]<<'\n';
			ans[i]=min(ans[i],d[n+U[i]]+d[n+V[i]]);
		}
//		cerr<<"OK!\n";
	}
	for(int i=1;i<=Q;i++){
		ans[i]+=(a[U[i]]+a[V[i]]);
		cout<<ans[i]<<'\n';
	}
}
//void clear(){
//
//}
signed main(){
	ios::sync_with_stdio(false);cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int T;T=1;
	while(T--){
		solve();
//		clear();
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

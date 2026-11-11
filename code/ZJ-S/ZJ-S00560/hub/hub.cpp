#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PII pair<int,int>
const int N=1e5+5;
int n,k;
vector<int>g[N];
int dis[505][505];
bool vis[N];
int ok[N];
int ans=1e18;
void dfs(int u){
	for(auto v:g[u]){
		if(vis[v]||!ok[v]){
			continue;
		}
		vis[v]=1;
		dfs(v);
	}
}
void dijkstra(int st){
	dis[st][st]=0;
	priority_queue<PII,vector<PII>,greater<PII> >q;
	q.push({0,st});
	for(int i=1;i<=n;i++)vis[i]=0;
	while(!q.empty()){
		PII u=q.top();
		q.pop();
		if(vis[u.second])continue;
		vis[u.second]=1;
		for(auto v:g[u.second]){
			if(dis[st][v]>dis[st][u.second]+1){
				dis[st][v]=dis[st][u.second]+1;
				if(!vis[v]){
					q.push({dis[st][v],v});
				}
			}
		}
	}
}
void solve(){
	ans=1e18;
	cin>>n>>k;
	for(int i=1;i<=n;i++)g[i].clear();
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dis[i][j]=1e18;
		}
	}
	for(int i=1;i<=n;i++){
		dijkstra(i);
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout<<dis[i][j]<<' ';
//		}
//		cout<<"\n";
//	}
	for(int i=0;i<(1<<n);i++){
		if(__builtin_popcount(i)!=k){
			continue;
		}
		for(int j=1;j<=n;j++){
			if(i&(1<<(j-1)))ok[j]=1;
			else ok[j]=0;
		}
		for(int j=1;j<=n;j++)vis[j]=0;
		int cnt=0;
		for(int j=1;j<=n;j++){
			if(ok[j]&&!vis[j]){
				vis[j]=1;
				cnt++;
				dfs(j);
			}
		}
		if(cnt!=2)continue;
		int sum=0;
		for(int j=1;j<=n;j++){
			if(ok[j])continue;
			int mn=1e18;
			for(int l=1;l<=n;l++){
				if(!(i&(1<<(l-1))))continue;
				mn=min(mn,dis[j][l]);
			}
			sum=max(sum,mn);
		}
//		cout<<i<<" "<<sum<<"\n";
		ans=min(ans,sum);
	}
	cout<<ans<<"\n";
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int C,_;
	cin>>C>>_;
	while(_--){
		solve();
	}
	return 0;
}
/*
15pts


0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10
*/

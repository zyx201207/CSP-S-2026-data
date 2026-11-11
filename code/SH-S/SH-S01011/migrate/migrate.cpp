#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define pll pair<int,int> 
const int N=310;
int c,T,dis[N],x[N],ans,n,d,cnt[N];
vector<int> g[N];
void dijkstra(int s){
	for(int i=1;i<=n;i++) cnt[i]=1;
	for(int i=1;i<=n;i++) dis[i]=1e18+10;
	dis[s]=0;
	queue<int> q;
	q.push(s);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int i=0;i<g[u].size();i++) {
			int v=g[u][i];
			if(dis[v]>dis[u]+1) {
				dis[v]=dis[u]+1;
				q.push(v);
			}else if(dis[v]==dis[u]+1) cnt[v]++;
		} 
	}
//	cout<<s<<"\n";
	for(int i=1;i<=n;i++) {
//		cout<<cnt[i]<<" ";
		if(cnt[i]==2) ans++;
	}
//	cout<<'\n';
}
void solve(){
	ans=0;
	cin>>n>>d;
	for(int i=1;i<=n;i++) g[i].clear();
	for(int i=1;i<=n;i++) cin>>x[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i!=j) {
				if(abs(x[i]-x[j])<=d) g[i].push_back(j); 
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=0;j<g[i].size();j++){
//			int u=i,v=g[u][j].second,w=g[u][j].first;
//			cout<<u<<" "<<v<<" "<<w<<"\n";
//		}
//	} 
	for(int i=1;i<=n;i++) dijkstra(i);
	cout<<ans/2<<"\n";
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--) solve();
	return 0;
}
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

*/

#include<bits/stdc++.h>
#define N 200005
#define ll long long
using namespace std;
int n;
int c,T;
int k;
vector<int> g[N];
bool vis[N];
bool is[N];
int dis[N];
void dfs(int x,int f){
	vis[x]=1;
	for(auto i:g[x]){
		if(i==f or !is[i]) continue;
		dfs(i,x);
	}
}
void work(int x,int f,int d){
	dis[x]=min(dis[x],d);
	for(auto i:g[x]){
		if(i==f) continue;
		work(i,x,d+1);
	}
}
int main(){
	cin.tie(0),cout.tie(0),ios::sync_with_stdio(0);
	freopen("hub.in","r",stdin),freopen("hub.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		if(n<=10){
			int ans=1e9;
			for(int S=0;S<(1<<n);S++){
				if(__builtin_popcount(S)!=k) continue;
				for(int i=1;i<=n;i++) vis[i]=is[i]=0,dis[i]=10000;
				for(int j=0;j<n;j++){
					if(S>>j&1) is[j+1]=1;
				}
				int cnt=0;
				for(int j=1;j<=n;j++){
					if(is[j] and !vis[j]){
						dfs(j,0);
						++cnt;
					}
				}
				if(cnt>2) continue;
				for(int i=1;i<=n;i++){
					if(is[i]) work(i,0,0);
				}
				int res=0;
				for(int i=1;i<=n;i++){
					res=max(res,dis[i]);
				}
				ans=min(ans,res);
			}
			for(int i=1;i<=n;i++) g[i].clear();
			cout<<ans<<'\n';
		}
		else{
			cout<<n/4-k/2<<'\n';
		}
	}
	return 0;
}
/*
0 1
8 3
0 1 2 4 8 10 11 13
0 1
6 12
-10 -6 -2 2 6 10

*/
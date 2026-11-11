#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=1e5+5;
int c,t,n,k,dis[N],vis[N];
int mx,d;
vector<int>g[N];
void bfs(int s){
	memset(vis,0,sizeof vis);
	queue<int>q;
	vis[s]=1,dis[s]=0;
	q.push(s);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int i=0;i<g[u].size();i++){
			int v=g[u][i];
			if(vis[v]) continue;
			vis[v]=1,dis[v]=vis[u]+1;
			if(dis[v]>mx) mx=dis[v],d=v;
			q.push(v);
		}
	}
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<n;i++) {
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		mx=0;
		bfs(1);
		bfs(d);
		sort(dis+1,dis+1+n);
		cout<<max(dis[n]-2,dis[n-1])/2<<"\n";
	}
	return 0; 
}

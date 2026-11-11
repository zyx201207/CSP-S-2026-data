#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
int c,n,m,d,q;
int w[5*N];
vector<pair<int,int>>g[5*N];
vector<int>t[5*N];
int cnt, a[5*N];
int dis[5*N];
bool vis[5*N];
int dij(int s, int T){
	priority_queue<pair<int,int>,vector<pair<int,int>> ,greater<pair<int,int>>>q;
	for(int i=1;i<=cnt;i++) vis[i]=0, dis[i]=1000000000;
	for(auto i:t[s]){
		dis[i]=a[i];
		q.push({a[i],i});		
	}
	
	while(q.size()){
		auto x=q.top();
		q.pop();
		int u=x.second;
		if(vis[u]) continue;
		vis[u]=1;
		for(auto o:g[u]){
			int wx=o.second,v=o.first;
			if(wx+dis[u]<dis[v]){
				dis[v]=wx+dis[u];
				q.push({dis[v],v});
			}
		}
	}
	int ans=1000000000;
	for(auto i:t[T]){
		ans=min(ans,dis[i]+a[i]);
	}
	return ans;
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int u,x;
			cin>>u>>x;
			a[++cnt]=x;
			for(auto v:t[u]){
				g[cnt].push_back({v,a[v]+a[cnt]});
				g[v].push_back({cnt,a[v]+a[cnt]});
			}
			t[u].push_back(cnt);
			if(j>1){
				g[cnt-1].push_back({cnt,0});
				g[cnt].push_back({cnt-1,0});
			}
		}
	}
/*
	for(int i=1;i<=cnt;i++){
		for(auto v:g[i]){
			cout<<v<<' ';
		}		
		cout<<"\n";
	}
*/

	for(int i=1,u,v;i<=q;i++){
		cin>>u>>v;
		cout<<w[u]+w[v]+dij(u,v)<<"\n";			
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
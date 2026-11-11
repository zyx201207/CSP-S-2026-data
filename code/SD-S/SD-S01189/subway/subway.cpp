#include<bits/stdc++.h>
#define int long long
#define double long double
#define fi first
#define se second
#define pii pair<int,int>
#define endl '\n'
using namespace std;
const int N=6e5+5;
int c,n,m,d,q;
int w[N];
vector<pii>g[N];
int dis[N];
bool vis[N];
priority_queue<pii>pq;
int dij(int s,int t){
	for(int i=1;i<=n+m;i++){
		dis[i]=0x3f3f3f3f3f3f3f3f;
		vis[i]=0;
	}
	dis[s]=0;
	pq.push({0,s});
	while(pq.size()){
		int u=pq.top().se;
		pq.pop();
		if(vis[u])continue ;
		vis[u]=1;
		for(pii e:g[u]){
			int v=e.fi,ww=e.se;
			if(vis[v])continue ;
			if(dis[v]>dis[u]+ww){
				dis[v]=dis[u]+ww;
				pq.push({-dis[v],v});
			}
		}
	}
	return dis[t];
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k=0;
		cin>>k;
		for(int j=1;j<=k;j++){
			int u=0,ww=0;
			cin>>u>>ww;
			g[i+m].push_back({u,ww});
			g[u].push_back({i+m,ww});
		}
	}
	while(q--){
		int s=0,t=0;
		cin>>s>>t;
		cout<<dij(s,t)+w[s]+w[t]<<endl;
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

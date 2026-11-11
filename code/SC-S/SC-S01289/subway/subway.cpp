#define pii pair<int,int>
#include<bits/stdc++.h>
#define int long long
using namespace std;
vector<pii>G[1000010];
int w[500005],k[505],a[505][505],t[505][505],dis[500005],c,n,m,d,q;
int dij(int x,int y){
	priority_queue<pii,vector<pii>,greater<pii> >q;
	for(int i=1;i<=500000;i++)dis[i]=1e18;
	q.push({x+n,0});
	while(!q.empty()){
		int u=q.top().second;
		q.pop();
		for(pii x:G[u]){
			int v=x.first,ww=x.second;
			if(dis[u]+ww<dis[v])q.push({dis[v],v});
		}
	}return dis[y+n];
}
signed main(){
	freopen("subway.out","w",stdout);
	freopen("subway1.in","r",stdin);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
		G[i].push_back({i+n,w[i]});
		G[i+n].push_back({i,w[i]});
	}for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			G[i+n].push_back({j+n,t[i][j]});
			G[j+n].push_back({i+n,t[i][j]});
			G[i+2*n].push_back({i,0});
			G[i].push_back({i+2*n,0});
			G[j+2*n].push_back({i,0});
			G[j].push_back({j+2*n,0});
		}
	}while(q--){
		int x,y;
		cin>>x>>y;
		cout<<dij(x,y)<<'\n';
	}
	return 0;
}
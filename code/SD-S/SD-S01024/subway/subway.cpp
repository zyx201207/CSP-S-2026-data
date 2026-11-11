#include<bits/stdc++.h>
using namespace std;
#define ll long long
int c,n,m,d,q;
ll g[505][505],dis[505][505],vis[505],w[500005];
vector<pair<int,ll>> v[505],e[500005];
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int len;
		cin>>len;
		for(int j=1;j<=len;j++){
			int x,y;
			cin>>x>>y;
			v[i].push_back({x,y});
			e[x].push_back({i,y});
		}
	}
	memset(g,0x3f,sizeof g);
	memset(dis,0x3f,sizeof dis);
	for(int i=1;i<=n;i++) dis[i][i]=g[i][i]=0;
	for(int i=1;i<=m;++i){
		int l=e[i].size();
		for(int j=0;j+1<l;++j){
			for(int k=j+1;k<l;++k){
				int x=e[i][j].first,y=e[i][k].first;
				g[x][y]=g[y][x]=min(g[x][y],e[i][j].second+e[i][k].second);
			}
		}
	}
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof vis);
		priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
		q.push({0,i});
		while(!q.empty()){
			int x=q.top().second;q.pop();
			if(vis[x]) continue;
			vis[x]=1;
			for(int j=1;j<=n;j++){
				if(j==x) continue;
				if(dis[i][j]>dis[i][x]+g[x][j]){
					dis[i][j]=dis[i][x]+g[x][j];
					q.push({dis[i][j],j});
				}
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++) cout<<(dis[i][j]==0x3f3f3f3f3f3f3f3f?-1:dis[i][j])<<' ';
//		cout<<'\n';
//	}
	while(q--){
		int x,y;
		cin>>x>>y;
		int l=e[x].size(),le=e[y].size();
		ll ans=1e18;
		for(int j=0;j<l;++j){
			for(int k=0;k<le;++k){
				int u=e[x][j].first,v=e[y][k].first;
				ans=min(ans,e[x][j].second+e[y][k].second+dis[u][v]);
			}
		}
		cout<<ans+w[x]+w[y]<<'\n';
	}
	return 0;
}

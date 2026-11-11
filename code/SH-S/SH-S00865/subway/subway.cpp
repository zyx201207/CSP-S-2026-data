#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q,w[500005],k[505],in[2],t[505][20005],dis[505][505],vis[505],x,y,ans;
vector<int>a[20005];
vector<pair<int,int>>g[505];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>in[0]>>in[1];
			a[in[0]].push_back(i);
			t[i][in[0]]=in[1];
		}
	}
	for(int i=1;i<=m;i++){
		if(a[i].size()>=2){
			for(int j=0;j<a[i].size();j++){
				for(int k=j+1;k<a[i].size();k++){
					g[a[i][j]].push_back(make_pair(t[a[i][j]][i]+t[a[i][k]][i],a[i][k]));
					g[a[i][k]].push_back(make_pair(t[a[i][j]][i]+t[a[i][k]][i],a[i][j]));
				} 
			}
		}
	}
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof(vis));
		priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
		dis[i][i]=0;
		q.push(make_pair(0,i));
		while(!q.empty()){
			int u=q.top().second;
			q.pop();
			if(vis[u])continue;
			vis[u]=1;
			for(int j=0;j<g[u].size();j++){
				int v=g[u][j].second,l=g[u][j].first;
				if(dis[i][v]>dis[i][u]+l){
					dis[i][v]=dis[i][u]+l;
					q.push(make_pair(dis[i][v],v));
				}
			} 
		}
	} 
	while(q--){
		cin>>x>>y;
		ans=2e18;
		for(int i=0;i<a[x].size();i++){
			for(int j=0;j<a[y].size();j++){
				ans=min(ans,w[x]+w[y]+t[a[x][i]][x]+t[a[y][j]][y]+dis[a[x][i]][a[y][j]]);
			}
		} 
		cout<<ans<<'\n';
	} 
	return 0;
}

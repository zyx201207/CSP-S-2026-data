#include <bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,D,Q,w[500005],d[505][505],dis[505][505],vis[505];
vector<pair<int,int> >a[500005];
vector<int>g[500005];
struct node{
	int x,d;
	bool operator <(const node &t) const{
		return d>t.d;
	}
};
priority_queue<node>q;
void dijkstra(int x){
	q.push({x,0});
	dis[x][x]=0;
	vis[x]=1;
	while(!q.empty()){
		auto u=q.top();q.pop();
		for(int v=1;v<=n;v++){
			if(v==u.x)continue;
			if(dis[x][v]>dis[x][u.x]+d[u.x][v]){
				dis[v][x]=dis[x][v]=dis[x][u.x]+d[u.x][v];
				if(vis[v])continue;
				q.push({v,dis[x][v]});
				vis[v]=1;
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>D>>Q;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			d[i][j]=dis[i][j]=1e18;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1,k;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			int x,y;
			cin>>x>>y;
			a[x].push_back({i,y});
			g[i].push_back(x);
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<a[i].size();j++){
			for(int k=j+1;k<a[i].size();k++){
				d[a[i][j].first][a[i][k].first]=d[a[i][k].first][a[i][j].first]=
				min(d[a[i][k].first][a[i][j].first],a[i][j].second+a[i][k].second);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)vis[j]=0;
		dijkstra(i);
	}
	while(Q--){
		int x,y,ans=1e18;
		cin>>x>>y;
		for(auto u:a[x]){
			for(auto v:a[y]){
				ans=min(ans,u.second+w[x]+v.second+w[y]+dis[u.first][v.first]);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
//Could CCF give me 100pts on it?

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

#include<bits/stdc++.h>
#define int long long
//#define endl "\n"
using namespace std;
int c,m,n,d,q;
int w[500010];
pair<int,int> a[500010][21];
vector<pair<int,int>> g[501];//地铁线路算点 
int dis[501][501];
bool vis[501];
void dj(int s){
	for(int i=1;i<=n;i++){
		dis[s][i]=1e18;
		vis[i]=0;
	}
	dis[s][s]=0;
	priority_queue<pair<int,int>> q;
	q.push({0,s});
	while(!q.empty()){
		int u=q.top().second;
		q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(auto vw:g[u]){
			int v=vw.first,w=vw.second;
			if(dis[s][v]>dis[s][u]+w){
				dis[s][v]=dis[s][u]+w;
				q.push({-dis[s][v],v});
			}
		}
	}
	return ;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int ki;
		cin>>ki;
		for(int j=1;j<=ki;j++){
			int v,w;
			cin>>v>>w;
			a[v][0].first++;
			a[v][a[v][0].first]={i,w};
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=a[i][0].first;j++){
			for(int k=1;k<j;k++){
				g[a[i][j].first].push_back({a[i][k].first,a[i][j].second+a[i][k].second});
				g[a[i][k].first].push_back({a[i][j].first,a[i][j].second+a[i][k].second});
			}
		}
	}
	for(int i=1;i<=n;i++){
		dj(i);
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		int ans=1e18;
		for(int i=1;i<=a[x][0].first;i++){
			for(int j=1;j<=a[y][0].first;j++){
				ans=min(ans,dis[a[x][i].first][a[y][j].first]+a[x][i].second+a[y][j].second);
			}
		}
		cout<<ans+w[x]+w[y]<<endl;
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
fc subway.out subway
*/
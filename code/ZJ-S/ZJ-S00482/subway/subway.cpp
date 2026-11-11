#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int inf=1e18+7;
int c,n,m,d,q,w[500005],dis[505][505],dist[505005];
vector<pair<int,int> > v[505005];
bool vis[505005];
//void dijkstra(int x){
//	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
//	for(int i=1;i<=n+m;++i) dist[i]=inf,vis[i]=0;
//	dist[x]=0;
//	q.push({0,x});
//	while(!q.empty()){
//		pair<int,int> P=q.top();
//		q.pop();
//		int u=P.second;
//		vis[u]=1;
//		for(int i=0;i<v[u].size();++i){
//			int now=v[u][i].first;
//			if(!vis[now]&&dist[now]>dist[u]+v[u][i].second){
//				dist[now]=dist[u]+v[u][i].second;
//				q.push({dist[now],now});
//			}
//		}
//	}
//	for(int i=1;i<=n;++i){
//		dis[x-m][i]=dist[i+m];
//	}
//}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i) cin>>w[i];
	for(int i=1;i<=n;++i){
		int sz;
		cin>>sz;
		for(int j=1;j<=sz;++j){
			int x,y;
			cin>>x>>y;
			v[i+m].push_back({x,y});
			v[x].push_back({i+m,y});
		}
	}
//	for(int i=1;i<=n;++i){
//		dijkstra(i+m);
//	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			dis[i][j]=inf;
		}
		dis[i][i]=0;
	}
	for(int i=1;i<=m;++i){
		for(int j=0;j<v[i].size();++j){
			for(int k=0;k<v[i].size();++k){
				int x=v[i][j].first,y=v[i][k].first,xw=v[i][j].second,yw=v[i][k].second;
				dis[x-m][y-m]=min(dis[x-m][y-m],xw+yw);
			}
		}
	}
	for(int k=1;k<=n;++k){
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		int res=0,mn=inf;
		res+=(w[x]+w[y]);
		for(int i=0;i<v[x].size();++i){
			for(int j=0;j<v[y].size();++j){
				int nx=v[x][i].first,xw=v[x][i].second;
				int ny=v[y][j].first,yw=v[y][j].second;
				mn=min(mn,xw+yw+dis[nx-m][ny-m]);
			}
		}
		cout<<res+mn<<endl;
	}
	return 0;
}


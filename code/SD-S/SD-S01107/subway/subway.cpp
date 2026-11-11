#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e2+5,M=5e5+5,INF=1e18;
int w[M],k[N],dis[N][N];
vector<pair<int,int> >G[N];
map<int,int>t[N];
vector<int>E[M];
void dij(int s){
	dis[s][s]=0;
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >qu;
	qu.push({0,s});
	while(!qu.empty()){
		auto it=qu.top();
		qu.pop();
		int u=it.second,w=it.first;
		if(dis[s][u]!=w)continue;
		for(auto e:G[u]){
			int v=e.first,d=e.second;
			//cout<<v<<" "<<d<<"\n";
			if(dis[s][v]>dis[s][u]+d){
				dis[s][v]=dis[s][u]+d;
				qu.push({dis[s][v],v});
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	//cout<<"pppp";
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int a,x;
			cin>>a>>x;
			t[i][a]=x;
			for(auto v:E[a]){
				G[i].push_back({v,t[i][a]+t[v][a]});
				G[v].push_back({i,t[i][a]+t[v][a]});
			}
			E[a].push_back(i);
		}
	}
//	for(int i=1;i<=n;i++){
//		for(auto e:G[i]){
//			int v=e.first,d=e.second;
//			cout<<i<<" "<<v<<" "<<d<<"\n";
//		}
//	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dis[i][j]=INF;
		}
	}
	for(int i=1;i<=n;i++){
		dij(i);
	}
	//cout<<dis[1][2]<<" ";
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout<<dis[i][j]<<"\n";
//		}
//	}
	while(q--){
		int x,y;
		cin>>x>>y;
		int minn=INF;
		for(auto u:E[x]){
			for(auto v:E[y]){
				minn=min(minn,dis[u][v]+w[x]+t[u][x]+w[y]+t[v][y]);
			}
		}
		cout<<minn<<"\n";
	}
	return 0;
}

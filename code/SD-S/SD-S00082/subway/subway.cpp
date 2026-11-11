#include<bits/stdc++.h>
#define int long long
using namespace std;
const int INF=9e18;
const int M=5e5+10,N=5e2+10;
int c,n,m,d,q;
int w[M];
int k[N];
vector<pair<int,int>> nod[M];
vector<int> G0[N][N];
vector<pair<int,int>> G[N];
int disn[N][N];
bool vis[N];
int dis[N];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> qu;
void dji(int s){
	for(int i=1;i<=n;i++)vis[i]=0,dis[i]=INF;
	while(!qu.empty())qu.pop();
	qu.push({0,s});
	while(!qu.empty()){
		auto u=qu.top();
		qu.pop();
		if(!vis[u.second]){
			vis[u.second]=1,dis[u.second]=u.first;
			for(auto v:G[u.second]) qu.push({u.first+v.second,v.first});
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int ta,tt;
			cin>>c>>tt;
			nod[ta].push_back({i,tt});
		}
	}
	for(int i=1;i<=m;i++)for(auto u:nod[i])for(auto v:nod[i])if(u!=v)G0[u.first][v.first].push_back(u.second+v.second),G0[v.first][u.first].push_back(u.second+v.second);
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++){
			int minn=INF;
			for(auto u:G0[i][j])minn=min(minn,u);
			if(minn!=INF)G[i].push_back({j,minn}),G[j].push_back({i,minn});
		}
	}
	for(int i=1;i<=n;i++){
		dji(i);
		for(int j=1;j<=n;j++)disn[i][j]=dis[j];
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		int minn=INF;
		for(auto u:nod[x])for(auto v:nod[y])minn=min(minn,u.second+v.second+disn[u.first][v.first]);
		cout<<minn+w[x]+w[y]<<'\n';
	}
	return 0;
}

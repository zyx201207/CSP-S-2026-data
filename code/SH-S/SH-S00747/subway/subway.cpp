#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define int long long
int c,n,m,d,q;
const int maxn=5e5+5;//station max num
vector<pii>line[maxn];//the line station rely on and its cost
vector<pii>e[505];//graph on the lines
int dis[505][505];//min_dis betwen lines
int w[maxn];
bool vis[505];
void dij(int start){
	for(int i=1;i<=n;i++){
		dis[start][i]=1e18;
		vis[i]=0;
	}
	dis[start][start]=0;
	priority_queue<pii,vector<pii>,greater<pii>>q;
	q.push({0,start});
	while(!q.empty()){
		int d=q.top().first,u=q.top().second;
		q.pop();
		vis[u]=1;
		for(auto j:e[u]){
			int v=j.first,w=j.second;
			if(vis[v])continue;
			if(dis[start][u]+w<dis[start][v]){
				dis[start][v]=dis[start][u]+w;
				q.push({dis[start][v],v});
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];//don't forget to add w[i]+w[j]
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			line[a].push_back({i,t});
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dis[i][j]=1e18;
		}
	}for(int i=1;i<=n;i++)dis[i][i]=0;
	for(int i=1;i<=m;i++){
		for(int j=0;j<line[i].size()-1;j++){
			for(int k=j+1;k<line[i].size();k++){
				int dist=line[i][j].second+line[i][k].second;
				int u=line[i][j].first,v=line[i][k].first;
				if(dis[u][v]>dist){
					dis[u][v]=dis[v][u]=dist;
				}
			}
		}
	}
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			if(dis[i][j]!=1e18){
			//	cout<<i<<' '<<j<<':'<<dis[i][j]<<endl;
				e[i].push_back({j,dis[i][j]});
				e[j].push_back({i,dis[i][j]});
			}
		}
	}
	for(int i=1;i<=n;i++){
		dij(i);
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		int ans=1e18;
		for(auto xlt:line[x]){
			int xl=xlt.first,xlw=xlt.second;
			for(auto ylt:line[y]){
				int yl=ylt.first,ylw=ylt.second;
				ans=min(ans,dis[xl][yl]+xlw+ylw);
			}
		}cout<<ans+w[x]+w[y]<<'\n';
	}cout<<endl;
	return 0;
}

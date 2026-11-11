#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=505,M=500005;
const int inf=1e18;
const int D=22;
int c,n,m,d,q;
int dis[M*D];
int vis[D*M];
vector<pair<int,int> >g[M*D+2*M];
vector<pair<int,int> >tai[M];
void dij(int s){
	for(int i=1;i<=10000000;i++){
		dis[i]=inf;
		vis[i]=0;
	}
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >pq;
	dis[s]=0;
	pq.push({0,s});
	while(pq.size()){
		int u=pq.top().second;
		pq.pop();
		if(vis[u])continue;
		for(int i=0;i<g[u].size();i++){
			int v=g[u][i].first,w=g[u][i].second;
			if(dis[u]+w<dis[v]){
				dis[v]=dis[u]+w;
				pq.push({dis[v],v});
			}
		}
		vis[u]=1;
	}
}
int cnt;
pair<int,int> b[D*M];
int xian[D*M];
signed main(){
	freopen("subway1.in","r",stdin);
	freopen("subway1.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	vector<vector<int> >a(n+1,vector<int>(m+1)),t(n+1,vector<int>(m+1));
	vector<int>w(m+1),k(n+1);
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j]; //t[i][j]表示从这条线路在这个地铁站的的站台走到各个站厅 
			//a[i][j]表示这是哪一个地铁站 
			//第i条线路上a[i][j]是第几个 
			tai[a[i][j]].push_back({i,++cnt});  //在这个地铁站有哪些线路经过 ,cnt表示这是站台编号 
			
			xian[cnt]=i;//这个站台属于哪n一个线路 
			b[cnt]={a[i][j],j};
			//这个站台属于哪一个通地铁站 ,是线路中的第几个 
			g[cnt].push_back({a[i][j]+D*M,t[i][j]});
			g[a[i][j]+D*M].push_back({cnt,t[i][j]});
			if(j==1)continue;
			//各个站台之间 (费用为0)
			//g[cnt].push_back({cnt-1,0});
			g[cnt-1].push_back({cnt,0});  //1~m*n表示展台的点 
		}
	}
	//那么我们用M*D+1~M*D+m开始表示 站厅 
	while(q--){
		int x,y;
		cin>>x>>y; //
		dij(M*D+x);
		cout<<w[x]+w[y]+dis[M*D+y]<<endl;
	}
	return 0;
}

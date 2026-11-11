#include<bits/stdc++.h>
using namespace std;
#define int long long
int C;
int n,m,d,Q;
int w[1010];
bool sw[510][1010];
int ti[510][1010];
int e[1010][1010];
int dis[1010];
bool vis[1010];
int dij(int S,int T){
	for(int i=1;i<=m+2;i++)
		dis[i]=-1,vis[i]=false;
	dis[S]=0;
	priority_queue <pair<int,int> > q;
	q.push({0,S});
	while(!q.empty()){
		int u=q.top().second;
		q.pop();
		if(vis[u])	continue;
		vis[u]=true; 
		for(int i=1;i<=m+2;i++)
			if(e[u][i]!=-1&&(dis[i]==-1||dis[i]>dis[u]+e[u][i]))
				dis[i]=dis[u]+e[u][i],q.push({-dis[i],i});
	}
	return dis[T];
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	cin>>C>>n>>m>>d>>Q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1,k;i<=n;i++){
		cin>>k;
		for(int j=1,a,b;j<=k;j++)
			cin>>a>>b,sw[i][a]=true,ti[i][a]=b;
	}
	for(int i=1;i<=m+2;i++)
		for(int j=1;j<=m+2;j++)
			e[i][j]=-1;
	for(int i=1;i<=m;i++)
		for(int j=1;j<=m;j++)
			for(int a=1;a<=n;a++)
				if(sw[a][i]&&sw[a][j]&&(ti[a][i]+ti[a][j]<e[i][j]||e[i][j]==-1))
					e[i][j]=ti[a][i]+ti[a][j];
//	for(int i=1;i<=m;i++,cout<<"\n")
//		for(int j=1;j<=m;j++)
//			cout<<e[i][j]<<" ";
	int lstx=0,lsty=0;
	while(Q--){
		int x,y;
		cin>>x>>y;
		e[m+1][lstx]=-1;
		e[lsty][m+2]=-1;
		e[m+1][x]=w[x];
		e[y][m+2]=w[y];
		lstx=x,lsty=y;
		cout<<dij(m+1,m+2)<<"\n";
	}
	return 0;
}//Baixie 0513DTY
//32pts. 16:38

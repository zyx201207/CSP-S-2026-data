#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=505,M=2e4+5;
int c,n,m,d,q,w[M],kk[N],a[N][M],t[N][M],x,y;
int dis[M][N],vis[M][N],ans;
vector<pair<int,int> > b[M];
struct node{
	int to,xl,ww;
	bool friend operator>(const node&a,const node&b){
		return a.to<b.to;
	}
};
vector<node> g[M][N];
void dij(int sx){
	priority_queue<node,vector<node>,greater<node> > pq;
	memset(vis,0,sizeof vis);
	for(int i=1;i<=m;++i){
		for(int j=1;j<=n;++j) dis[i][j]=1e18;
	}
	for(int i=0;i<b[sx].size();++i){
		dis[sx][b[sx][i].first]=t[b[sx][i].first][b[sx][i].second];
		pq.push((node){t[b[sx][i].first][b[sx][i].second],b[sx][i].first,sx});
	}
	while(!pq.empty()){
		int qx=pq.top().ww,qxl=pq.top().xl;
		pq.pop();
		if(vis[qx][qxl]) continue;
		vis[qx][qxl]=1;
		for(int i=0;i<g[qx][qxl].size();++i){
			int zx=g[qx][qxl][i].to,zv=g[qx][qxl][i].xl,zw=g[qx][qxl][i].ww;
			if(dis[qx][qxl]+zw<dis[zx][zv]){
				dis[zx][zv]=dis[qx][qxl]+zw;
				pq.push((node){dis[zx][zv],zv,zx});
			}
		}
	}
	return ;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i) cin>>w[i];
	for(int i=1;i<=n;++i){
		cin>>kk[i];
		for(int j=1;j<=kk[i];++j){
			cin>>a[i][j]>>t[i][j];
			b[a[i][j]].push_back(make_pair(i,j));
			if(j==1) continue;
			g[a[i][j-1]][i].push_back((node){a[i][j],i,0});
		}
	}
	for(int i=1;i<=m;++i){
		for(int j=0;j<b[i].size()-1;++j){
			for(int k=j+1;k<b[i].size();++k){
				int i1=b[i][j].first,j1=b[i][j].second;
				int i2=b[i][k].first,j2=b[i][k].second;
				if(j2+1<=kk[i2]) g[i][i1].push_back((node){a[i2][j2+1],i2,t[i1][j1]+t[i2][j2]});
				if(j1+1<=kk[i1]) g[i][i2].push_back((node){a[i1][j1+1],i1,t[i1][j1]+t[i2][j2]});
			}
		}
	}
	while(q--){
		cin>>x>>y;
		dij(x);
		ans=1e18;
		for(int i=0;i<b[y].size();++i){
			int i1=b[y][i].first,j1=b[y][i].second;
			ans=min(ans,dis[y][i1]+t[i1][j1]);
		}
		cout<<w[x]+w[y]+ans<<'\n';
	}
	return 0;
}

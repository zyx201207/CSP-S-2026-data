// Why this year is so easy???????????????????????????

#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INF 0x3f3f3f3f3f3f3f3f
#define pi pair<int,int>
const int N=505+5;
const int M=5e5+5;
int cs,n,m,d,q;
int w[M];
int k[N];
vector<int>dt[M],dc[M],g[N],c[N];
int dis[N][N];
int vis[N];
void dij(int s){
	for(int i=1;i<=n;i++){
		vis[i]=0;
	}
	dis[s][s]=0;
	priority_queue<pi,vector<pi>,greater<pi>>pq;
	pq.push({0,s});
	while(!pq.empty()){
		int x=pq.top().second;
		pq.pop();
		if(vis[x]) continue;
		vis[x]=1;
	//	cout<<s<<' '<<x<<endl;
		for(int i=0;i<g[x].size();i++){
			int v=g[x][i];
			int ct=c[x][i];
		//	cout<<x<<' '<<v<<' '<<ct<<endl;
			if(dis[s][x]+ct<dis[s][v]){
				dis[s][v]=dis[s][x]+ct;
				pq.push({dis[s][v],v});
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin>>cs>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int xx,yy;
			cin>>xx>>yy;
			dt[xx].push_back(i);
			dc[xx].push_back(yy);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dis[i][j]=INF;
			if(i==j) dis[i][j]=0;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<dt[i].size();j++){
			for(int l=j+1;l<dt[i].size();l++){
			//	if(j==l) continue;
				int u=dt[i][j];
				int v=dt[i][l];
				int w=dc[i][l]+dc[i][j];
				g[u].push_back(v);
				g[v].push_back(u);
				c[u].push_back(w);
				c[v].push_back(w);
	//			dis[u][v]=dis[v][u]=min(dis[u][v],w);
			}
		}
	}
	for(int i=1;i<=n;i++){
		dij(i);
	}
/*	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<dis[i][j]<<' ';
		}
		cout<<'\n';
	}*/
	while(q--){
		int x,y;
		cin>>x>>y;
		int ans=w[x]+w[y];
		int res=INF;
		for(int i=0;i<dt[x].size();i++){
			int pl=dt[x][i];
			int jr=dc[x][i];
			for(int j=0;j<dt[y].size();j++){
				int pr=dt[y][j];
				int jl=dc[y][j];
				res=min(res,dis[pl][pr]+jr+jl);
			}
		}
		cout<<ans+res<<'\n';
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

*/

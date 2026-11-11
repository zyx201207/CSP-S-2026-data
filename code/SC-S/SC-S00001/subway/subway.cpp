#include<bits/stdc++.h>
using namespace std;
#define int long long
#define FILE "subway"
#define JUDGE
const int N=2e4+5,M=5e2+5,D=25;
int dw[N];
vector<pair<int,int>> g[N];
vector<int> sub[N][M];
int out[N][M];
int c,n,m,din,q;
const int N2=5e2+5;
int floyd[N2][N2];
int d[N];
bool vis[N],hshsub[M];
struct node{
	int dis,u,subway,from;
};
bool operator >(const node& a,const node& b){
	return a.dis>b.dis;
}
int dijkstra(int s,int t){
	memset(d,0x3f,sizeof d);
	memset(vis,0,sizeof vis);
	memset(hshsub,0,sizeof hshsub);
	priority_queue<node,vector<node>,greater<node>> q;
	d[s]=0,q.push({0,s,0,0});
	while(q.size()){
		int u=q.top().u,
			subway=q.top().subway,
			from=q.top().from,
			dis=q.top().dis;
		q.pop();
		if(vis[u] && subway==0) continue;
//		cout<<u<<' ';
		vis[u]=(subway==0);
		hshsub[subway]=1;
		if(subway!=0){
			for(auto v:sub[u][subway]){
				if(v==from) continue;
				q.push({dis,v,subway,u});
			}
			for(auto edge:g[u]){
				int su=edge.first;
				if(su!=subway) continue;
				if(d[u]>dis+edge.second){
					d[u]=dis+edge.second;
					q.push({dis+edge.second,u,0,0});
				}
			}
		}else{
			for(auto edge:g[u]){
				int su=edge.first;
				if(!hshsub[su]){
					q.push({dis+edge.second,u,su,0});
				}
			}
		}
	}
//	cout<<'\n';
//	for(int i=1; i<=m; i++){
//		cout<<d[i]<<' ';
//	}
//	cout<<'\n';
	return d[t];
}
signed main(){
	#ifdef JUDGE
	freopen(FILE ".in","r",stdin);
	freopen(FILE ".out","w",stdout);
	#endif
	cin>>c>>n>>m>>din>>q;
	for(int i=1; i<=m; i++){
		cin>>dw[i];
	}
	if(c<=11 && c>=7){
		memset(floyd,0x3f,sizeof(floyd));
		int k;
		for(int i=1; i<=n; i++){
			cin>>k;
			int u,v,d1,d2;
			if(k==1) cin>>u>>d1;
			if(k==2){
				cin>>u>>d1>>v>>d2;
				floyd[u][v]=min(d1+d2,floyd[u][v]);
				floyd[v][u]=min(d1+d2,floyd[v][u]);
			}
		}
		for(int i=1; i<=m; i++){
			for(int j=1; j<=m; j++){
				for(int k=1; k<=m; k++){
					if(k==j || i==j || k==i) continue;
					floyd[i][j]=min(floyd[i][k]+floyd[k][j],floyd[i][j]);
				}
			}
		}
//		for(int i=1; i<=m; i++){
//			for(int j=1; j<=m; j++){
//				cout<<floyd[i][j]<<' ';
//			}
//			cout<<'\n';
//		}
		while(q--){
			int x,y;
			cin>>x>>y;
			cout<<floyd[x][y]+dw[y]+dw[x]<<'\n';
		}
	}else if(c<=15){
		int k;
		for(int i=1; i<=n; i++){
			cin>>k;
			int u,v,t;
			if(k==1) cin>>u>>t;
			else if(k==2){
				cin>>u>>t;
				g[u].push_back({i,t});
				cin>>v>>t;
				g[v].push_back({i,t});
				sub[u][i].push_back(v);
				sub[v][i].push_back(u);
			}else{
				cin>>u>>t;
				g[u].push_back({i,t});
				v=u;
				for(int j=2; j<=k; j++){
					cin>>u>>t;
					sub[v][i].push_back(u);
					sub[u][i].push_back(v);
					g[u].push_back({i,t});
					v=u;
				}
			}
		}
		int x,y;
		while(q--){
			cin>>x>>y;
			cout<<dijkstra(x,y)+dw[x]+dw[y]<<'\n';
		}
	}
	#ifdef JUDGE
	fclose(stdin);
	fclose(stdout);
	#endif
	return 0;
}
/*
建边太难了啊啊啊啊啊啊啊 
根本没有这么难的CSP-S
-----------你只是怕了 
*/
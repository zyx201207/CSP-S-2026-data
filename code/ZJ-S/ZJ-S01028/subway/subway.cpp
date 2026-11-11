#include<bits/stdc++.h>
using namespace std;
#define PII pair<int,int>
const int N=505,M=5e5+5;
int c,n,m,d,q,k[N];
long long w[M],ans=INT_MAX;
long long dis[55][305][305];
vector<PII>G[N];
vector<PII>g[1005];
int vis[M];
int DIS[2][M]; 
signed main(){
/*
11 3 4 20 1111
0 0 0 0
2 1 3 2 1
2 1 2 4 1
2 3 2 4 0
*/
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	memset(dis,0x3f,sizeof dis);
	int mnpot=0;
	long long mnva=LLONG_MAX;
	for(int i=1;i<=n;i++){
		cin>>k[i];
		if(7<=c&&c<=11){
			int u,v,d1,d2;
			if(k[i]==2){
				cin>>u>>d1>>v>>d2;
				g[u].push_back({v,d1+d2});
				g[v].push_back({u,d1+d2});
			}else
				cin>>u>>d1;
			continue;
		}
		for(int j=1;j<=k[i];j++){
			int u,d;cin>>u>>d;
			if(i==1){
				vis[u]=d;
				DIS[1][u]=d; 
			}
			if(i==2)
				DIS[2][u]=d; 
			if(i==2&&vis[u]){
				if(vis[u]+d<mnva){
					mnva=vis[u]+d;
					mnpot=u;
				}
			} 
			G[i].push_back({u,d});
		}
		if(c<=6){
			for(int j=0;j<k[i];j++)
				for(int t=0;t<k[i];t++)
					if(j!=t)
						dis[i][G[i][j].first][G[i][t].first]=G[i][j].second+G[i][t].second;
		}
	}
	while(q--){
		int u,v;
		cin>>u>>v;
		ans=INT_MAX;
		if(c<=6){
			int d[305][305],mind[305][305],xx[305][305];
			memset(d,0x3f,sizeof d);
			memset(mind,0x3f,sizeof mind);
			for(int i=1;i<=m;i++)
				for(int j=1;j<=m;j++)
					for(int k=1;k<=n;k++){
						if(dis[k][i][j]<mind[i][j]){
							mind[i][j]=dis[k][i][j];
							xx[i][j]=k;
						}
					}
			for(int k=1;k<=m;k++)
				for(int i=1;i<=m;i++)
					for(int j=1;j<=m;j++){
							mind[i][j]=min(mind[i][k]+mind[j][k],mind[i][j]);
					}
			cout<<mind[u][v]+w[u]+w[v]<<'\n';
		}else if(7<=c&&c<=11){
			int d[1005];
			memset(d,0x3f,sizeof d);
			d[u]=0;queue<int>q;
			q.push(u);
			while(!q.empty()){
				int now=q.front();q.pop();
				for(auto nxt:g[now]){
					int v=nxt.first,dis=nxt.second;
					if(dis+d[now]<d[v]){
						d[v]=d[now]+dis;
						q.push(v);
					}
				}
			}
//			for(int i=1;i<=m;i++)
//				cout<<d[i]<<' ';
//			cout<<'\n';
			cout<<d[v]+w[u]+w[v]<<'\n';
		}else
			cout<<w[u]+w[v]+min(DIS[1][u]+DIS[2][v],DIS[2][u]+DIS[1][v])+mnva<<'\n';
	}
	return 0;
}

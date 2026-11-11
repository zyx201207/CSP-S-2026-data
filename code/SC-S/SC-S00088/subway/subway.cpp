#include<bits/stdc++.h>
using namespace std;
const int INF=1e9;
int c,n,m,d,q,sum;
int w[100005],a[505][505],t[505][505],k[505];
int dis[2505][2505];
int cnt[100005];
int f[2505][2505];
vector<vector<pair<int,int> > > g(505);
vector<vector<pair<int,int> > > h(1005);
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int u,v;
			cin>>u>>v;
			g[i].push_back({u,v});
			h[u].push_back({i,v});
			cnt[u]++;
		}
	}
	memset(dis,0x3f,sizeof dis);
	for(int i=1;i<=n;i++){
		for(int j=0;j<k[i];j++){
			int u=g[i][j].first,t=g[i][j].second;
			for(int l=j+1;l<k[i];l++){
				int v=g[i][l].first,s=g[i][l].second;
				dis[u][v]=dis[v][u]=min(dis[u][v],s+t);
				f[u][v]=f[v][u]=1;
			}
			dis[u][u]=0;
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		if(n==2){
			if(f[x][y]!=1){
				int v1=h[x][0].second;
				dis[x][y]=0;
				dis[x][y]+=v1;
				int vv1=h[y][0].second;
				dis[x][y]+=vv1;
				int in=INF;
				for(int i=1;i<=m;i++){
					if(cnt[i]==2){
						int v2=h[i][1].second,v11=h[i][0].second;
						int s=v2+v11;
						dis[x][y]=min(s+dis[x][y],dis[x][y]+in);
						in=0;
					}
				}
			}
		}
		sum=w[x]+w[y];
		cout<<dis[x][y]+sum<<'\n';
	}
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
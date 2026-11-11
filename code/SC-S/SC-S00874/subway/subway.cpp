#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=505,M=5e5+5;
const int INF=1e18;
int c,n,m,d,q,w[M],dis[N][N];
//vector<int>a[N],t[N];
vector<pair<int,int>>bel[M];
signed main(){
//	freopen("subway7.in","r",stdin);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j)continue;
			dis[i][j]=INF;
		}
	}
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
//		cin>>k[i];
//		a[i].resize(k[i]+1,0);
//		t[i].resize(k[i]+1,0);
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t; 
			bel[a].push_back({i,t});
		}
	}
	for(int i=1;i<=m;i++){
		int sz=bel[i].size();
		for(int u=0;u<sz;u++){
			for(int v=u+1;v<sz;v++){
				int uid=bel[i][u].first,uw=bel[i][u].second;
				int vid=bel[i][v].first,vw=bel[i][v].second;
				int dist=uw+vw;
				dis[uid][vid]=dis[vid][uid]=min(dis[uid][vid],dist);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=1;k<=n;k++){
				dis[i][j]=dis[j][i]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		int ans=INF;
		for(int i=0;i<bel[x].size();i++){
			for(int j=0;j<bel[y].size();j++){
				auto u=bel[x][i];
				auto v=bel[y][j];
				ans=min(ans,u.second+v.second+dis[u.first][v.first]);
			}
		}
		cout<<ans+w[x]+w[y]<<'\n';
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
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
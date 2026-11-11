#include<bits/stdc++.h>
#define int long long
using namespace std;
vector<pair<int,int>>e[600005];
int c[500005];
int dis[505][505];
int w[500005];
int cc,n,m,d,q;
signed main(){
//	system("fc subway.out subway7.ans"); 
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>cc>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=1;j<=k;j++){
			int aa,tt;
			cin>>aa>>tt;
			e[aa].push_back({i,tt});
		}
	}//cout<<111111<<endl;
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=m;i++){
		for(int j=0;j<e[i].size();j++){
			for(int k=0;k<e[i].size();k++){
				int u=e[i][j].first,v=e[i][k].first;
				dis[u][v]=min(dis[u][v],e[i][j].second+e[i][k].second);
			}
		}
	}
	for(int i=1;i<=n;i++)dis[i][i]=0;
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout<<dis[i][j]<<" ";
//		}cout<<endl;
//	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		int ans=1e18;
		for(int j=0;j<e[x].size();j++){
			for(int k=0;k<e[y].size();k++){
				ans=min(ans,dis[e[x][j].first][e[y][k].first]+e[x][j].second+e[y][k].second);
			}
		}
		cout<<ans+w[x]+w[y]<<'\n';
	}
	return 0;
}

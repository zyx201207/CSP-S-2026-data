#include<bits/stdc++.h>
#define N 505
#define M 500005
#define int long long
using namespace std;
int f[N][N],w[M],k[N];
vector<pair<int,int> > e[N]; 
vector<pair<int,int> > mp[M];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int a,t;
			cin>>a>>t;
			e[i].push_back({a,t});
			mp[a].push_back({i,t});
		}
	}
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=m;i++){
		for(int j=0;j<mp[i].size();j++){
			for(int k=0;k<mp[i].size();k++){
				if(j==k)continue;
				int u=mp[i][j].first;
				int v=mp[i][k].first;
				int w1=mp[i][j].second;
				int w2=mp[i][k].second;
				f[u][v]=min(f[u][v],w1+w2);
				f[v][u]=min(f[v][u],w1+w2);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j)f[i][j]=0;
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	while(q--){
		int u,v;
		cin>>u>>v;
		int ans=1e18;
		for(int i=0;i<mp[u].size();i++){
			for(int j=0;j<mp[v].size();j++){
				pair<int,int> x1,x2;
				x1=mp[u][i],x2=mp[v][j];
				ans=min(ans,w[u]+x1.second+w[v]+x2.second+f[x1.first][x2.first]);
			}
		}
		cout<<ans<<"\n";
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
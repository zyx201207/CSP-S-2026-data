#include<bits/stdc++.h>
using namespace std;
const int N=500+5,M=5e5+5;
const long long MAX=1e18;
int w[M];
long long g[N][N];
vector<pair<int,int> > t[M];
int main(){
	ios::sync_with_stdio(NULL);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int C,n,m,D,q;
	cin>>C>>n>>m>>D>>q;
	for (int i=1;i<=m;i++){
		cin>>w[i];
	}
	for (int i=1;i<=n;i++){
		int k;
		cin>>k;
		for (int j=1;j<=k;j++){
			int x,y;
			cin>>x>>y;
			t[x].push_back(make_pair(i,y));
		}
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			g[i][j]=MAX;
		}
		g[i][i]=0;
	}
	for (int i=1;i<=m;i++){
		for (int j=0;j<t[i].size();j++){
			for (int k=j+1;k<t[i].size();k++){
				int u=t[i][j].first,v=t[i][k].first;
				long long d=t[i][j].second+t[i][k].second;
				g[u][v]=min(g[u][v],d);
				g[v][u]=min(g[v][u],d);
			}
		}
	}
	for (int k=1;k<=n;k++){
		for (int u=1;u<=n;u++){
			for (int v=1;v<=n;v++){
				g[u][v]=min(g[u][v],g[u][k]+g[k][v]);
			}
		}
	}
	for (int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		long long ans=MAX;
		for (int j=0;j<t[x].size();j++){
			for (int k=0;k<t[y].size();k++){
				int st=t[x][j].first,ed=t[y][k].first;
				long long als=1ll*t[x][j].second+t[y][k].second+w[x]+w[y];
				ans=min(ans,als+g[st][ed]);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}

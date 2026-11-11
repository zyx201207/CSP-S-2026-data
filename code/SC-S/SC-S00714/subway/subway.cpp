#include<bits/stdc++.h>
#define M 500005
#define N 505
using namespace std;
int w[M];
vector<pair<int,int> > tuj[M];
long long dist[N][N];
signed main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++) {
		int ki;
		cin>>ki;
		for(int j=1;j<=ki;j++) {
			int a,t;
			cin>>a>>t;
			tuj[a].push_back({i,t});
		}
	}
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=n;j++) dist[i][j]=1000000000000000000ll;
		dist[i][i]=0;
	}
	for(int i=1;i<=m;i++) {
		for(int j=0;j<(int)tuj[i].size();j++) {
			for(int k=j+1;k<(int)tuj[i].size();k++) {
				int u=tuj[i][j].first,d1=tuj[i][j].second;
				int v=tuj[i][k].first,d2=tuj[i][k].second;
				dist[u][v]=min(dist[u][v],1ll*(d1+d2));
			}
		}
	}
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=n;j++) {
			dist[i][j]=min(dist[i][j],dist[j][i]);
		}
	}
	for(int k=1;k<=n;k++) {
		for(int i=1;i<=n;i++) {
			for(int j=1;j<=n;j++) {
				dist[i][j]=min(dist[i][k]+dist[k][j],dist[i][j]);
			}
		}
	}
	for(int i=1;i<=q;i++) {
		int x,y;
		cin>>x>>y;
		long long ans=1000000000000000000ll;
		for(auto p:tuj[x]) {
			for(auto q:tuj[y]) {
				int k1=p.first,p1=p.second;
				int k2=q.first,p2=q.second;
				if(k1>k2) swap(k1,k2);
				ans=min(ans,dist[k1][k2]+w[x]+w[y]+p1+p2);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
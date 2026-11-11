#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005];
vector<pair<int,int> > G[500005];
long long mp[505][505];
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1; i<=m; i++) cin>>w[i];
	for(int i=1; i<=n; i++) {
		int k;
		cin>>k;
		for(int j=1; j<=k; j++) {
			int x,y;
			cin>>x>>y;
			G[x].emplace_back(i,y);
		}
	}
	memset(mp,0x3f,sizeof mp);
	for(int i=1; i<=m; i++) {
		for(auto x:G[i]) {
			for(auto y:G[i]) {
				long long w=x.second+y.second;
				mp[x.first][y.first]=min(mp[x.first][y.first],w);
				mp[y.first][x.first]=min(mp[y.first][x.first],w);
			}
		}
	}
	for(int i=1; i<=n; i++) mp[i][i]=0;
	for(int k=1; k<=n; k++)
		for(int i=1; i<=n; i++)
			for(int j=1; j<=n; j++)
				mp[i][j]=min(mp[i][j], mp[i][k]+mp[k][j]);
	for(int i=1; i<=q; i++) {
		int x,y;
		cin>>x>>y;
		long long ans=1e18;
		for(auto xx:G[x])
			for(auto yy:G[y])
				ans=min(ans,0ll+xx.second+yy.second+mp[xx.first][yy.first]);
		cout<<ans+w[x]+w[y]<<'\n';
	}
	return 0;
}
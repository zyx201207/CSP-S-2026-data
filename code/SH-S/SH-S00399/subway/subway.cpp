#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,n,m,d,q,w[500009];
ll dis[509][509];
vector<pair<int,ll> > v[500009];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) {
		cin>>w[i];
	}
	for(int i=1;i<=n;i++) {
		int k;
		cin>>k;
		for(int j=1;j<=k;j++) {
			int x,y;
			cin>>x>>y;
			v[x].push_back({i,y});
		}
	}
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=n;i++) {
		dis[i][i]=0;
	}
	for(int i=1;i<=m;i++) {
		for(int j=0;j<v[i].size();j++) {
			for(int k=0;k<j;k++) {
				dis[v[i][j].first][v[i][k].first]=min(dis[v[i][j].first][v[i][k].first],v[i][j].second+v[i][k].second);
				dis[v[i][k].first][v[i][j].first]=min(dis[v[i][k].first][v[i][j].first],v[i][j].second+v[i][k].second);
			}
		}
	}
	for(int k=1;k<=n;k++) {
		for(int i=1;i<=n;i++) {
			for(int j=1;j<=n;j++) {
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
//	for(int i=1;i<=m;i++) {
//		for(int j=0;j<v[i].size();j++) {
//			cout<<v[i][j].first<<" "<<v[i][j].second<<" ";
//		}
//		cout<<"\n";
//	}
//	for(int i=1;i<=n;i++) {
//		for(int j=1;j<=n;j++) {
//			cout<<dis[i][j]<<" ";
//		}
//		cout<<"\n";
//	}
	for(int i=1;i<=q;i++) {
		int x,y;
		cin>>x>>y;
		ll ans=0x3f3f3f3f3f3f3f3f;
		for(int j=0;j<v[x].size();j++) {
			for(int k=0;k<v[y].size();k++) {
				//cout<<v[x][j].first<<" "<<v[y][k].first<<"\n";
				ans=min(ans,dis[v[x][j].first][v[y][k].first]+w[x]+w[y]+v[x][j].second+v[y][k].second);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
//15:25

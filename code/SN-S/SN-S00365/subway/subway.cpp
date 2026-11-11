/*
西安辅轮中学
韩谦益 
SN-S00365
*/
#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500010];
int k[510];
vector<int> a[510];
vector<int> t[510];
long long dis[510][510];
vector<pair<int,int> > e[500010];
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i = 1;i<=m;i++) {
		cin>>w[i];
	}
	for(int i = 1;i<=n;i++) {
		cin>>k[i];
		for(int j = 1;j<=k[i];j++) {
			int ta,tt;
			cin>>ta>>tt;
			a[i].push_back(ta);
			t[i].push_back(tt);
			pair<int,int> tp;
			tp.first = i;
			tp.second = tt;
			e[ta].push_back(tp);
		}
	}
	for(int i = 1;i<=n;i++) {
		for(int j = 0;j<k[i];j++) {
			int u = a[i][j];
			for(int ii = 0;ii<e[u].size();ii++) {
				int v = e[u][ii].first;
				int w = e[u][ii].second;
				if(v == i) {
					continue;
				}
				dis[i][v] = dis[v][i] = t[i][j]+w;
			}
		}
	}
	for(int k = 1;k<=n;k++) {
		for(int i = 1;i<=n;i++) {
			for(int j = 1;j<=n;j++) {
				if(dis[i][k] == 0 || dis[j][k] == 0) {
					continue;
				}
				if(i == j) {
					continue;
				}
				if(dis[i][j] == 0) {
					dis[i][j] = dis[i][k]+dis[k][j];
					continue;
				}
				dis[i][j] = min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	for(int i = 1;i<=n;i++) {
		dis[i][i] = 0;
	}
	while(q--) {
		int x,y;
		cin>>x>>y;
		long long ans = 1000000000000000000;
		for(int i = 0;i<e[x].size();i++) {
			for(int j = 0;j<e[y].size();j++) {
				ans = min(ans,dis[e[x][i].first][e[y][j].first]+e[x][i].second+e[y][j].second);
			}
		}
		ans+=w[x]+w[y];
		cout<<ans<<"\n"; 
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q;
const int maxn=505;
const int maxmm=1005;
const int inf=1e18+7;
const int D=25;
int w[maxmm];
int a[maxmm],t[maxmm];
vector< pair<int,int> > edge[maxmm];
int dis[maxmm][maxmm];
bool vis[maxmm];
void dij(int x) {
	for(int i=1; i<=m; i++) {
		dis[x][i]=inf;
		vis[i]=0;
	}
	priority_queue< pair<int,int>, vector< pair<int,int> >, greater< pair<int,int> > > que;
	que.push({0,x});
	dis[x][x]=0;
	while(que.size()) {
		pair<int,int> u=que.top();
		que.pop();
		if(vis[u.second]) continue;
		vis[u.second]=1;
		for(auto v:edge[u.second]) {
			if(dis[x][v.first]>u.first+v.second) {
				dis[x][v.first]=u.first+v.second;
				que.push({dis[x][v.first],v.first});
			}
		}
	}
}
signed main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1; i<=m; i++) cin>>w[i];
	if(c<=11) {
		for(int i=1; i<=n; i++) {
			int x;
			cin>>x;
			for(int j=1; j<=x; j++)
				cin>>a[j]>>t[j];
			for(int j=1; j<=x; j++) {
				for(int k=j+1; k<=x; k++) {
					edge[a[j]].push_back({a[k],t[j]+t[k]});
					edge[a[k]].push_back({a[j],t[j]+t[k]});
				}
			}
		}
		for(int i=1; i<=m; i++)
			dij(i);
		while(q--) {
			int x,y;
			cin>>x>>y;
			cout<<w[x]+w[y]+dis[x][y]<<"\n";
		}
	}

	return 0;
}
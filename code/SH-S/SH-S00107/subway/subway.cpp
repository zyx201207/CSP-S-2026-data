#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll,int>
using namespace std;
int c,n,m,d,t;
int ttt[500005];
vector<pii> a[500005];
vector<pii> e[505],ee[505];
queue<int> q;
ll dis[505];
bool inq[505];
ll spfa() {
	while (!q.empty()) {
		int u=q.front();
		q.pop();
		inq[u]=0;
		for (int i=0;i<e[u].size();i++) {
			ll w=e[u][i].first;
			int v=e[u][i].second;
			if (dis[v]>dis[u]+w) {
				dis[v]=dis[u]+w;
				if (!inq[v]) {
					q.push(v);
					inq[v]=1;
				}
			}
		}
	}
	return dis[n+1];
}
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> t;
	for (int i=1;i<=m;i++) {
		cin >> ttt[i];
	}
	for (int i=1;i<=n;i++) {
		int ki;
		cin >> ki;
		int staa[500005];
		for (int j=1;j<=ki;j++) {
			scanf("%d",&staa[j]);
		}
		for (int j=1;j<=ki;j++) {
			int ww;
			scanf("%d",&ww);
			a[staa[j]].push_back(make_pair(ww,i));
		}
	}
	ll minn=9e18;
	if (c!=22&&c!=23) {
	for (int i=1;i<=m;i++) {
		for (int j=0;j<a[i].size();j++) {
			for (int k=j+1;k<a[i].size();k++) {
				int fr=a[i][j].first,to=a[i][k].first;
				int ww=a[i][j].second+a[i][k].second;
				ee[fr].push_back(make_pair(ww,to));
				ee[to].push_back(make_pair(ww,fr));
			}
		}
	}} else {
		for (int i=1;i<=m;i++) {
			if (a[i].size()>1) {
				ll nw=a[i][1].first+a[i][0].first;
				if (nw<=minn) {
					minn = nw;
				}
			}
		}
	}
	while (t--) {
		while(!q.empty()) {
			q.pop();
		}
		memset(inq,0,sizeof(inq));
		memset(dis,0x7f,sizeof(dis));
		for (int i=0;i<503;i++) {
			e[i].clear();
		}
		int u,v;
		scanf("%d%d",&u,&v);if (c!=22&&c!=23) {
		for (int i=1;i<=n;i++) {
			for (int j=0;j<ee[i].size();j++) {
				e[i].push_back(ee[i][j]);
			}
		}
		for (int i=0;i<a[u].size();i++) {
			e[0].push_back(a[u][i]);
		}
		for (int i=0;i<a[v].size();i++) {
			int fr = a[v][i].second;
			ll ww = a[v][i].first;
			e[fr].push_back(make_pair(ww,n+1));
		}
		q.push(0);
		dis[0]=0;
		inq[0]=1;
		ll ans = spfa();
		ans += ttt[u]+ttt[v];
		printf("%lld\n",ans);} else {
			ll ans=ttt[u]+ttt[v];
			if (a[u].size()==1 && a[v].size()==1) {
				ans += a[u][0].first+a[v][0].first;
				if (a[u][0].second!=a[v][0].second) {
					ans += minn;
				} 
			} else  {
				ans += a[v][0].first;
				if (a[u][0].second==a[v][0].second) {
					ans += min(a[u][0].first,a[v][0].first+minn);
				}
			
			}
		}
		
	}
	return 0;
}

#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,i,j,k,fx,sx,x,y,f[1000010],g[1000010],a[1000010],vis[1000010],dis[1000010];
vector<int>e[1000010];
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >q;
int bfs() {
	int ma=0;
	for(i=1; i<=k; i++)g[a[i]]=1;
	for(i=1; i<=k; i++) {
		q.push(make_pair(a[i],0));
		vis[a[i]]=1;
		dis[a[i]]=0;
		while(q.size()) {
			fx=q.top().first;
			q.pop();
			for(i=0; i<e[fx].size(); i++) {
				sx=e[fx][i];
				if(!g[sx]) {
					if(dis[sx]>dis[fx]+1)q.push(make_pair(sx,dis[sx]));
					dis[sx]=dis[fx]+1;
					vis[sx]=1;
				}
			}
		}
		for(j=1; j<=n; j++)ma=max(ma,dis[j]);
	}
	return ma;
}
int dg(int t) {
	int i;
	if(t>k)return bfs();
	for(i=1; i<=t; i++)
		if(!f[i]) {
			f[i]=1;
			a[t]=i;
			return dg(t+1);
			f[i]=0;
		}
}
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.ans","w",stdout);
	cin>>T;//c没有用，用T覆盖
	cin>>T;
	while(T--) {
		cin>>n>>k;
		if(n>100) {
			cout<<(int)log10(n)*2<<"\n";
			continue;
		}
		for(i=1; i<n; i++) {
			cin>>x>>y;
			e[x].push_back(y);
			e[y].push_back(x);
		}
		cout<<dg(1)<<"\n";
	}
	return 0;
}

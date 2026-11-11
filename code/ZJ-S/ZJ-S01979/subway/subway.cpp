#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#define int long long
using namespace std;
int n,m,d,Q,c,i,x,y,z,j,w[500010],dis[500010],vis[500010];vector<int>f[500010],g[500010];
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >q;
int dijkstra(int s,int t){
	for(int i=1;i<=m;i++) dis[i]=2e18,vis[i]=0;
	dis[s]=w[s];q.push({w[s],1});
	while(q.size()){
		int fx=q.top().second,fy=q.top().first;q.pop();
		if(vis[fx]) continue;
		vis[fx]=1;
		for(int i=0;i<f[fx].size();i++){
			int sx=f[fx][i],sy=fy+g[fx][i]+w[sx]*2;
			if(dis[sx]>sy) dis[sx]=sy,q.push({sy,sx});
		}
	}
	return dis[t]-w[t];
}
main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>Q;
	for(i=1;i<=m;i++) cin>>w[i];
	for(i=1;i<=n;i++){
		cin>>x;
		for(j=1;j<=x;j++) cin>>y>>z,f[i].push_back(y),g[i].push_back(z);
	}
	while(Q--) cin>>x>>y,cout<<dijkstra(x,y)<<"\n";
	return 0;
}

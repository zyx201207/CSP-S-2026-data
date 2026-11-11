#include <bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q,i,t,x,y,dn,dis[1000510],j,vis[1000510];
vector<pair<int,int> > f[1000510];
void dij(int w){
	int i,u,l,x,y;
	priority_queue<pair<int,int>,vector<pair<int,int> > ,greater<pair<int,int> > > q;
	for(i=1;i<=t;i++) vis[i]=0,dis[i]=1e18;
	dis[w]=0;
	q.push(make_pair(0,w));
	while(!q.empty()){
		u=q.top().second;
		q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		l=f[u].size();
		for(i=0;i<=l-1;i++){
			x=f[u][i].first;
			y=f[u][i].second;
			
			if(dis[x]>dis[u]+y){
				dis[x]=dis[u]+y;
				q.push(make_pair(dis[x],x));
			}
		}
		
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>m>>n>>d>>q;
	t=n;
	for(i=1;i<=n;i++){
		t++;
		cin>>x;
		f[i].push_back(make_pair(t,x));
		f[t].push_back(make_pair(i,x));
	}
	for(i=1;i<=m;i++){
		cin>>dn;
		t++;
		for(j=1;j<=dn;j++){
			cin>>x>>y;
			f[n+x].push_back(make_pair(t,y));
			f[t].push_back(make_pair(n+x,y));
		}
	}
	while(q--){
		cin>>x>>y;
		dij(x);
		cout<<dis[y]<<"\n";
	}
	return 0;
}
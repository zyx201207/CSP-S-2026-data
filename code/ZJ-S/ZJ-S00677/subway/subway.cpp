#include <bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q,w[500010],i,k,a[500010],t[500010],dis[500010],vis[500010],j,x,y,l;
vector<int> f[500010],g[500010];
void dij(int x){
	int fx,fy,sx,sy,i;
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
	while(q.size()) q.pop();
	memset(dis,127,sizeof(dis));
	memset(vis,0,sizeof(vis));
	dis[x]=0;
	q.push({0,x});
	while(q.size()){
		fx=q.top().second;fy=dis[fx];q.pop();
		if(vis[fx]) continue;vis[fx]=1;
		for(i=0;i<f[fx].size();i++){
			sx=f[fx][i];sy=g[fx][i];
			if(fy+sy<dis[sx])
				dis[sx]=fy+sy,q.push({dis[sx],sx});
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(i=1;i<=m;i++) cin>>w[i];
	for(i=1;i<=n;i++){
		cin>>k;
		for(j=1;j<=k;j++) cin>>a[j]>>t[j];
		for(j=1;j<=k;j++)
			for(l=j+1;l<=k;l++){
				f[a[l]].push_back(a[j]),g[a[l]].push_back(t[j]+t[l]);
				f[a[j]].push_back(a[l]),g[a[j]].push_back(t[j]+t[l]);
			}
	}
	while(q--){
		cin>>x>>y;
		dij(x);
		cout<<dis[y]+w[x]+w[y]<<"\n";
	}
	return 0;
}
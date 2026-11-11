#include<bits/stdc++.h>
#define N 500010
#define int long long
using namespace std;
int c,n,m,d,j,i,kk,x,y,T,dis[N],vis[N],k[N],w[N],a[N],t[N];
vector<int>f[N],g[N];priority_queue<pair<int,int>,
vector<pair<int,int> >,greater<pair<int,int> > >q;
int DIJ(int x,int y){
	int i,fx,sx,sy;
	for(i=1;i<=m;i++)dis[i]=1e18,vis[i]=0;
	q.push(make_pair(0ll,x));dis[x]=0;
	while(!q.empty()){
		fx=q.top().second;q.pop();
		if(vis[fx]==1)continue;
		vis[fx]=1;
		for(i=0;i<f[fx].size();i++){
			sx=f[fx][i];sy=g[fx][i];
			if(dis[fx]+sy<dis[sx]){
				dis[sx]=dis[fx]+sy;
				q.push(make_pair(dis[sx],sx));
			}
		}
	}
	return dis[y];
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>T;
	for(i=1;i<=m;i++)cin>>w[i];
	for(i=1;i<=n;i++){
		cin>>k[i];
		for(j=1;j<=k[i];j++)cin>>a[j]>>t[j];
		for(j=1;j<=k[i];j++)
			for(kk=2;kk<=k[i];kk++)f[a[j]].push_back(a[kk]),
			g[a[j]].push_back(t[j]+t[kk]),f[a[kk]].push_back(a[j]),
			g[a[kk]].push_back(t[j]+t[kk]);
	}
	while(T--){
		cin>>x>>y;
		cout<<DIJ(x,y)+w[x]+w[y]<<"\n";
	}
}
//by wild cat
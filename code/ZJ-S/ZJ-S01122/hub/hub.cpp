#include <bits/stdc++.h>
#define int long long
using namespace std;
int c,T,n,k,mii,i,x,y,mi[1000010],gs,g[1000010],vis[1000010],dis[1000010],b[1000010],js[1000010];
vector<pair<int,int> > f[1000010];
void dij(int w){
	int i,u,l,x,y;
	priority_queue<pair<int,int>,vector<pair<int,int> > ,greater<pair<int,int> > > q;
	for(i=1;i<=n;i++) vis[i]=0,dis[i]=1e18;
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
void sc(int t){
	int i,l,x;
	js[t]=1;
	l=f[t].size();
	for(i=0;i<=l-1;i++){
		x=f[t][i].first;
		if(js[x]) continue;
		if(g[x]) sc(x); 
	}
}
void dfs(int t){
	int i,j,ma=0;
	if(t==k+1){
		gs=0;
		for(i=1;i<=k;i++) if(!js[b[i]]) sc(b[i]),gs++;
		for(i=1;i<=n;i++) js[i]=0;
		if(gs>2) return ;
		for(i=1;i<=n;i++) mi[i]=1e18;
		for(i=1;i<=k;i++){
			dij(b[i]);
			for(j=1;j<=n;j++) mi[j]=min(mi[j],dis[j]);
		}
		for(i=1;i<=n;i++) ma=max(ma,mi[i]);
		mii=min(mii,ma);
		return ;
	}
	for(i=1;i<=n;i++)
		if(!g[i]){
			g[i]=1;
			b[t]=i;
			dfs(t+1);
			g[i]=0;
		}
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>k;mii=1e18;
		for(i=1;i<=n;i++) f[i].clear();
		for(i=1;i<=n-1;i++){
			cin>>x>>y;
			f[x].push_back(make_pair(y,1));
			f[y].push_back(make_pair(x,1));
		}
		dfs(1);
		for(i=1;i<=n;i++) g[i]=0;
		cout<<mii<<"\n";
	}
	return 0;
}
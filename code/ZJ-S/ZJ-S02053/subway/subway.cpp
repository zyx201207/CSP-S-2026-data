#include <bits/stdc++.h>
#define int long long
#define P pair<int,int>
using namespace std;
const int N=6e5+5;
int c,n,m,d,q,w[N],dis[N],vis[N],di[1505][1505],vi[1505],ans[N],vv[N],T;
vector<P> g[10*N];
void dj(int s){
	priority_queue<P,vector<P>,greater<P>> q;
	memset(dis,0x3f,sizeof dis);
	memset(vis,0,sizeof vis);
	q.push({0,s});
	dis[s]=0;
	while(q.size()){
		int u=q.top().second;q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(auto t:g[u]){
			int v=t.first,w=t.second;
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				q.push({dis[v],v});
			}
		}
	}
}
void djs(int s){
	priority_queue<P,vector<P>,greater<P>> q;
	memset(vi,0,sizeof vi);
	q.push({0,s});
	di[s][s]=0;
	while(q.size()){
		int u=q.top().second;q.pop();
		if(vi[u]) continue;
		vi[u]=1;
		for(auto t:g[u]){
			int v=t.first,w=t.second;
			if(di[s][v]>di[s][u]+w){
				di[s][v]=di[s][u]+w;
				q.push({di[s][v],v});
			}
		}
	}
}
void bfs(int x,int y){
	memset(ans,0,sizeof ans);
	memset(vv,0,sizeof vv);
	queue<int> q;
	q.push(x);
	vv[x]=1;
	while(q.size()){
		int u=q.front();q.pop();
		for(auto t:g[u]){
			int v=t.first;
			if(vv[v]==0){
				ans[v]=ans[u]+1,vv[v]=1;
				q.push(v);
			}
		}
		if(ans[y]!=0){
			cout<<w[x]+ans[y]*T+w[y]<<"\n";
			return;
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i) cin>>w[i];
	for(int i=1,k;i<=n;++i){
		cin>>k;
		for(int j=1,a,t;j<=k;++j){
			cin>>a>>t;
			g[i+m].push_back({a,t});
			g[a].push_back({i+m,t});
			T=t;
		}
	}
	if(c==9||c==10||c==11){
		memset(di,0x3f,sizeof di);
		for(int i=1;i<=n+m;++i) djs(i);
		for(int i=1,x,y;i<=q;++i){
			cin>>x>>y;
			cout<<w[x]+di[x][y]+w[y]<<"\n";
		}
	}
	else if(c==12||c==13||c==14||c==15){
		for(int i=1,x,y;i<=q;++i){
			cin>>x>>y;
			bfs(x,y);
		}
	}
	else{
		for(int i=1,x,y;i<=q;++i){
			cin>>x>>y;
			dj(x);
			cout<<w[x]+dis[y]+w[y]<<"\n";
		}
	}
}

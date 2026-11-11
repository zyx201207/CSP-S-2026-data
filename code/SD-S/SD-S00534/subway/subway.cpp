#include<bits/stdc++.h>
#define fi first
#define se second
#define PII pair<long long,int>
#define ll long long
using namespace std;
int to[1000005],nxt[1000005],frt[1000005],val[1000005],vis[1000005],idx,n,m,q;
ll dis[505][30005];
inline void add_edge(int x,int y,int z){
	to[++idx]=y;
	nxt[idx]=frt[x];
	frt[x]=idx;
	val[idx]=z;
}
void dij(int id){
	for(int i=1;i<=n+m;++i){
		vis[i]=0;
		dis[id-m][i]=1e18;
	} 
	dis[id-m][id]=0;
	priority_queue<PII,vector<PII>,greater<PII> >q;
	q.push({0,id});
	while(!q.empty()){
		PII x=q.top();
		q.pop();
		if(vis[x.se]) continue ;
		vis[x.se]=1;
		for(int i=frt[x.se];i;i=nxt[i]){
			int j=to[i];
			if(dis[id-m][j]<=dis[id-m][x.se]+val[i]) continue ;
			dis[id-m][j]=dis[id-m][x.se]+val[i];
			q.push({dis[id-m][j],j});
		}
	}
}
void bfs(int id){
	deque<int>q;
	q.push_back(id);
	for(int i=1;i<=n+m;++i) vis[i]=0;
	dis[id-m][id]=0;
	while(!q.empty()){
		int x=q.front();
		q.pop_front();
		if(vis[x]) continue ;
		vis[x]=1;
		for(int i=frt[x];i;i=nxt[i]){
			int j=to[i];
			if(dis[id-m][j]<=dis[id-m][x]+val[i]) continue ;
			dis[id-m][j]=dis[id-m][x]+val[i];
			if(!val[i]){
				q.push_front(j);
			}
			else{
				q.push_back(j);
			}
		}
	}
}
inline void solve2(){
	for(int i=m+1;i<=n+m;++i){
		dij(i);
	}
}
inline void solve1(){
	for(int i=m+1;i<=n+m;++i){
		bfs(i);
	}
}
int a[500005];
inline void solve(int C){
	int d;
	cin>>n>>m>>d>>q;
	for(int i=1;i<=m;++i){
		cin>>a[i];
	} 
	for(int i=1;i<=n;++i){
		int k;
		cin>>k;
		for(int j=1;j<=k;++j){
			int x,y;
			cin>>x>>y;
			add_edge(x,m+i,y);
			add_edge(m+i,x,y); 
		}
	}
	if(C>=12&&C<=19){
		solve1();
	}
	else {
		solve2();
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		ll ans=1e18;
		for(int i=m+1;i<=n+m;++i){
			ans=min(ans,dis[i-m][x]+dis[i-m][y]);
		} 
		cout<<ans+a[x]+a[y]<<'\n';
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int C,t=1;
	cin>>C;
	while(t--){
		solve(C);
	}
	return 0;
}



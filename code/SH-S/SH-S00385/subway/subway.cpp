#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=505,M=5e5+5;
struct node{
	int v,t;
};
int c,n,m,d,q;
int w[M];
vector<node>a[M];
int A[M][3]; 
int g[N][N];
int dis[N][N];
vector<int>bel[M];
void add(int i,int v,int t){
	for(node u:a[v]){
		g[u.v][i]=max(g[u.v][i],u.t+t);
	}
	return;
}
struct upd{
	int u,ds;
	bool operator > (const upd &a)const{
		return ds>a.ds;
	}
};
bool vis[N];
void dij(int s){
	priority_queue<upd,vector<upd>,greater<upd> >q;
	for(int i=0;i<=n+1;i++) vis[i]=0;
	q.push({s,0});
	dis[s][s]=0;
	while(!q.empty()){
		int u=q.top().u;
		q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(int v=1;v<=n;v++){
			if(g[u][v]>0){
				if(dis[s][v]>dis[s][u]+g[u][v]){
					dis[s][v]=dis[s][u]+g[u][v];
					q.push({v,dis[s][v]});
				}
			}
		}
	}
	return;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int v,t;
			cin>>v>>t;
			a[v].push_back({i,t});
			bel[v].push_back(i);
			add(i,v,t);
			
			
		}
	}
	memset(dis,0x3f,sizeof dis);
	for(int u=1;u<=n;u++){
		dij(u);
	}
	for(int u=1;u<=n;u++){
		for(int v=1;v<=n;v++){
			dis[u][v]=min(dis[u][v],dis[v][u]);
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		int ans=w[x]+w[y],mn=1e17;
		for(node u:a[x]){
			for(node v:a[y]){
				mn=min(mn,u.t+v.t+dis[u.v][v.v]);
			}
		}
		cout<<ans+mn<<'\n';
	}
	return 0;
}


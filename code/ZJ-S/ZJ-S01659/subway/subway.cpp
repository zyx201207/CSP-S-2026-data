#include<bits/stdc++.h>
#define int long long 
#define pb push_back

using namespace std;

const int N=2005,M=2e4+5,inf=1e18,QY=1e5+5;
int c,n,m,d,q,idx,w[N];
int dis[N][M];
vector<int> qry;
struct node{
	int v,w;
	bool operator<(node o)const{
		return w>o.w;
	}
};
struct Qry{
	int s,t;
}Q[QY];
vector<node> g[N];
void add(int u,int v,int w){
	g[u].pb({v,w});
	g[v].pb({u,w});
}
void dij(int s){
	for(int i=1;i<=n+m;i++) dis[s][i]=inf;
	priority_queue<node> q;	
	q.push({s,0});dis[s][s]=0;
	while(!q.empty()){
		node it=q.top();q.pop();
		int u=it.v,disu=it.w;
		if(disu!=dis[s][u]) continue;
		for(node ed:g[u]){
			int v=ed.v,w=ed.w;
			if(dis[s][v]>dis[s][u]+w){
				dis[s][v]=dis[s][u]+w;
				q.push({v,dis[s][v]});
			}
		}
	}
}
int32_t main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>m>>n>>d>>q;
	for(int i=1;i<=n;i++) cin>>w[i];
	for(int i=1;i<=m;i++){
		int k;cin>>k;
		int now=i+n;
		while(k--){
			int x,t;cin>>x>>t;
			add(now,x,t);
		}
	}
	for(int i=1;i<=q;i++){
		int s,t;cin>>s>>t;
		Q[i]={s,t};
		qry.pb(s);
	}
	for(int x:qry){
		dij(x);
	}
	for(int i=1;i<=q;i++){
		int s=Q[i].s,t=Q[i].t;
		cout<<w[s]+w[t]+dis[s][t]<<"\n";
	}
}
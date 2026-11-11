#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;
const int MAXN=5e5+7;
const ll INF=1e18;
bool vis[MAXN];
int c,n,m,d,q,k,x,y,a,t;
int hd[MAXN],nxt[2*MAXN],to[2*MAXN],cnt=0;
ll val[MAXN],dis[MAXN],wi[2*MAXN];

void add(int u,int v,int w){
	to[++cnt]=v;
	wi[cnt]=w;
	nxt[cnt]=hd[u];
	hd[u]=cnt;
}

void dijkstra(int s){
	for(int i=1;i<=n+m;++i){
		vis[i]=false,dis[i]=INF;
	}
	priority_queue<pii,vector<pii>,greater<pii>> p;
	dis[s]=0;
	p.push({0,s});
	while(!p.empty()){
		pii tmp=p.top();
		p.pop();
		int u=tmp.second;
		if(vis[u]) continue;
		vis[u]=true;
		for(int i=hd[u];~i;i=nxt[i]){
			int v=to[i],w=wi[i];
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				p.push({dis[v],v});
			}
		}
	}
}

void work(){
	cin>>x>>y;
	dijkstra(x);
	cout<<val[x]+dis[y]+val[y]<<'\n';
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	memset(hd,-1,sizeof(hd));
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i) cin>>val[i];
	for(int i=1;i<=n;++i){
		
		cin>>k;
		for(int j=1;j<=k;++j){
			cin>>a>>t;
			add(a,m+i,t),add(m+i,a,t);
			
		}
	}
	while(q--) work();
	return 0;
}
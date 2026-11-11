//SN-S00283 Aapwp gxyz
#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+10;
int c,n,m,d,T,w[maxn],a[maxn];
struct edge{
	int to,nxt,val;
}e[10000005];
int head[maxn],edgenum;
void add_edge(int u,int v,int w){
	e[++edgenum].nxt=head[u];
	e[edgenum].to=v;
	e[edgenum].val=w;
	head[u]=edgenum;
}

int cnt=0;
map<pair<int,int>,int> mp;
#define mk make_pair
inline int id(int x,int y){
	if(mp[mk(x,y)]==0) mp[mk(x,y)]=++cnt;
	return mp[mk(x,y)]; 
}

bool vis[maxn];
int dis[maxn];
struct node{
	int pos,dis;
	bool operator < (const node &x)const{
		return x.dis<dis;	
	}
};
priority_queue<node> q;
void dij(int x){
	for(int i=1;i<=cnt;i++){
		dis[i]=2e9,vis[i]=0;
	}
	dis[x]=0;
	q.push((node){x,0});
	while(!q.empty()){
		node tmp=q.top();
		q.pop();
		int u=tmp.pos;
		if(vis[u]) continue;
		vis[u]=1;
		for(int i=head[u];i;i=e[i].nxt){
			int v=e[i].to;
			if(dis[v]>dis[u]+e[i].val){
				dis[v]=dis[u]+e[i].val;
				if(!vis[v]) q.push((node){v,dis[v]});
			}
		}	
	}
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>T;
	
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1,k;i<=n;i++){
		cin>>k;
		for(int j=1,t;j<=k;j++){
			cin>>a[j]>>t;
			if(j>=2){
				add_edge(id(i,a[j-1]),id(i,a[j]),0);
				add_edge(id(i,a[j]),id(i,a[j-1]),0);
			}
			add_edge(id(i,a[j]),id(0,a[j]),t),add_edge(id(0,a[j]),id(i,a[j]),t);
		}
	}
	while(T--){
		int x,y;
		cin>>x>>y;
		dij(id(0,x));
		cout<<dis[id(0,y)]+w[x]+w[y]<<'\n';
	}
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

*/

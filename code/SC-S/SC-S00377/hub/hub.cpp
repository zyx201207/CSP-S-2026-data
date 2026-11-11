#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define fi first
#define se second
using namespace std;
const int maxn=1000;
int n,k;
struct node{
	int to,next;
}e[2*maxn];
int head[maxn],tot;
void add(int u,int v){
	e[++tot].to=v;
	e[tot].next=head[u];
	head[u]=tot;
}
bitset<maxn> vis,st;
int ans=1e18;
int fa[maxn],siz[maxn];
int find(int x){
	if(fa[x]==x) return fa[x];
	return fa[x]=find(fa[x]);
}
void merge(int u,int v){
	u=find(u),v=find(v);
	if(u==v) return;
	if(siz[u]<siz[v]) swap(u,v);
	siz[u]+=siz[v]; fa[v]=u;
}
void Dfs(int u,int f){
	for(int i=head[u];i;i=e[i].next){
		int v=e[i].to;
		if(v==f) continue;
		if(vis[u]&&vis[v]) merge(u,v);
		Dfs(v,u);
	}
}

struct qnode{
	int u,w;
	bool operator<(const qnode& other)const{
		return w>other.w;
	}
};
void dij(int s,int dis[]){
	st.reset();
	fill(dis+1,dis+n+1,1e18);
	priority_queue<qnode> pq;
	pq.push({s,0}); dis[s]=0;
	while(!pq.empty()){
		qnode qn=pq.top(); pq.pop();
		if(st[qn.u]) continue;
		st[qn.u]=1;
		for(int i=head[qn.u];i;i=e[i].next){
			int v=e[i].to;
			if(dis[v]>dis[qn.u]+1){
				dis[v]=dis[qn.u]+1;
				pq.push({v,dis[v]});
			}
		}
	}
} 
int dis[maxn][maxn];
int d[maxn];
int calc(){
	memset(d,0x3f,sizeof(d));
	for(int i=1;i<=n;i++) fa[i]=i,siz[i]=1;
	Dfs(1,0);
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(fa[i]==i&&vis[i]) cnt++;
	}
	if(cnt>2) return 1e18;
	for(int i=1;i<=n;i++) dij(i,dis[i]);
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		for(int j=1;j<=n;j++){
			if(i==j||!vis[j]) continue;
			d[i]=min(d[i],dis[i][j]);
		}
	}
	int res=0;
	for(int i=1;i<=n;i++){
		if(!vis[i]) res=max(res,d[i]);
	}
	return res;
}
void dfs(int x,int cnt){
	if(cnt==k){
		ans=min(ans,calc());
		return;
	}
	if(x==n+1) return;
	vis[x]=1; dfs(x+1,cnt+1);
	vis[x]=0; dfs(x+1,cnt);
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t; cin>>c>>t;
	while(t--){
		ans=1e18;
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int u,v; cin>>u>>v;
			add(u,v); add(v,u);
		}
		dfs(1,0);
		cout<<ans<<endl;
		memset(head,0,sizeof(int)*(n+1)); tot=0;
		vis.reset();
	}
	return 0;
}
/*
今天已经打了 3 遍最短路了…… 

16：52 15pts 
*/
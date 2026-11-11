#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=505,M=5e5+5;
int c,n,m,d,q;
int w[M];
int k[N];
vector<int> p[M];//p:每个点有哪些线路经过
vector<ll> s[M];
struct edge{
	int nxt,to;
	ll w;
	
}e[M<<1];
struct node{
	int p;
	ll w;
	bool operator > (const node &x) const{
		return w>x.w;
	}
};
ll dis[N][N];
int h[N],cnt;
void add(int u,int v,ll w){
	e[++cnt].nxt=h[u];
	e[cnt].to=v;
	e[cnt].w=w;
	h[u]=cnt;
}
priority_queue<node,vector<node>,greater<node> > pq;
bool vis[N];
void dijk(int s){
	memset(vis,0,sizeof(vis));
	dis[s][s]=0;
	pq.push({s,0});
	while(!pq.empty()){
		int u=pq.top().p;
		pq.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(int i=h[u];i;i=e[i].nxt){
			int v=e[i].to,w=e[i].w;
			if(dis[s][u]+w<dis[s][v]){
				dis[s][v]=dis[s][u]+w;
				pq.push({v,dis[s][v]});
			}
		}
	}
}
ll ans;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int a,t;
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a>>t;
			p[a].push_back(i);
			s[a].push_back(t);
		}
	}
	for(int i=1;i<=m;i++){
		if(p[i].size()==1) continue;
		for(int j=0;j<p[i].size();j++)
			for(int k=0;k<p[i].size();k++){
				if(j==k) continue;
				add(p[i][j],p[i][k],s[i][j]+s[i][k]);
			}
	}
	memset(dis,0x7f,sizeof(dis));
	for(int i=1;i<=n;i++){
		dijk(i);
	}
	for(int i=1;i<=q;i++){
		ans=LONG_LONG_MAX;
		int x,y;
		cin>>x>>y;
		for(int j=0;j<p[x].size();j++)
			for(int k=0;k<p[y].size();k++){
				if(p[x][j]!=p[y][k]) ans=min(dis[p[x][j]][p[y][k]]+s[x][j]+s[y][k],ans); 
				else ans=min(s[x][j]+s[y][k],ans);
			}
		cout<<w[x]+w[y]+ans<<"\n";
	}
	return 0;
}


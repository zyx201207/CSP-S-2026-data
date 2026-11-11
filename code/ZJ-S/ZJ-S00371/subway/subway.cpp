#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5,M=505;
const ll inf=1e18;
ll c,m,n,d,q,w1[N],dis[N],f[N][21],dep[N],len[N],vis[N+M],tot,ans;
vector<ll>a,t;
struct pp{int v;ll w;};
vector<pp>p[N],p1[N+M];
struct node{
	ll ind,w;
	bool operator < (const node&other)const{
		return w>other.w;
	}
};
priority_queue<node>q1;
void dijkstra(ll s,ll y){
	fill(dis+1,dis+1+n,inf);
	dis[s]=0;
	q1.push({s,dis[s]});
	while(!q1.empty()){
		ll u=q1.top().ind;
		q1.pop();
		for(pp i:p[u]){
			if(dis[i.v]!=inf)continue;
			if(dis[i.v]>dis[u]+i.w){
				dis[i.v]=dis[u]+i.w;
				if(i.v==y)return;
				q1.push({i.v,dis[i.v]});
			}
		}
	}
}
void work1(){
	while(q--){
		ll x,y;
		cin>>x>>y;
		dijkstra(x,y);
		cout<<dis[y]+w1[x]+w1[y]<<'\n';
	}
	exit(0);
}
void dfs(ll x,ll fa){
	f[x][0]=fa,dep[x]=dep[fa]+1;
	for(int i=1;i<20;i++)
		f[x][i]=f[f[x][i-1]][i-1];
	for(pp i:p[x]){
		if(i.v==fa)continue;
		len[i.v]=len[x]+i.w;
		dfs(i.v,x);
	}
}
ll lca(ll x,ll y){
	if(dep[x]>dep[y])swap(x,y);
	for(int i=19;i>=0;i--)
		if(dep[f[y][i]]>=dep[x])
			y=f[y][i];
	if(x==y)return x;
	for(int i=19;i>=0;i--)
		if(f[y][i]!=f[x][i])
			x=f[x][i],y=f[y][i];
	return f[x][0];
}
void work2(){
	dfs(1,0);
	while(q--){
		ll x,y;
		cin>>x>>y;
		ll now=lca(x,y);
		cout<<w1[x]+w1[y]+len[x]+len[y]-len[now]*2<<'\n';
	}
	exit(0);
}
void bfs(int x,int y){
	queue<pp>q;
	q.push({x,0});
	vis[x]=++tot;
	while(!q.empty()){
		int u=q.front().v;
		ll val=q.front().w;
		q.pop();
		for(pp i:p1[u]){
			if(vis[i.v]==tot)continue;
			if(i.v==y){
				ans=w1[x]+w1[y]+(val+1)*i.w;
				return;
			}
			q.push({i.v,val+1});
			vis[i.v]=tot;
		}
	}
}
void work3(){
	for(int i=1,k;i<=m;i++){
		cin>>k;
		for(int j=1,aa,tt;j<=k;j++){
			cin>>aa>>tt;
			p1[n+i].push_back({aa,tt});
			p1[aa].push_back({n+i,tt});
		}
	}
	while(q--){
		ll x,y;
		cin>>x>>y;
		bfs(x,y);
		cout<<ans<<'\n';
	}
	exit(0);
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>m>>n>>d>>q;
	for(int i=1;i<=n;i++)cin>>w1[i];
	if(c<=15&&c>11)work3();
	for(int i=1,k;i<=m;i++){
		cin>>k;
		for(int j=1,aa,tt;j<=k;j++){
			cin>>aa>>tt;
			a.push_back(aa);
			t.push_back(tt);
		}
		for(int j=0;j<k;j++){
			for(int l=j+1;l<k;l++){
				p[a[j]].push_back({a[l],t[j]+t[l]});
				p[a[l]].push_back({a[j],t[j]+t[l]});
			}
		}
		a.clear(),t.clear();
	}
	if(c<=8)work1();
	else if(c<=11)work2();
	else work1();
}

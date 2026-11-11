#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=510;//线路数 
const ll M=5e5+10;//站数
const ll M1=5e5+510;
ll c,n,m,d,q; 
ll w[M];
struct nod{
	ll a,t;
};vector<nod> aa[N];
ll tot;
struct edge{
	ll v,w;
};vector<edge> e[M1];
void add(ll u,ll v,ll w){
	e[u].push_back({v,w});
}
struct node1{
	ll u,v,w;
}bian[M*20];
ll mm=0,fa[M1],dep[M1],de[M1];
bool cmp1(node1 a,node1 b){
	return a.w<b.w;
}
ll Find(ll x){
	if(fa[x]==x) return x;
	return fa[x]=Find(fa[x]);
}
ll f[M1][21],h;
void dfs(ll u,ll p){
	f[u][0]=p;
	for(auto i:e[u]){
		if(i.v==p) continue;
		dep[i.v]=dep[u]+1,de[i.v]=de[u]+i.w;
		dfs(i.v,u);
	}
}
void init(){
	h=log2(tot);
	for(ll j=1;j<=h;j++)
		for(ll i=1;i<=tot;i++) f[i][j]=f[f[i][j-1]][j-1];
}
ll LCA(ll x,ll y){
	if(dep[x]<dep[y]) swap(x,y);
	for(ll i=h;i>=0;i--) if(dep[f[x][i]]>=dep[y]) x=f[x][i];
	if(x==y) return x;
	for(ll i=h;i>=0;i--) if(f[x][i]!=f[y][i]) x=f[x][i],y=f[y][i];
	return f[x][0]; 
}
void solve1(){
	tot=m;
	for(ll i=1;i<=n;i++){
		tot++;
		for(auto x:aa[i]){
			bian[++mm]={tot,x.a,x.t};
		}
	}
	for(ll i=1;i<=tot;i++) fa[i]=i;
	sort(bian+1,bian+mm+1,cmp1);
	ll cnt=0;
	for(ll i=1;i<=mm;i++){
		ll x=bian[i].u,y=bian[i].v,w=bian[i].w;
		ll fx=Find(x),fy=Find(y);
		if(fx==fy) continue;
		add(x,y,w);add(y,x,w);
		fa[fx]=fy;cnt++;
		if(cnt==tot-1) break; 
	}
	dfs(1,0);
	init();
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++) cin>>w[i];
	for(ll i=1;i<=n;i++){
		ll k;cin>>k;
		for(ll j=1;j<=k;j++){
			ll a,t;cin>>a>>t;
			aa[i].push_back({a,t});
		}
	}
	solve1();
	for(ll i=1;i<=q;i++){
		ll x,y;cin>>x>>y;
		ll p=LCA(x,y);
		cout<<w[x]+w[y]+de[x]+de[y]-de[p]*2<<'\n';
	}
	return 0;
}

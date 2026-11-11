#include<bits/stdc++.h>
using namespace std;
#define re register
#define ll long long
#define forl(i,a,b) for(re ll i=a;i<=b;i++)
#define forr(i,a,b) for(re ll i=a;i>=b;i--)
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define pb push_back
#define x first
#define y second
ll n,m,x,y,c;
vector<ll>G[1000010];
ll dep[1000010],f[1000010][20];
void Dfs(ll x,ll fa){
	f[x][0]=fa;
	dep[x]=dep[fa]+1;
	for(auto i:G[x]) if(i!=fa) Dfs(i,x);
}
ll lca(ll x,ll y){
	if(dep[x]<=dep[y]) swap(x,y);
	forr(i,19,0) if(dep[f[x][i]]>=dep[y]) x=f[x][i];
	if(x==y) return x;
	forr(i,19,0) if(f[x][i]!=f[y][i]) x=f[x][i],y=f[y][i];
	return f[x][0];
}
ll dis(ll x,ll y){
	return dep[x]+dep[y]-dep[lca(x,y)]*2;
}
ll id[1000010];
ll find(ll x){
	if(x==id[x]) return id[x];
	return id[x]=find(id[x]);
}
ll b[1000010],g[20][20];
void merge(ll x,ll y){
	id[find(x)]=find(y);
}
ll minn;
void chk(){
	forl(i,1,n) id[i]=i;
	forl(i,1,n) for(auto j:G[i]) if(b[i] && b[j]) merge(i,j);
	ll S=0;
	forl(i,1,n) if(b[i]) S+=find(i)==i;
	if(S>2) return ;
	vector<ll>v;
	forl(i,1,n) if(b[i]) v.pb(i);
	ll maxn=0;
	forl(i,1,n) if(!b[i]){
		ll mi=1e18;
		for(auto j:v) mi=min(mi,g[i][j]);
		maxn=max(maxn,mi);
	}
	minn=min(minn,maxn);
}
void Dfs2(ll x,ll y){
	if(y>m) return ;
	if(x==n+1){
		chk();
		return ;
	}
	b[x]=0,Dfs2(x+1,y);
	b[x]=1,Dfs2(x+1,y+1);
	b[x]=0;
}
ll ma,rt;
ll h[1000010],vis[1000010];
void Dfs3(ll x,ll fa){
	for(auto i:G[x]) if(i!=fa) Dfs3(i,x),vis[x]|=vis[i];
}
vector<ll>G2[1000010];
ll d[1000010];
void Dfs4(ll x,ll fa){
	d[x]=d[fa]+1;
	for(auto i:G2[x]) if(i!=fa) Dfs4(i,x);
}
bool chk(ll Mid){
	if(ma-1<=Mid) return 1;
	ll p=rt;
	forl(i,1,Mid) p=f[p][0];
	ll pd=0;
	forl(i,1,n) vis[i]=dis(i,p)>Mid,pd|=vis[i];
	if(!pd) return 1;
	Dfs3(1,0);
//	return 0;
	forl(i,1,n) G2[i].clear(),d[i]=0;
	forl(i,1,n) for(auto j:G[i]) if(vis[i] && vis[j] && i<j) G2[i].pb(j),G2[j].pb(i);
//	return 0;
	Dfs4(1,0);
//	return 0;
	ll Ma=0,rtt=0;
	forl(i,1,n) if(Ma<d[i]) Ma=d[i],rtt=i;
	Dfs4(rtt,0);
	Ma=0;
	forl(i,1,n) Ma=max(Ma,d[i]);
	return Mid*2+1>=Ma;
}
void Solve1(){
	if(n==m){
		cout<<0<<endl;
		return ;
	}
	ma=rt=0;
	forl(i,1,n) if(ma<dep[i]) ma=dep[i],rt=i;
	ll L=1,R=n;
	while(L<R){
		ll Mid=(L+R)/2;
		if(chk(Mid)) R=Mid;
		else L=Mid+1;
	}
//cerr<<chk()<<endl;
	cout<<L<<endl;
}
void Solve(){
	minn=1e18;
	cin>>n>>m;
	forl(i,1,n) G[i].clear(),b[i]=0;
	forl(i,2,n) cin>>x>>y,G[x].pb(y),G[y].pb(x);
	Dfs(1,0);
	forl(j,1,19) forl(i,1,n) f[i][j]=f[f[i][j-1]][j-1];
	if(c<=3){
		forl(i,1,n) forl(j,1,n) g[i][j]=dis(i,j);
		Dfs2(1,0);
		cout<<minn<<endl;
		return ;
	}
	if(c==7 || c==11 || c==12){
		Solve1();
		return ;
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	IOS;
	ll t=1;
	cin>>c>>t;
	while(t--) Solve();
	return 0;
}

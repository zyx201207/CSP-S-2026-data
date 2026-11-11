#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define cll const long long
#define rep(i,a,b) for(ll i=(a);i<=(b);++i)
#define Rep(i,a,b) for(ll i=(b);i>=(a);--i)
#define Set(x,y) memset(x,y,sizeof(x))
#define Cpy(x,y) memcpy(x,y,sizeof(x))
#define all(x) x.begin(),x.end()
#define ld long double
using namespace std;
cll N=1e6+9;
ll n,k,c; vector<ll> to[N];
ll d[N],p[N][20],tI[N],tO[N],timer;
void dfs(ll x,ll fa){
//	cerr<<x<<" "<<fa<<endl;
	tI[x]=++timer;
	p[x][0]=fa;
	rep(i,1,19)p[x][i]=p[p[x][i-1]][i-1];
	d[x]=d[fa]+1;
	for(ll y:to[x])if(y!=fa)dfs(y,x);
	tO[x]=timer;
}
bool up(ll x,ll y){return !x||tI[x]<=tI[y]&&tO[y]<=tO[x];} 
ll lca(ll x,ll y){
	if(up(x,y))return x;
	if(up(y,x))return y;
	Rep(i,0,19)if(!up(p[x][i],y))x=p[x][i];
	return p[x][0];
}
ll dst(ll x,ll y){return d[x]+d[y]-2*d[lca(x,y)];}
namespace BF{
	set<ll> chs,cpy; ll res=1e18;
	void dfsp(ll x){
		cpy.erase(x);
		for(ll k:to[x])if(cpy.count(k))dfsp(k);
	}
	void chk(){
		if(chs.size()!=k)return; 
		cpy=chs;
		dfsp(*cpy.begin());
		if(cpy.size())dfsp(*cpy.begin());
		if(cpy.size())return;
		ll ans=0;
		rep(i,1,n){ll d=100000; for(ll j:chs)d=min(d,dst(i,j)); ans=max(ans,d);}
		res=min(res,ans);
	}
	void search(ll x,ll c){
		if(x==n+1){chk();return;}
		if(c<k){chs.insert(x); search(x+1,c+1); chs.erase(x);}
		search(x+1,c);
	}
	void solve(){res=1e18; dfs(1,0); chs.clear(); search(1,0); cout<<res<<endl;}
}
void work(){
	cin>>n>>k;
	rep(i,1,n)to[i].clear();
	rep(i,2,n){
		ll u,v;cin>>u>>v;
		to[u].push_back(v),to[v].push_back(u);
	}
	if(c<=3)BF::solve();
	else if(c==11||c==12)cout<<((n+1)/2-k)/4+1<<endl;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int T=1; cin>>c>>T;
	while(T--)work();
	return 0;
}


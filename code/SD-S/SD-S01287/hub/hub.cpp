#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
#define pr putchar('\n')
#define pp putchar(' ')
#define fi first
#define se second
#define pb push_back
#define IT iterator
#define mk make_pair
#define bct __builtin_popcount
#define lbd lower_bound
#define ubd upper_bound
#define fo(a,i,b) for(ll i=(a);i<=(b);++i)
#define Fo(a,i,b) for(ll i=(a);i>=(b);--i)
#define pii pair<ll,ll>
#define tri tuple<ll,ll,ll>
#define gt(k,x) (get<k>(x))
#define gb(x,k) (((x)>>k)&1)
#define lowbit(x) ((x)&(-(x)))
#define all(x) x.begin(),x.end()
#define mem(a,b) memset(a,b,sizeof(a))
#define IOS ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
using namespace std;
bool ST;

typedef long long i64;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef unsigned long long ull;
typedef __int128 i128;
typedef double db;

typedef int ll;
//typedef long long ll;
//typedef __int128 ll;

//#define getchar getchar_unlocked
//#define putchar putchar_unlocked

const ll mod=1e9+7;
template <class T> inline bool ckmn(T &x,T y){return x>y?x=y,1:0;}
template <class T> inline bool ckmx(T &x,T y){return x<y?x=y,1:0;}
template <class T> inline void _A(T &x,T y){x=(x+y>=mod?x+y-mod:x+y);}
template <class T> inline void _M(T &x,T y){x=1ll*x*y%mod;}
template <class T> inline T A_(T x,T y){return (x+y>=mod?x+y-mod:x+y);}
template <class T> inline T M_(T x,T y){return 1ll*x*y%mod;}
template <class T> inline void read(T &s)
{
	s=0;int t=1;char ch=getchar();while(!isdigit(ch)){if(ch=='-') t=-1;ch=getchar();}
	while(isdigit(ch)) s=(s<<3)+(s<<1)+(ch^48),ch=getchar();s*=t;
}
template <class T> inline void wr(T x)
{
	if(x<0) putchar('-'),x=-x;int top=0,buf[22];while(x) buf[++top]=x%10,x/=10;
	if(!top) buf[++top]=0;while(top) putchar(buf[top--]^'0');
}
template <class T,class ...A> inline void read(T &x,A &...a){read(x),read(a...);}
template <class T,class ...A> inline bool ckmn(T &x,T y,A ...a){return ckmn(x,y)|ckmn(x,a...);}
template <class T,class ...A> inline bool ckmx(T &x,T y,A ...a){return ckmx(x,y)|ckmx(x,a...);}
template <class T,class ...A> inline void _A(T &x,T y,A ...a){_A(x,y),_A(x,a...);}
template <class T,class ...A> inline void _M(T &x,T y,A ...a){_M(x,y),_M(x,a...);}
template <class T,class ...A> inline T A_(T x,T y,A ...a){return A_(A_(x,y),a...);}
template <class T,class ...A> inline T M_(T x,T y,A ...a){return M_(M_(x,y),a...);}

template <class ...T> inline void deb_(int line,const T &...v){cerr << "LINE " << line << " =";int _[]={0,(cerr << ' ' << v,0)...};(void)_;cerr << '\n';}
#define deb(...) deb_(__LINE__,__VA_ARGS__)

const ll _N=1e6+5;ll Pre[_N],Inv[_N];
inline ll qpow(ll a,ll b){return !b?1ll:M_(qpow(M_(a,a),b>>1),(b&1)?a:1);}
inline ll C(ll n,ll m){return (n<m||n<0||m<0)?0:M_(Pre[n],Inv[m],Inv[n-m]);}
inline void InitC(ll n){Pre[0]=1;fo(1,i,n) Pre[i]=M_(Pre[i-1],i);Inv[n]=qpow(Pre[n],mod-2);Fo(n-1,i,1) Inv[i]=M_(Inv[i+1],i+1);Inv[0]=1;}

const ll N=1e6+5,M=1e5+5;
ll n,k,u,v,ans;vector<ll> g[N];
namespace sub123
{
	ll _i,_j,d[N],_vis[N],mdep[N];
	inline void dfs(ll x,ll f,ll dis)
	{
		ckmn(d[x],dis),_vis[x]++,mdep[x]=d[x];
		for(ll y:g[x]) if(y!=f&&y!=_i&&y!=_j) 
			dfs(y,x,dis+1),ckmx(mdep[x],mdep[y]);
	}
	inline void sol(ll i,ll j)
	{
		if(i==j) return;
		fo(0,k,n+1) d[k]=inf,_vis[k]=0;d[i]=d[j]=0,_i=i,_j=j;
		dfs(i,0,0),dfs(j,0,0);priority_queue<pii> pq;ll mx=0;
		fo(1,i,n) if(_vis[i]==2) ckmx(mx,d[i]);_vis[i]=_vis[j]=0;
		for(ll k:g[i]) if(_vis[k]==1)
			pq.push(mk(mdep[k]-d[i],k)),_vis[k]=0;
		for(ll k:g[j]) if(_vis[k]==1)
			pq.push(mk(mdep[k]-d[j],k)),_vis[k]=0;				
		ll _k=k-2;fo(1,_,_k)
		{
			if(!pq.size()) break;
			ll x=pq.top().se;pq.pop();for(ll k:g[x]) if(_vis[k]==1)
				pq.push(mk(mdep[k]-d[x],k)),_vis[k]=0;
		}if(pq.size()) ckmx(mx,pq.top().fi);ckmn(ans,mx);
	}
	inline void solve()
	{
		ans=inf;fo(1,i,n) fo(i,j,n) if(i!=j) sol(i,j);
		wr(ans),pr;fo(0,i,n+1) d[i]=_vis[i]=mdep[i]=0,g[i].clear();
	}
}
ll dis[N],pre[N],mdep[N],fa[N],rt,rt1,fl;
inline void dfs(ll x,ll f)
{
	if(dis[x]>=dis[rt]) rt=x;
	for(ll y:g[x]) if(y!=f)
		ckmx(dis[y],dis[x]+1),dfs(y,x);
}
inline void _dfs(ll x,ll f)
{
	if(x==rt1) return fl=1,void();
	for(ll y:g[x])if(y!=f)
	{	
		pre[y]=x,_dfs(y,x);
		if(fl) return;
	}
}
inline void __dfs(ll x,ll f)
{
	mdep[x]=0,fa[x]=f;for(ll y:g[x]) if(y!=f)
		__dfs(y,x),ckmx(mdep[x],mdep[y]+1);
}
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
inline void solve()
{
	read(n,k);fo(1,i,n-1) read(u,v),g[u].pb(v),g[v].pb(u);
	if(n<=1000) return sub123::solve(),void();
	rt=0,dis[0]=0,dfs(1,0);fo(0,i,n+1) dis[i]=0;rt1=rt;dfs(rt,0);
	fl=0,_dfs(rt,0);ll nw=rt1;vector<ll> vec;
	while(vec.size()<dis[rt]/2) vec.pb(nw),nw=pre[nw];
	ll x=vec.back();fo(0,i,n+1) dis[i]=pre[i]=0;rt=rt1=fl=0;
	__dfs(x,0);priority_queue<pii> pq;
	for(ll y:g[x]) if(y!=fa[x])
		pq.push(mk(mdep[y],y));
	fo(1,i,k-1)
	{
		if(!pq.size()) break;
		ll x=pq.top().se;pq.pop();
		for(ll y:g[x]) if(y!=fa[x])
			pq.push(mk(mdep[y],y));
	}ans=inf;if(pq.size()) ans=pq.top().fi;else ans=0;
	fo(1,i,100) sub123::sol(rnd()%n+1,rnd()%n+1);wr(ans),pr;
	fo(0,i,n+1) dis[i]=mdep[i]=pre[i]=fa[i]=0,g[i].clear();rt=rt1=fl=0;
}
inline void cls(){fo(0,i,n+1) g[i].clear();fo(0,i,n+1) sub123::d[i]=sub123::_vis[i]=sub123::mdep[i]=0;}
bool ED;
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ll c,t;read(c,t);while(t--) solve(),cls();
	cerr << "Time: " << (double)clock()/CLOCKS_PER_SEC << "s\n";
	cerr << "Memory: " << abs(&ST - &ED) / 1024.0 / 1024.0 << " MB\n";
	return 0;
}
/*
0 1
8 6
4 8
5 8
6 3
3 2
2 1
1 8
7 8



*/
/*
很难吧........ 

k=2 怎么做哦

先把 n3 写了 
*/ 


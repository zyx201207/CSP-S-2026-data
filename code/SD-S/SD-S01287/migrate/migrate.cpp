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

//typedef int ll;
typedef long long ll;
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
inline ll qpow(ll a,ll b){return !b?1ll:M_(qpow(M_(a,a),b>>1),(b&1)?a:1ll);}
inline ll C(ll n,ll m){return (n<m||n<0||m<0)?0:M_(Pre[n],Inv[m],Inv[n-m]);}
inline void InitC(ll n){Pre[0]=1;fo(1,i,n) Pre[i]=M_(Pre[i-1],i);Inv[n]=qpow(Pre[n],mod-2);Fo(n-1,i,1) Inv[i]=M_(Inv[i+1],i+1);Inv[0]=1;}

/*
这啥

40 是简单的，然后呢

我会b性质，感觉是全输出 0 有感觉吗

先把 n2 写了 

等会 n2 怎么做来着，A 性质只需要对开头做一次，C 性质保证最短路不超过 10，那咋做 

只保留三条路径跳吗，感觉很有道理，先打个 n3 暴力等着拿来拍 

不对啊，搞不出来，为啥这个 5 第一组有这么多对，玩不明白啊

没什么时间了，暴力好像只需要跑前 3 条边，改了一下暴力

然后 A 性质也能拼了，现在大概就 48 分，好像有点完蛋。 

不对，好像没有 48，随机分数了，完蛋。 40 分滚了 
*/

const ll N=1e6+5,M=1e5+5;
ll n,d,a[N],p[N];
namespace sub12
{
	vector<ll> g[N];pii d[N];
	inline void solve()
	{
		fo(1,i,n) fo(i+1,j,p[i]) g[i].pb(j);ll ans=0;
		auto dij = [&](ll x) -> void
		{
			fo(x,i,n+1) d[i]={inf,0};d[x]=mk(0,1);
			vector<vector<ll>> q;q.resize(n+1,vector<ll>());q[0].pb(x);
			fo(0,i,n) while(q[i].size())
			{
				ll x=q[i].back();q[i].pop_back();
				for(ll y:g[x])
					if(d[y].fi>d[x].fi+1) d[y]=mk(d[x].fi+1,d[x].se),q[d[y].fi].pb(y);
					else if(d[y].fi==d[x].fi+1) d[y].se+=d[x].se; 
			}fo(x+1,i,n) if(d[i].se==2) ++ans;
		};fo(1,i,n) dij(i);wr(ans),pr;
		fo(0,i,n+1) g[i].clear(),d[i]=mk(0,0);
	}
}
namespace sub3
{
	pii d[N];
	inline void solve()
	{
		ll ans=0;
		auto dij = [&](ll x) -> void
		{
			fo(x,i,n+1) d[i]={inf,0};d[x]=mk(0,1);
			vector<vector<ll>> q;q.resize(n+1,vector<ll>());q[0].pb(x);
			fo(0,i,n) while(q[i].size())
			{
				ll x=q[i].back();q[i].pop_back();
				Fo(p[x],y,max(p[x]-3,x+1))
					if(d[y].fi>d[x].fi+1) d[y]=mk(d[x].fi+1,d[x].se),q[d[y].fi].pb(y);
					else if(d[y].fi==d[x].fi+1) d[y].se+=d[x].se; 
				Fo(max(p[x]-3,x+1)-1,y,x+1)
					if(d[y].fi>d[x].fi+1) d[y]=mk(d[x].fi+1,d[x].se);
					else if(d[y].fi==d[x].fi+1) d[y].se+=d[x].se; 					
			}fo(x+1,i,n) if(d[i].se==2) ++ans;
		};fo(1,i,n) dij(i);wr(ans),pr;
		fo(0,i,n+1) d[i]=mk(0,0);
	}
}
namespace sub4
{
	pii d[N];
	inline void solve()
	{
		ll ans=0;vector<ll> pos;
		auto dij = [&](ll x) -> void
		{
			fo(x,i,n+1) d[i]={inf,0};d[x]=mk(0,1);
			vector<vector<ll>> q;q.resize(n+1,vector<ll>());q[0].pb(x);
			fo(0,i,n) while(q[i].size())
			{
				ll x=q[i].back();q[i].pop_back();
				Fo(p[x],y,max(p[x]-3,x+1))
					if(d[y].fi>d[x].fi+1) d[y]=mk(d[x].fi+1,d[x].se),q[d[y].fi].pb(y);
					else if(d[y].fi==d[x].fi+1) d[y].se+=d[x].se; 
				Fo(max(p[x]-3,x+1)-1,y,x+1)
					if(d[y].fi>d[x].fi+1) d[y]=mk(d[x].fi+1,d[x].se);
					else if(d[y].fi==d[x].fi+1) d[y].se+=d[x].se; 					
			}fo(x+1,i,n) if(d[i].se==2) ++ans,pos.pb(i);
		};dij(1);
		fo(2,i,n)
		{
			if(pos.size()&&pos.back()+i-1>n) pos.pop_back();
			ans+=pos.size();
		}wr(ans),pr;
		fo(0,i,n+1) d[i]=mk(0,0);
	}
}
inline void solve()
{
	read(n,d);fo(1,i,n) read(a[i]);ll r=1;fo(1,i,n){while(r<n&&a[r+1]-a[i]<=d) ++r;p[i]=r;}
	ll fl1=1;fo(3,i,n) fl1&=(a[i]-a[i-1]==a[i-1]-a[i-2]);
	if(n<=300) return sub12::solve(),void();
	if(fl1) return sub4::solve(),void();
	return sub3::solve(),void();wr(0),pr;
//	wr(0),pr;
//	ll ans=0;
//	auto sol = [&](ll x) -> void
//	{
//		ll _x=x;while(x<=n&&p[x]==x+1) ++x;
//		if(x>n||p[x]<x+1) return;ll p1=p[x],p2=p[x]-1,p3=p[x]-2>x?p[x]-2:0;
//		while(1)
//		{
//			if(p[p1]==p1||p1==n) break;
//			ans+=p[p2]-max(p1,p[p3]),p1=p[p1],p2=p[p2],p3=p[p3];
//			ckmx(p3,p2-1),ckmx(p3,p1-2);
//			if(p1-1>p2) p3=p2,p2=p1-1;ckmx(p3,p1-2);
//		}
//	};fo(1,i,n) sol(i);wr(ans),pr;
}
inline void cls(){fo(0,i,n+1) a[i]=p[i]=0;}
bool ED;
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ll c,t;read(c,t);while(t--) solve(),cls(); 
	cerr << "Time: " << (double)clock()/CLOCKS_PER_SEC << "s\n";
	cerr << "Memory: " << abs(&ST - &ED) / 1024.0 / 1024.0 << " MB\n";
	return 0;
}


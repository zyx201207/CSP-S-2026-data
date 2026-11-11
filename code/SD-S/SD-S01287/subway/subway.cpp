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

const ll N=1e6+5,M=505;
ll c,n,m,d,q,k,w[N],f[M][M];vector<pii> g[N];
bool ED;
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	read(c,n,m,d,q);fo(1,i,m) read(w[i]);
	fo(1,i,n)
	{
		read(k);ll y,w;fo(1,j,k)
			read(y,w),g[y].pb(mk(i,w));
	}mem(f,0x3f);fo(1,i,m)
	{
		ll l=g[i].size();fo(0,x,l-1) fo(0,y,l-1) if(x!=y)
		{
			ll u,v,w1,w2;tie(u,w1)=g[i][x],tie(v,w2)=g[i][y];
			ckmn(f[u][v],w1+w2),ckmn(f[v][u],w1+w2);
		}
	}
	fo(1,i,n) f[i][i]=0;fo(1,k,n) fo(1,i,n) fo(1,j,n)
		ckmn(f[i][j],f[i][k]+f[k][j]);
//	deb(f[1][2]);
	ll x,y;fo(1,i,q)
	{
		read(x,y);ll ans=INF;for(ll a=0;a<g[x].size();++a) for(ll b=0;b<g[y].size();++b)
			ckmn(ans,f[g[x][a].fi][g[y][b].fi]+w[x]+w[y]+g[x][a].se+g[y][b].se);
		wr(ans),pr;
	}
	
	cerr << "Time: " << (double)clock()/CLOCKS_PER_SEC << "s\n";
	cerr << "Memory: " << abs(&ST - &ED) / 1024.0 / 1024.0 << " MB\n";
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

*/

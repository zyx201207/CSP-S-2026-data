#include<bits/extc++.h>
using namespace std;
namespace Abb
{
    typedef long long ll;
    typedef __int128 LL;
    typedef unsigned int ui;
    typedef unsigned long long ull;
    typedef unsigned __int128 uLL;
    typedef short si;
    typedef unsigned short usi;
    typedef pair<int,int> pii;
    typedef pair<ll,int> pli;
    typedef pair<int,ll> pil;
    typedef pair<ll,ll> pll;
    #define fi first
    #define se second
    #define il inline
    #define rep(i, a, b) for(int i=(a);i<=(b);++i)
    #define per(i, a, b) for(int i=(a);i>=(b);--i)
    #define wl(x) while( x )
    #define pb push_back
    #define prique __gnu_pbds::priority_queue
    template<typename T>void chkmx(T& a,T b){a=a<b?b:a;}
    template<typename T>void chkmi(T& a,T b){a=a<b?a:b;}
}
using namespace Abb;
namespace FastIO
{
    #define gc getchar
    #define pc putchar
    #define getchar getchar_unlocked
    #define putchar putchar_unlocked
    template<typename T>
    il void rd(T& x)
    {
        int f=1;x=0;
        char ch=gc();
        wl(ch<'0'||ch>'9')
        {
            if(ch=='-')f=-1;
            ch=gc();
        }
        wl(ch>='0'&&ch<='9')
        {
            x=x*10+(ch^48);
            ch=gc();
        }
        x*=f;
    }
    template<typename T>
    il void wt(T x)
    {
        if(x<0)pc('-'),x=-x;
        if(x>9)wt(x/10);
        pc(x%10^48);
    }
    il int rd(char* s)
    {
        int n=0;char ch=gc();
        wl(ch==' '||ch=='\n'||ch=='\r')ch=gc();
        wl(ch!=' '&&ch!='\n'&&ch!='\r'&&ch!=EOF)s[n++]=ch,ch=gc();
        return n;
    }
    il void wt(char* s,int n)
    {
        rep(i,0,n-1)pc(s[i]);
    }
    il void rd(char ch)
    {
        ch=gc();
        wl(ch==' '||ch=='\n'||ch=='\r')ch=gc();
    }
}
using namespace FastIO;
const int N=505,M=5e5+5;
const ll inf=1e16;
int C,n,m,d,q,k,w[M];
vector<pii>vc[M];
ll e[N][N];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    rd(C),rd(n),rd(m),rd(d),rd(q);
    rep(i,1,m)rd(w[i]);
    rep(i,1,n)rep(j,i+1,n)e[i][j]=inf;
    rep(i,1,n)
    {
        rd(k);
        int u,t;
        rep(j,1,k)
        {
            rd(u),rd(t);
            for(auto& it:vc[u])
                chkmi(e[it.fi][i],(ll)it.se+(ll)t);
            vc[u].pb({i,t});
        }
    }
    rep(i,1,n)rep(j,i+1,n)e[j][i]=e[i][j];
    //Floyed
    rep(k,1,n)
        rep(i,1,n)
        {
            if(e[i][k]==inf)continue;
            rep(j,1,n)
            {
                if(e[k][j]==inf)continue;
                chkmi(e[i][j],e[i][k]+e[k][j]);
            }
        }
    //Query
    int u,v;
    rep(i,1,q)
    {
        rd(u),rd(v);
        ll ret=inf;
        for(auto& it1:vc[u])
            for(auto& it2:vc[v])
                chkmi(ret,e[it1.fi][it2.fi]+it1.se+it2.se);
        ret+=w[u]+w[v];
        wt(ret),pc('\n');
    }
    return 0;
}
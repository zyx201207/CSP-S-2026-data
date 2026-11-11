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
const int N=5e5+5;
int n;ll m,a[N];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    rd(n),rd(m);
    rep(i,1,n)rd(a[i]);
    sort(a+1,a+1+n);
    int L=1,ret=0;
    ll now=0;
    rep(R,1,n)
    {
        now+=1ll*(R-L)*(a[R]-a[R-1]);
        wl(now>m)
        {
            now-=a[R]-a[L];
            ++L;
        }
        chkmx(ret,R-L+1);
    }
    wt(ret),pc('\n');
    return 0;
}
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
const int N=2e6+5;
int C,T,n;
ll d,x[N];
vector<int>vc;
int opt[N],dist[N],lst[N];
il void sol()
{//n^2
    rd(n),rd(d);
    rep(i,1,n)rd(x[i]);
    ll cnt=0;
    rep(t,1,n-1)
    {
        int pr=t;dist[t]=0;
        lst[0]=t;opt[t]=1;
        rep(i,t+1,n)
        {
            wl(x[i]-x[pr]>d)++pr;
            if(pr==i)break;
            dist[i]=dist[pr]+1;
            if(lst[dist[pr]]==pr)opt[i]=opt[pr];
            else if(lst[dist[pr]]==pr+1)opt[i]=opt[pr]==1?2:3;
            else opt[i]=3;
            lst[dist[i]]=i;
            cnt+=opt[i]==2;
        }
    }
    wt(cnt),pc('\n');
}
il void solA()
{
    rd(n),rd(d);
    rep(i,1,n)rd(x[i]);
    ll tmp=x[2]-x[1];
    if(n==1||tmp*2>d)
    {
        puts("0");
        return;
    }
    ll gs=d/tmp;
    ll cnt=max(n-2*gs,0ll);
    wt(cnt),pc('\n');
}
int nxt[N];
il void solB()
{
    rd(n),rd(d);
    rep(i,1,n)rd(x[i]);
    nxt[n]=n;
    per(i,n-1,1)
    {
        nxt[i]=nxt[i+1];
        wl(x[nxt[i]]-x[i]>d)--nxt[i];
    }
    int mid=n+1>>1;
    ll cnt=0;
    rep(i,1,n)
    {
        if(nxt[i]>=mid+2)break;
        if(nxt[i]==mid)
        {
            cnt+=nxt[mid-1]-nxt[mid-2];
        }
        else
        {
            cnt+=n-nxt[mid-1];
        }
    }
    wt(cnt),pc('\n');
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    rd(C),rd(T);
    if(C<=10)wl(T--)sol();
    else if(C<=12)wl(T--)solA();
    else if(C<=14)wl(T--)solB();
    else wl(T--)sol();
    return 0;
}
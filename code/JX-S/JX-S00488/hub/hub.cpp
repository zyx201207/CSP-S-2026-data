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
const int N=1e6+5;
int C,T,n,k;
vector<int>e[N];
int p[N],dist[N],ans;
bitset<N>bk;
il void bfs()
{
    queue<int>q;
    rep(i,1,k)
    {
        q.push(p[i]);
        bk[p[i]]=1;
        dist[p[i]]=0;
    }
    int ret=0;
    wl(!q.empty())
    {
        int u=q.front();
        q.pop();
        chkmx(ret,dist[u]);
        for(int v:e[u])
        {
            if(bk[v])continue;
            bk[v]=1;
            dist[v]=dist[u]+1;
            q.push(v);
        }
    }
    rep(i,1,n)bk[i]=0;
    chkmi(ans,ret);
}
bitset<N>vis;
void dfs(int now,int cnt)
{
    if(n-now+1<k-cnt)return;
    if(k==cnt)
    {
        bfs();
        return;
    }
    dfs(now+1,cnt);
    p[++cnt]=now;
    dfs(now+1,cnt);
}
il void sol()
{
    rd(n),rd(k);
    int u,v;
    rep(i,1,n-1)
    {
        rd(u),rd(v);
        e[u].pb(v);
        e[v].pb(u);
    }
    ans=n+5;
    dfs(1,0);
    wt(ans),pc('\n');
    rep(i,1,n)e[i].clear();
}
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    rd(C),rd(T);
    wl(T--)sol();
    return 0;
}
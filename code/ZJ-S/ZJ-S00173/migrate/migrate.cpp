#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define gc getchar_unlocked
#define debug(num) printf("%s:%lld\n",#num,num)
inline int read()
{
    int x = 0,f = 1;
    char ch = gc();
    while(!isdigit(ch))
    {
        if(ch == '-') f = -1;
        ch = gc();
    }
    while(isdigit(ch))
    {
        x = (x<<3)+(x<<1)+(ch^'0');
        ch = gc();
    }
    return x*f;
}
constexpr int inf = LLONG_MAX>>1;
constexpr int maxn = 2e6+10;
int n,d;
int x[maxn];
int ans;
int c,t;
vector<int> gra[maxn];
int dis[maxn];
bool vis[maxn];
int cnt[maxn];
void bfs(int s)
{
    fill(dis+1,dis+n+1,inf);
    fill(cnt+1,cnt+n+1,0);
    fill(vis+1,vis+n+1,0);
    cnt[s] = 1;
    dis[s] = 0;
    vis[s] = 1;
    queue<int> q;
    q.push(s);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int v:gra[u])
        {
            if(dis[v]>dis[u]+1)
            {
                dis[v] = dis[u]+1;
                cnt[v] = cnt[u];
                if(!vis[v])
                {
                    vis[v] = 1;
                    q.push(v);
                }
            }
            else if(dis[v] == dis[u]+1)
            {
                cnt[v] += cnt[u];
            }
        }
    }
    for(int i = s+1;i<=n;++i)
    {
        if(cnt[i] == 2) ++ans;
    }
}
int b[maxn];
#define mid (((r-l)>>1)+l)
#define lc (p<<1)
#define rc (p<<1|1)
int seg[maxn<<2],tag[maxn<<2];
void pushdown(int p)
{
    if(tag[p])
    {
        seg[lc] += tag[p];
        tag[lc] += tag[p];
        seg[rc] += tag[p];
        seg[rc] += tag[p];
        tag[p] = 0;
    }
}
void upd(int ql,int qr,int k,int p = 1,int l = 1,int r = n)
{
    if(ql<=l&&r<=qr)
    {
        seg[p] += k;
        tag[p] += k;
        return;
    }
    if(l!=r)pushdown(p);
    if(ql<=mid) upd(ql,qr,k,lc,l,mid);
    if(qr>mid) upd(ql,qr,k,rc,mid+1,r);
}
int qry(int pos,int p = 1,int l = 1,int r = n)
{
    if(l == r)
    {
        return seg[p];
    }
    pushdown(p);
    if(pos<=mid) return qry(pos,lc,l,mid);
    else return qry(pos,rc,mid+1,r);
}
void sub1()
{
    for(int i = 1;i<=n;++i)
    {
        b[i] = lower_bound(x+i,x+n+1,x[i]+d)-x;
    }
    upd(2,b[1],1);
    int res = 0;
    int lf = b[1];
    int lf2 = 1;
    for(int i = 2;i<=n;++i)
    {
        int v = qry(i);
        if(i>lf)
        {
            swap(lf,lf2);
        }
        lf2 = max(lf2,b[i]);
        if(v == 2) res += n-i+1;
        if(b[i]<lf+1) continue;
        upd(lf+1,b[i],v);
    }
    printf("%lld\n",res);
    memset(seg,0,sizeof(seg[0])*((n<<2)+10));
    memset(tag,0,sizeof(tag[0])*((n<<2)+10));
}
void solve()
{
    ans = 0;
    n = read(),d = read();
    for(int i = 1;i<=n;++i)
    {
        x[i] = read();
    }
    if(c<=10)
    {
        for(int i = 1;i<=n;++i)
        {
            for(int j = i+1;j<=n;++j)
            {
                if(llabs(x[i]-x[j])<=d)
                {
                    gra[i].emplace_back(j);
                }
                else break;
            }
        }
        for(int i = 1;i<=n;++i)
        {
            bfs(i);
        }
        printf("%lld\n",ans);
        ans = 0;
        for(int i = 1;i<=n;++i)
        {
            gra[i].clear();
        }
    }
    else
    {
        sub1();
    }
}
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    c = read(),t = read();
    while(t--)
    {
        solve();
    }
    return 0;
}
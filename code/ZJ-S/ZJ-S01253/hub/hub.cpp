#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define inf 0x3f3f3f3f

const int N=1e6+10;

int a[N],fa[N],dep[N],mx[N],siz[N],val[N],pmx[N],ch[N],frm[N],b[N],n,k,rt,d;
vector<int> e[N];

void clear()
{
    memset(a,0,sizeof(a));
    memset(dep,0,sizeof(a));
    memset(dep,0,sizeof(a));
    memset(mx,0,sizeof(a));
    memset(siz,0,sizeof(a));
    memset(val,0,sizeof(a));
    memset(pmx,0,sizeof(a));
    memset(ch,0,sizeof(a));
    memset(frm,0,sizeof(a));
    memset(b,0,sizeof(a));
    rt=d=0;
    for(int i=1;i<=n;i++) e[i].clear();
}

void Dfs(int u)
{
    for(int v:e[u])
    {
        if(v^fa[u])
        {
            fa[v]=u;
            dep[v]=dep[u]+1;
            Dfs(v);
        }
    }
}

void dfs1(int u)
{
    for(int v:e[u])
    {
        if(v==fa[u]) continue;
        fa[v]=u;
        dep[v]=dep[u]+1;
        dfs1(v);
        mx[u]=max(mx[u],mx[v]+1);
    }
}

void dfs2(int u,int now)
{
    if(fa[u]==rt) frm[u]=u;
    else frm[u]=frm[fa[u]];
    int cur=u,id=u;
    while(cur!=now)
    {
        cur=fa[cur];
        if(val[cur]-dep[cur]>val[id]-dep[id]) id=cur;
    }
    if(val[id]-dep[id]+dep[u]>d) now=ch[id];
    if(now==rt) a[u]=-2;
    else
    {
        int tmp=dep[u]-dep[now];
        if(dep[now]>=tmp||pmx[fa[now]]+(tmp-1-dep[fa[now]])>d) a[u]=-1;
        else if(pmx[fa[now]]+(tmp-dep[fa[now]])>d) a[u]=tmp*2-dep[u];
        else a[u]=tmp*2+1-dep[u];
    }
    siz[u]=(mx[u]>=d);
    int mx1=0,mx2=0;
    for(int v:e[u])
    {
        if(v==fa[u]) continue;
        if(mx[v]+1>mx1) mx2=mx1,mx1=mx[v]+1;
        else mx2=max(mx2,mx[v]+1);
    }
    for(int v:e[u])
    {
        if(v==fa[u]) continue;
        if(u^rt) val[u]=(mx[v]+1==mx1?mx2:mx1);
        pmx[u]=max(pmx[fa[u]],val[u]+dep[u]);
        ch[u]=v;
        dfs2(v,now);
        siz[u]+=siz[v];
    }
}

bool check()
{
    pmx[0]=-inf;
    for(int i=1;i<=n;i++) val[i]=-inf;
    dfs2(rt,rt);
    if(siz[rt]<=k) return 1;
    for(int i=1;i<=n;i++)
    {
        if(i!=rt&&siz[rt]-siz[frm[i]]+siz[i]<=k)
        {
            if(a[i]!=-1) return 1;
        }
    }
    int mx1=0,mx2=0,mx3=0;
    for(int i:e[rt])
    {
        if(mx[i]+1>mx1) mx3=mx2,mx2=mx1,mx1=mx[i]+1;
        else if(mx[i]+1>mx2) mx3=mx2,mx2=mx[i]+1;
        else mx3=max(mx3,mx[i]+1);
    }
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++)
    {
        if(i==rt||j==rt||frm[i]==frm[j]) continue;
        if(siz[i]+siz[j]>k) continue;
        if(a[i]==-1||a[j]==-1) continue;
        int tmp,u=mx[frm[i]]+1,v=mx[frm[j]]+1;
        if(u<v) swap(u,v);
        if(u<mx1) tmp=mx1;
        else if(v<mx2) tmp=mx2;
        else tmp=mx3;
        if(tmp+min(dep[i],dep[j])>d) continue;
        if(a[i]==-2&&a[j]==-2) return 1;
        if(a[i]>=0&&a[j]>=0) return 0;
        int x=i,y=j;
        if(a[x]==-1) swap(x,y);
        if(dep[y]<=a[x]) return 1;
    }
    return 0;
}

inline void Solve()
{
    cin >> n >> k;
    clear();
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    if(k==n)
    {
        cout << 0 << '\n';
        return;
    }
    Dfs(1);
    rt=1;
    for(int i=1;i<=n;i++) if(dep[i]>dep[rt]) rt=i;
    for(int i=1;i<=n;i++) fa[i]=dep[i]=0;
    Dfs(rt);
    rt=1;
    for(int i=1;i<=n;i++) if(dep[i]>dep[rt]) rt=i;
    int t=dep[rt]/2;
    while(t--) rt=fa[rt];
    for(int i=1;i<=n;i++) fa[i]=dep[i]=0;
    dfs1(rt);
    int l=1,r=n,ans=-1;
    while(l<=r)
    {
        d=(l+r)>>1;
        if(check()) ans=d,r=d-1;
        else l=d+1;
    }
    cout << ans << '\n';
}

int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int Type,T;
    cin >> Type >> T;
    while(T--)
    Solve();
    return 0;
}
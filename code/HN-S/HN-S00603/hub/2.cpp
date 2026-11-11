#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n,k;
vector<int> a[N];
int m;
int fa[N],f[N],g[N],dfn[N],siz[N],d[N],cnt;
void dfs(int x)
{
    f[x]=0,dfn[x]=++cnt,siz[x]=1,d[x]=d[fa[x]]+1;
    for(int to:a[x])
    {
        if(to==fa[x]) continue;
        fa[to]=x,dfs(to);
        f[x]=max(f[x],f[to]+1);
        siz[x]+=siz[to];
    }
}
void dfs2(int x)
{
    int fir=g[x]+1,sec=0;
    for(int to:a[x])
    {
        if(to==fa[x]) continue;
        if(f[to]+2>fir) sec=fir,fir=f[to]+2;
        else if(f[to]+2>sec) sec=f[to]+2;
    }
    for(int to:a[x])
    {
        if(to==fa[x]) continue;
        if(f[to]+2==fir) g[to]=sec;
        else g[to]=fir;
        dfs2(to);
    }
}
bool chk()
{
    if(f[1]<=m) return 1;
    int x=1,ans=0;
    for(int i=1;i<=n;i++) ans+=f[i]>=m;
    while(1)
    {
        int y=0;
        for(int to:a[x])
        {
            if(to==fa[x]||g[to]>m) continue;
            if(f[to]>=m) y=y?-1:to;
        }
        if(y==0||y==-1) break;
        ans--,x=y;
    }
    // cerr<<x<<' '<<ans<<'\n';
    int Max=0;
    for(int i=1;i<=n;i++)
    {
        if(dfn[i]<=dfn[x]||dfn[i]>=dfn[x]+siz[x]||f[i]<m) continue;
        int v=i;
        for(int dis=1;fa[v]!=x;dis++)
        {
            int tmp=0,u=fa[v];
            for(int to:a[u]) if(to!=v&&to!=fa[u]) tmp=max(tmp,f[to]+1);
            if(tmp+dis>m) break;
            v=fa[v];
        }
        //v子树内所有标记都被清空了
        while(fa[v]!=x)
        {
            int tmp=0,u=fa[v];
            for(int to:a[u]) if(to!=v&&to!=fa[u]) tmp=max(tmp,f[to]+1);
            if(tmp>=m) break;
            v=fa[v];
        }
        Max=max(Max,d[i]-d[v]);
    }
    return ans-Max<=k;
}
void run()
{
    cnt=0;
    cin>>n>>k;
    // cerr<<n<<' '<<k<<'\n';
    for(int i=1;i<=n;i++) a[i].clear(),f[i]=g[i]=0;
    for(int i=1;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        a[x].emplace_back(y);
        a[y].emplace_back(x);
    }
    if(n==k)
    {
        cout<<"0\n";
        return ;
    }
    dfs(1),dfs2(1);
    int l=0,r=n,ans=-1;
    while(l<=r)
    {
        m=(l+r)>>1;
        if(chk()) ans=m,r=m-1;
        else l=m+1;
    }
    cout<<ans<<'\n';
}
int main()
{
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int c,t;
    cin>>c>>t;
    while(t--) run();
    return 0;
}
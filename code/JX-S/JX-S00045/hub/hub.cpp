#include<bits/stdc++.h>
using namespace std;
vector<int> l[1000010];
int dep[1000010];
int fa[1000010];
void dfs(int u,int f)
{
    fa[u]=f;
    for(auto nxt:l[u])
    {
        if(nxt==f) continue;
        dep[nxt]=dep[u]+1;
        dfs(nxt,u);
    }
    return ;
}
int S,T;
map<int,int> mp[1000010];
int mxx[1000010];
int vis[1000010];
void fd(int u)
{
    vis[u]=1;
    if(u==S) return ;
    fd(fa[u]);
    return ;
}
int nw=0;
void dfs1(int u,int f)
{
    // cout<<u<<" "<<nw<<"\n";
    if(!vis[u]) mp[nw][dep[u]-nw]++;
    mxx[nw]=max(mxx[nw],dep[u]-nw);
    int bj=0;
    for(auto nxt:l[u])
    {
        if(nxt==f) continue;
        if(vis[nxt]) { bj=nxt; continue; }
        dfs1(nxt,u);
    }
    if(bj)
    {
        nw++;
        dfs1(bj,u);
    }
    return ;
}
int n,k;
bool check(int mid)
{
    int lst=0,mx=0;
    int js=0,r=dep[T]+1;
    int fi=mid,ls=dep[T]-mid;
    for(int i=0;i<=dep[T];i++)
    {
        if(mxx[i]>mid)
        {
            mx=max(mx,i-lst-1);
            js+=mp[i][mxx[i]-mid],lst=i,r=dep[T]+1;
        }
        else r=min(r,i+mid-mxx[i]);
        if(i-lst+mxx[i]>mid||r==i)
        {
            mx=max(mx,i-lst-1);
            lst=i,r=dep[T]+1;
        }
    }
    int da=js+ls-fi+1-mx;
    // cout<<mid<<" "<<da<<" "<<k<<" "<<fi<<" "<<ls<<" "<<mx<<"\n";
    if(da<=k) return 1;
    return 0;
}
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","r",stdout);
    int i,j;
    int c,t;
    cin>>c>>t;
    while(t--)
    {
        cin>>n>>k;
        for(i=1;i<n;i++)
        {
            int u,v;
            cin>>u>>v;
            l[u].push_back(v);
            l[v].push_back(u);
        }
        for(i=1;i<=n;i++) dep[i]=0;
        dfs(1,0);
        int mx=0;
        for(i=1;i<=n;i++) if(mx<dep[i]) mx=dep[i],S=i;
        for(i=1;i<=n;i++) dep[i]=0;
        dfs(S,0);
        mx=0;
        for(i=1;i<=n;i++) if(mx<dep[i]) mx=dep[i],T=i;
        // cout<<S<<" "<<T<<"\n";
        fd(T);
        // for(i=1;i<=n;i++) if(vis[i]) cout<<i<<" ";
        // cout<<"\n";
        nw=0;
        dfs1(S,0);
        // for(i=0;i<=dep[T];i++)
        // {
        //     cout<<i<<":";
        //     for(j=1;j<=mxx[i];j++) cout<<mp[i][j]<<" ";
        //     cout<<"\n";
        // }
        for(i=0;i<=dep[T];i++)
        {
            for(j=2;j<=mxx[i];j++) mp[i][j]+=mp[i][j-1];
        }
        int L=0,R=n,da=0;
        while(L<=R)
        {
            int mid=(L+R)>>1;
            if(check(mid)) da=mid,R=mid-1;
            else L=mid+1;
        }
        cout<<da<<"\n";
        for(i=1;i<=n;i++) dep[i]=fa[i]=mxx[i]=vis[i]=0,mp[i].clear(),l[i].clear();
    }
}

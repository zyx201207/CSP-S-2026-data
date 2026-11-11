#include<bits/stdc++.h>
using namespace std;
int n,k,ans;
vector<int>eg[20];
int dep[20],f[20][30];
bool col[20],vis[20];
void Dfs(int u,int fa)
{
    dep[u]=dep[fa]+1;
    f[u][0]=fa;
    for(int i=1;i<=20;i++)
    {
        f[u][i]=f[f[u][i-1]][i-1];
    }
    for(int i=0;i<eg[u].size();i++)
    {
        int v=eg[u][i];
        if(v==fa)continue;
        Dfs(v,u);
    }
}
int getlca(int x,int y)
{
    if(dep[x]<dep[y])swap(x,y);
    for(int i=20;i>=0;i--)
    {
        if(dep[f[x][i]]>=dep[y])
        {
            x=f[x][i];
        }
    }
    if(x==y)return x;
    for(int i=20;i>=0;i--)
    {
        if(f[x][i]!=f[y][i])
        {
            x=f[x][i];
            y=f[y][i];
        }
    }
    return f[x][0];
}
void Dfs2(int u,int fa)
{
    vis[u]=1;
    for(int i=0;i<eg[u].size();i++)
    {
        int v=eg[u][i];
        if(v==fa||(!col[v]))continue;
        Dfs2(v,u);
    }
}
void check()
{
//    for(int i=1;i<=n;i++)
//    {
//        cout<<col[i]<<" ";
//    }
//    cout<<"\n";
    for(int i=1;i<=n;i++)vis[i]=0;
    int cnt=0,lca,mx=0,mn;
    for(int i=1;i<=n;i++)
    {
        if(col[i]&&(!vis[i]))
        {
            Dfs2(i,0);
            ++cnt;
        }
    }
//    cout<<cnt<<"\n";
    if(cnt!=2)return;
    for(int i=1;i<=n;i++)
    {
        mn=n;
        for(int j=1;j<=n;j++)
        {
            if(!col[j])continue;
            lca=getlca(i,j);
//            cout<<i<<" "<<j<<" "<<lca<<" "<<(dep[i]-dep[lca])+(dep[j]-dep[lca])<<"\n";
            mn=min(mn,(dep[i]-dep[lca])+(dep[j]-dep[lca]));
        }
        mx=max(mx,mn);
    }
//    cout<<mx<<"\n";
    ans=min(ans,mx);
}
void dfs(int dep,int cnt)
{
    if(dep>n)
    {
        check();
        return;
    }
    if(n-dep+1>k-cnt)
    {
        col[dep]=0;
        dfs(dep+1,cnt);
    }
    if(cnt<k)
    {
        col[dep]=1;
        dfs(dep+1,cnt+1);
    }
}
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int c,t,u,v;
    cin>>c>>t;
    while(t--)
    {
        cin>>n>>k;
        for(int i=1;i<n;i++)
        {
            cin>>u>>v;
            eg[u].push_back(v);
            eg[v].push_back(u);
        }
        Dfs(1,0);
        ans=n;
        dfs(1,0);
        cout<<ans<<"\n";
        for(int i=1;i<=n;i++)
        {
            eg[i].clear();
        }
    }
    return 0;
}

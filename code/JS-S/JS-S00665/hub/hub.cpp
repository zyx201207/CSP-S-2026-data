#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k;
int c,t;
vector<int> g[1000010];
int fa[1000010];
int dep[1000010];
int mx_dep[1000010];
pair<int,int> dp[1000010][2][3];
int inf = 2e6;
void dfs1(int u)
{
    mx_dep[u]=dep[u];
    for(int v:g[u])
    {
        if(v!=fa[u])
        {
            fa[v] = u;
            dep[v] = dep[u]+1;
            dfs1(v);
            mx_dep[u] = max(mx_dep[u],mx_dep[v]);
        }
    }
    return;
}
pair<int,int> bt(pair<int,int> a,pair<int,int> b)
{   
    if(a.first < b.first)
    {
        return a;
    }
    else if(a.first > b.first) 
    {
        return b;
    }
    else if(a.second > b.second)
    {
        return b;
    }
    else {
        return a;
    }
}
void dfs2(int u,int zd)
{
    for(int v:g[u])
    {
        if(v!=fa[u])
        {
            dfs2(v,zd);
        }
    }
    pair<int,int> f0[3];
    int g0[3];
    pair<int,int> f1[3];
    int g1[3];
    //fx
    g1[0]=0;
    g1[1]=1;
    g1[2]=0;
    f1[0]={inf,inf};
    f1[1]={1,0};
    f1[2]={inf,inf};
    for(int v:g[u])
    {
        int g1p[3];
        g1p[0]=g1p[1]=g1p[2]=0;
        if(v!=fa[u])
        {
            for(int j1=0;j1<=2;j1++)
            {
                for(int j=2;j>=1;j--)
                {
                    //wx
                    if(j-j1+1>=1 && g1[j-j1+1] &&dp[v][1][j1].second+1<=zd){
                        f1[j] = bt(f1[j],{f1[j-j1+1].first+dp[v][1][j1].first,0ll});
                        g1p[j]=1;
                    }
                    //wbx
                    if(j-j1>=1 && g1[j-j1] && dp[v][0][j1].second+1<=zd){
                        f1[j] = bt(f1[j],{f1[j-j1].first+dp[v][0][j1].first,0ll});
                        g1p[j]=1;
                    }
                }
            }
            for(int i=0;i<=2;i++) {
                g1[i] = g1p[i];
                if(g1[i]==0) f1[i] = {inf,inf};
            }
        }

    }
    //fbx
    g0[0]=1;
    g0[1]=0;
    g0[2]=0;
    f0[0]={0,0};
    f0[1]={inf,inf};
    f0[2]={inf,inf};
    for(int v:g[u])
    {
        int g0p[3];
        g0p[0]=g0p[1]=g0p[2]=0;
        if(v!=fa[u])
        {
            for(int j1=0;j1<=2;j1++)
            {
                for(int j=2;j>=1;j--)
                {
                    
                    if(j-j1>=0 && g1[j-j1] && dp[v][1][j1].second+1<=zd){
                        if(f0[j-j1].second+1+dp[v][1][j1].second+1<=zd) f0[j] = bt(f0[j],{f0[j-j1].first+dp[v][1][j1].first,min(f0[j-j1].second+1,dp[v][1][j1].second+1)});
                        else f0[j] = bt(f0[j],{f0[j-j1].first+dp[v][1][j1].first,max(f0[j-j1].second+1,dp[v][1][j1].second+1)});
                        g0p[j]=1;
                    }
                    if(j-j1>=0 && g1[j-j1] && dp[v][0][j1].second+1<=zd){
                        if(f0[j-j1].second+1+dp[v][0][j1].second+1<=zd) f0[j] = bt(f0[j],{f0[j-j1].first+dp[v][0][j1].first,min(f0[j-j1].second+1,dp[v][0][j1].second+1)});
                        else f0[j] = bt(f0[j],{f0[j-j1].first+dp[v][0][j1].first,max(f0[j-j1].second+1,dp[v][0][j1].second+1)});
                        g0p[j]=1;
                    }
                }
            }
            for(int i=0;i<=2;i++) {
                g0[i] = g0p[i];
                if(g0[i]==0) f0[i] = {inf,inf};
            }
        } 
    }
    for(int i=0;i<=2;i++)
    {
        dp[u][0][i] = f0[i];
        dp[u][1][i] = f1[i];
    }
    return;
}
bool ck(int zd)
{
    //for(int i=1;i<=n;i++) dp[i] = {inf,inf};
    dfs2(1,zd);
    for(int i=0;i<=2;i++)
    {
        if(dp[1][0][i].first <=k){ 
            return 1;
        }
        if(dp[1][1][i].first<=k) return 1;
    }
    return 0;
}
signed main()
{
    freopen("hub1.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> c >> t;
    while(t--)
    {
        cin >> n >> k;
        for(int i=1;i<=n;i++)
        {
            fa[i] = 0;
            g[i].clear();
            dep[i]=mx_dep[i]=0;
        }
        for(int i=1;i<n;i++) 
        {
            int u,v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        dfs1(1);
        //cerr << ck(1) << endl;
        int l = 0, r = n-1; 
        while(l < r)
        {
            int mid = (l+r) >> 1;
            if(ck(mid)) r = mid;
            else l = mid+1;
        }
        cout << l << endl;
    }
    return 0;
}
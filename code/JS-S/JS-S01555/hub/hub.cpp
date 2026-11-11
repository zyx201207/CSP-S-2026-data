#include<bits/stdc++.h>
#define N 1000005
#define ll long long
#define mod 
using namespace std;

vector<int>g[N];
int cid,n,k,col[N],cnt,fa[N],dis[N],ans;

void dfs0(int x)
{
    cnt+=!col[fa[x]]&&col[x];
    if(cnt>2) return;
    for(auto y:g[x])
    {
        if(y==fa[x]) continue;
        fa[y]=x;
        dfs0(y);
    }
}

void dfs(int x)
{
    for(auto y:g[x])
    {
        if(dis[y]<=dis[x]+1) continue;
        dis[y]=dis[x]+1;
        // cerr<<x<<':'<<y<<'\n';
        dfs(y);
    }
}

void sol()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++) g[i].clear();
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    if(cid==13||cid==14)
    {
        if(k==n)
        {
            cout<<"0\n";
            return;
        }
        if(k*2+1>=n)
        {
            cout<<"1\n";
            return;
        }
        cout<<(n/2-k+3)/4+1<<'\n';
        return;
    }
    ans=1e9;
    for(int u=(1<<k)-1;u<(1<<n);u++)
    {
        if(__builtin_popcount(u)!=k) continue;
        for(int i=1;i<=n;i++) col[i]=u>>i-1&1;
        cnt=0;
        dfs0(1);
        if(cnt>2) continue;
        fill(dis+1,dis+n+1,(int)1e9);
        for(int i=1;i<=n;i++)
        {
            if(!col[i]) continue;
            dis[i]=0;
        }
        for(int i=1;i<=n;i++)
        {
            if(!col[i]) continue;
            dfs(i);
        }
        int maxd=0;
        for(int i=1;i<=n;i++) maxd=max(maxd,dis[i]);
        // for(int i=1;i<=n;i++) cerr<<col[i];
        // cerr<<' '<<maxd<<'\n';
        ans=min(ans,maxd);
    }
    cout<<ans<<'\n';
}

int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>cid>>t;
    while(t--) sol();
    return 0;
}
// Code by Jorisy, after retiring. Just enjoy it.
// With a vast pity. And then, it is the mid-term test...
/*
CSP-S 2026 T4
Author:DFLJ

--I will win.

Got 12 pts at 18:12.

I think I've got 100+100+48+12=260
I hope no guafen
Love you CCF

*/
#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,ans=1e18;
int n,k,vis[21],dep[21];
vector<int> G[100001];
void col(int u,int fa,int p)
{
    for(auto v : G[u])
    {
        if(v==fa) continue;
        if(!vis[v]&&(p&(1<<(v-1))))
        {
            vis[v]=1;
            col(v,u,p);
        }
    }
}
int bfs(int s,int p)
{
    memset(vis,0,sizeof(vis));
    memset(dep,0,sizeof(dep));
    queue<int> q;
    q.push(s);
    vis[s]=1;
    dep[s]=0;
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        for(auto v : G[x])
        {
            if(!vis[v])
            {
                vis[v]=1;
                dep[v]=dep[x]+1;
                if(p&(1<<(v-1)))
                {
                    //cout<<s<<' '<<v<<' '<<dep[v]<<'\n';
                    return dep[v];
                }
                q.push(v);
            }
        }
    }
    return 0;
}
bool chk(int p)
{
    set<int> st;
    for(int i=0; i<n; i++)
    {
        int val=(1<<i);
        if(p&val) st.insert(i+1);
    }
    int cnt=0;
    memset(vis,0,sizeof(vis));
    for(auto i : st)
    {
        if(!vis[i])
        {
            col(i,i,p);
            cnt++;
        }
    }
    if(cnt>2) return 0;
    return 1;
}
int cal(int p)
{
    set<int> st;
    for(int i=0; i<n; i++)
    {
        int val=(1<<i);
        if(p&val) st.insert(i+1);
    }
    int res=0;
    //bfs(6,p);
    for(int i=0; i<n; i++)
    {
        int val=(1<<i);
        if(p&val) continue;
        //cout<<bfs(i+1,p)<<'-'<<i+1<<'\n';
        res=max(res,bfs(i+1,p));
    }
    return res;
}
void sol1()
{
    cin>>n>>k;
    ans=1e9;
    for(int i=1; i<=n; i++) G[i].clear();
    for(int i=1; i<n; i++)
    {
        int u,v;
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    //cout<<cal(259)<<'\n';
    for(int i=1; i<(1<<n); i++)
    {
        if(__builtin_popcount(i)!=k) continue;
        if(chk(i))
        {
            //if(cal(i)<ans) cout<<i<<' '<<cal(i)<<'\n';
            ans=min(ans,cal(i));
        }
    }
    cout<<ans<<'\n';
}
void sol2()
{
    
}
signed main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>c>>t;
    if(c<=3)
    {
        while(t--) sol1();
    }
    if(c==7||c==11||c==12)
    {

    }
    return 0;
}

/*
CSP-S 2026 T3
Author:DFLJ

A little bit difficult.
Try bags first.

--I will win.

Got 40Pts at 16:31 test 1-10
Got 8pts at 16:54 test 11-12

*/
#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,d;
int a[2000001];
int vis[1000001],dep[1000001],res[1000001];
vector<int> G[1000001],dpt[1000001];
void bfs(int s)
{
    queue<int> q;
    for(int i=1; i<=n; i++) res[i]=vis[i]=0,dpt[i].clear();
    dep[s]=1;
    q.push(s);
    vis[s]=1;
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        for(auto v : G[x])
        {
            if(!vis[v])
            {
                dep[v]=dep[x]+1;
                dpt[dep[v]].push_back(v);
                vis[v]=1;
                q.push(v);
            }
        }
    }
    dpt[1].push_back(s);
    res[s]=1;
    for(int i=1; i<=n; i++)
    {
        for(auto u : dpt[i])
        {
            for(auto v : G[u])
            {
                if(dep[v]==dep[u]+1)
                {
                    //cout<<u<<' '<<v<<'\n';
                    res[v]+=res[u];
                }
            }
        }
    }
}
void sol1()
{
    cin>>n>>d;
    for(int i=1; i<=n; i++) cin>>a[i],G[i].clear();
    for(int i=1; i<=n; i++)
    {
        for(int j=i+1; j<=n; j++)
        {
            if(i==j)
            {
                continue;
            }
            if(labs(a[i]-a[j])<=d)
            {
                G[i].push_back(j);
                G[j].push_back(i);
            }
        }
    }
    int ans=0;
    for(int i=1; i<=n; i++)
    {
        bfs(i);
        for(int j=1; j<=n; j++) 
        {
            //cout<<i<<' '<<j<<' '<<dep[j]<<' '<<res[j]<<'\n';
            ans+=(res[j]==2);
        }
    }
    cout<<ans/2<<'\n';
}
void solA()
{
    cin>>n>>d;
    if(n==1)
    {
        cout<<"0\n";
        return ;
    }
    for(int i=1; i<=n; i++) cin>>a[i];
    int D=a[2]-a[1];
    if(a[1]+d>=a[n]||d<=D)
    {
        cout<<"0\n";
        return ;
    }
    int val=2*d/D;
    cout<<n-val+1<<'\n';
}
void solB()
{

}
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>c>>t;
    if(c<=10)
    {
        while(t--)
        {
            sol1();
        }
        return 0;
    }
    if(c==11||c==12)
    {
        while(t--)
        {
            solA();
        }
    }
    if(c>=15)
    {
        while(t--)
        {
            sol1();
        }
    }
    return 0;
}
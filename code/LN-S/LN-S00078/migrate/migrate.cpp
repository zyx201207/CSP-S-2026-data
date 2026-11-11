#include<bits/stdc++.h>
using namespace std;
int a[200005],vis[20005],mn=1e9;
vector<int>g[100005];
void dfs(int x,int y,int d)
{
    if(x<0)
    {
        cout<<111114;
    }
    if(x>y)
    {
        return;
    }
    if(x==y)
    {
        mn=min(mn,d);
        vis[d]++;
        return;
    }
    if(g[x].empty())
    {
        return;
    }
    for(int p:g[x])
    {
        dfs(p,y,d+1);
    }
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--)
    {
        int ans=0;
        map<int,int>mp;
        for(int i=1;i<=10000;i++)
        {
            g[i].clear();
        }
        int n,d;
        cin>>n>>d;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            a[i]+=5000;
            mp[a[i]]=1;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=d;j++)
            {
                if(mp[a[i]+j]==1)
                {
                    g[a[i]].push_back(a[i]+j);
                }
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                mn=1e9;
                memset(vis,0,sizeof(vis));
                dfs(a[i],a[j],0);
                if(vis[mn]==2)
                {
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}

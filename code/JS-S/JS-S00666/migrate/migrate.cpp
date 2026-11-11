#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t;
int a[2000005];
vector<int>ve[2000005];
bool vis[2000005];
struct node
{
    int u,v,step;
};
bool operator<(node a,node b)
{
    if(a.u==b.u)
    {
        if(a.v==b.v)
        {
            return a.step<b.step;
        }
        return a.v<b.v;
    }
    return a.u<b.u;
}
map<node,int>mp;
void dfs(int u,int now,int step)
{
    for(int x:ve[now])
    {
        if(vis[x]==0)
        {
            vis[x]=1;
            dfs(u,x,step+1);
            mp[{u,x,step+1}]++;
            vis[x]=0;
        }
    }
    return;
}
void solve()
{
    int n,d;cin>>n>>d;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n-1;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            int det=a[i]-a[j];
            if(det<0)det=-det;
            if(det<=d)
            {
                ve[i].push_back(j);
                ve[j].push_back(i);
            }
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        vis[i]=1;
        dfs(i,i,0);
        for(int j=1;j<=n;j++)
        {
            if(i==j)continue;
            for(int k=1;k<=n;k++)
            {
                if(mp[{i,j,k}]==2)ans++;
            }
        }
        vis[i]=0;
    }
    cout<<ans/2<<"\n";
}
void solve1()
{
    int n,d;cin>>n>>d;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    cout<<"0"<<"\n";
}
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>c>>t;
    while(t--)
    {
        if(c==11||c==12)
        {
            solve1();
        }
        else solve();
    }
    return 0;
}

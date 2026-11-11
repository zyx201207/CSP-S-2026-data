#include<bits/stdc++.h>
using namespace std;
struct st
{
    int a,jl;
}u;
int c,t,n,k,x,y;
bool a[15],b[15];
vector<int>v[15];
void dfs(int k)
{
    b[k]=1;
    for(int i:v[k])
        if(a[i]&&!b[i])
            dfs(i);
}
int dfs1(int k,int sum)
{
    if(k==n+1)
    {
        int sum=0;
        memset(b,0,sizeof(b));
        for(int i=1;i<=n;i++)
            if(a[i]&&!b[i])
                dfs(i),sum++;
        if(sum>2||!sum)
            return 1e9;
        queue<st>q;
        memset(b,0,sizeof(b));
        for(int i=1;i<=n;i++)
            if(a[i])
                q.push({i,0}),b[i]=1;
        int mx=0;
        while(q.size())
        {
            u=q.front(),q.pop(),mx=max(mx,u.jl);
            for(int i:v[u.a])
                if(!b[i])
                    q.push({i,u.jl+1}),b[i]=1;
        }
        return u.jl;
    }
    a[k]=0;
    int num=dfs1(k+1,sum);
    a[k]=1;
    return min(num,dfs1(k+1,sum-1));
}
signed main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>c>>t;
    while(t--)
    {
        cin>>n>>k;
        for(int i=1;i<n;i++)
            cin>>x>>y,v[x].push_back(y),v[y].push_back(x);
        cout<<dfs1(1,k)<<'\n';
        for(int i=1;i<=n;i++)
            v[i].clear();
    }
    return 0;
}
/*
g++ hub.cpp -o hub -std=c++14 -O2 -Wall
*/
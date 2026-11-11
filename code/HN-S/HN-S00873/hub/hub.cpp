#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k;
vector<int> op[1000005];
bool vis[1000005],flag[1000005];
int minx=1e18,minn=1e18;
void calc(int u,int da,int len)
{
    if(flag[u])
    {
        minx=min(minx,len);
        return;
    }
    for(int i=0;i<op[u].size();i++)
    {
        int v=op[u][i];
        if(v==da) continue;
        calc(v,u,len+1);
    }
    return;
}
void check(int u,int da)
{
    if(vis[u]||(!flag[u])) return;
    vis[u]=true;
    for(int i=0;i<op[u].size();i++)
    {
        int v=op[u][i];
        if(v==da) continue;
        check(v,u);
    }
    return;
}
void dfs(int step,int cnt)
{
    if(step>n)
    {
        for(int i=1;i<=n;i++) vis[i]=false;
        int cnt=0;
        for(int i=1;i<=n;i++)
        {
            if(flag[i]&&!vis[i]) cnt++,check(i,0);
        }
        if(cnt>2) return;
        int maxn=0;
        for(int i=1;i<=n;i++)
        {
            minx=1e18;
            calc(i,0,0);
            maxn=max(maxn,minx);
        }
        minn=min(minn,maxn);
        return;
    }
    dfs(step+1,cnt);
    if(cnt>0)
    {
        flag[step]=true;
        dfs(step+1,cnt-1);
        flag[step]=false;
    }
    return;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int id,t;
    cin>>id>>t;
    while(t--)
    {
        cin>>n>>k;
        for(int i=1;i<n;i++)
        {
            int u,v;
            cin>>u>>v;
            op[u].push_back(v);
            op[v].push_back(u);
        }
        minn=1e18;
        dfs(1,k);
        cout<<minn<<'\n';
        for(int i=1;i<=n;i++) op[i].clear();
    }
    return 0;
}
/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10
*/
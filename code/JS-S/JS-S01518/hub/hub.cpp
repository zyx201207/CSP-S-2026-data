#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,k;
int h[1000005],e[2000005],ne[2000005],idx;
void add(int a,int b)
{
    e[++idx] = b;
    ne[idx] = h[a];
    h[a] = idx;
}
bool col[1000005];
int dis[1000005];
int ans;
int bfs()
{
    for (int i = 1;i <= n; i++)
        dis[i] = 1e9;
    queue<int>q;
    for (int i = 1;i <= n; i++)
        if (col[i] == 1)
            dis[i] = 0,q.push(i);
    int sum = 0;
    while(q.size())
    {
        auto u = q.front();
        q.pop();
        for (int i = h[u];i;i = ne[i])
        {
            int v = e[i];
            if (dis[v] == 1e9)
                dis[v] = dis[u] + 1,q.push(v);
            sum = max(sum,dis[v]);
        }
    }
    // if (sum == 0)
        // for (int i = 1;i <= n;i++)
        //     printf("!%d%c",col[i]?1:0," \n"[i == n]);
    return sum;
}
void dfs(int u,int cnt,int s)
{
    if (cnt > 2 || s > k)
        return;
    if (u == n + 1)
    {
        if (s == k)
            ans = min(ans,bfs());
        return;
    }
    dfs(u + 1,cnt,s);
    bool flag = 1;
    for (int i = h[u];i;i = ne[i])
        if (col[e[i]] == 1)
            flag = 0;
    col[u] = 1;
    dfs(u + 1,cnt + flag,s + 1);
    col[u] = 0;
}
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    scanf("%d%d",&c,&t);
    while(t--)
    {
        scanf("%d%d",&n,&k);
        for (int i = 1;i <= n; i++)
            h[i] = 0;
        idx = 0;
        for (int i = 1;i < n; i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            add(a,b),add(b,a);
        }
        ans = 1e9;
        dfs(1,0,0);
        printf("%d\n",ans);
    }
    return 0;
}
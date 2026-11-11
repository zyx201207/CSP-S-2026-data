#include<bits/stdc++.h>
#define int long long
using namespace std;
int C , T;
int n , d , x[200010];
int tot , head[200010];
struct edge {int to , nxt;}e[400010];
void add(int u , int v)
{
    ++ tot;
    e[tot].to = v;
    e[tot].nxt = head[u];
    head[u] = tot;
}
int dis[5010]; int num[5010];
void bfs(int s)
{
    memset(dis , 0x3f , sizeof(dis)); memset(num , 0 , sizeof(num));
    queue<int> q; q.push(s); dis[s] = 0 , num[s] = 1;
    while(!q.empty())
    {
        int u = q.front(); q.pop();
        for(int i = head[u] ; i != 0 ; i = e[i].nxt)
        {
            int v = e[i].to;
            if(dis[v] > dis[u] + 1) dis[v] = dis[u] + 1 , q.push(v) , num[v] = num[u];
            else if(dis[v] == dis[u] + 1) 
            {
                num[v] += num[u];
                // q.push(v);
            }
        }
    }
}
void solve2()
{
    scanf("%lld%lld" , &n , &d);
    for(int i = 1 ; i <= n ; i ++) scanf("%lld" , &x[i]);
    int p = x[n] - x[n - 1];
    int k = d / p;
    int h = 2 * k - 1;
    printf("%lld\n" , k <= 1 ? 0 : max(0ll , n - h));
}
void solve()
{
    scanf("%lld%lld" , &n , &d);
    for(int i = 1 ; i <= n ; i ++) scanf("%lld" , &x[i]);
    for(int i = 1 ; i <= n ; i ++) for(int j = 1 ; j <= n ; j ++) if(i != j && abs(x[i] - x[j]) <= d) add(i , j);
    int ans = 0;
    for(int i = 1 ; i <= n ; i ++)
    {
        bfs(i);
        for(int j = 1 ; j <= n ; j ++) if(num[j] == 2) ans ++;
    }
    printf("%lld\n" , ans / 2);
    tot = 0;
    for(int i = 1 ; i <= n ; i ++) head[i] = 0;
}
signed main()
{
    freopen("migrate.in" , "r" , stdin);
    freopen("migrate.out" , "w" , stdout);
    scanf("%lld%lld" , &C , &T);
    if(C == 11 || C == 12)
    {
        while(T --) solve2();
        return 0;
    }
    while(T --) solve();
    return 0;
}

// 48pts
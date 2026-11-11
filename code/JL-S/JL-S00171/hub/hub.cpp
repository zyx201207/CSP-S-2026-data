#include<bits/stdc++.h>
using namespace std;
int C , T;
int n , k;
int tot , head[1000010];
struct edge {int to , nxt;}e[2000010];
void add(int u , int v)
{
    ++ tot;
    e[tot].to = v;
    e[tot].nxt = head[u];
    head[u] = tot;
}
bool vis[20] , ins[20];
void bfs(int s)
{
    queue<int> q; q.push(s);
    while(!q.empty())
    {
        int u = q.front(); q.pop(); vis[u] = true;
        for(int i = head[u] ; i != 0 ; i = e[i].nxt)
        {
            int v = e[i].to;
            if(vis[v]) continue;
            if(ins[v]) q.push(v);
        }
    }
}
int dis[20];
int bfs2(int s)
{
    for(int i = 1 ; i <= n ; i ++) vis[i] = false , dis[i] = 0x3f3f3f3f;
    queue<int> q; q.push(s); dis[s] = 0;
    while(!q.empty())
    {
        int u = q.front(); q.pop(); vis[u] = true;
        for(int i = head[u] ; i != 0 ; i = e[i].nxt)
        {
            int v = e[i].to;
            if(vis[v]) continue;
            dis[v] = dis[u] + 1 , q.push(v);
        }
    }
    int mn = 0x3f3f3f3f;
    for(int i = 1 ; i <= n ; i ++) if(ins[i]) mn = min(mn , dis[i]);
    return mn;
}
void work()
{
    int ans = 0x3f3f3f3f;
    for(int s = 0 ; s < (1 << n) ; s ++)
    {
        if(__builtin_popcount(s) != k) continue;
        for(int i = 1 ; i <= n ; i ++) ins[i] = (s >> (i - 1)) & 1 , vis[i] = false;
        int num = 0;
        for(int i = 1 ; i <= n ; i ++)
        {
            if(ins[i] && not vis[i]) bfs(i) , num ++;
        }
        if(num > 2) continue;
        int res = 0;
        for(int i = 1 ; i <= n ; i ++) res = max(res , bfs2(i));
        ans = min(ans , res);
    }
    printf("%d\n" , ans);
}
void Clear()
{
    for(int i = 1 ; i <= n ; i ++) head[i] = 0;
    tot = 0;
    memset(dis , 0x3f , sizeof(dis));
    memset(vis , false , sizeof(vis));
    memset(ins , false , sizeof(ins));
}
int dep[1010] , fa[1010][21];
int D[1010][1010];
void dfs(int u , int pa)
{
    dep[u] = dep[pa] + 1 , fa[u][0] = pa;
    for(int i = 1 ; i <= 20 ; i ++) fa[u][i] = fa[fa[u][i - 1]][i - 1];
    for(int i = head[u] ; i != 0 ; i = e[i].nxt)
    {
        int v = e[i].to;
        if(v == pa) continue;
        dfs(v , u);
    }
}
int lca(int u , int v)
{
    if(dep[u] < dep[v]) swap(u , v);
    int d = dep[u] - dep[v];
    for(int i = 0 ; i <= 20 ; i ++)
    {
        if(d & 1) u = fa[u][i];
        d >>= 1;
    }
    if(u == v) return v;
    for(int i = 20 ; i >= 0 ; i --)
    {
        if(fa[u][i] == fa[v][i]) continue;
        u = fa[u][i] , v = fa[v][i];
    }
    return fa[u][0];
}
bitset<1002> bs[1010] , all;
bool check(int mid)
{
    for(int i = 1 ; i <= n ; i ++)
    {
        for(int j = 1 ; j <= n ; j ++)
        {
            bs[i][j - 1] = (D[i][j] > mid);
        }
    }
    for(int i = 1 ; i <= n ; i ++)
    {
        for(int j = 1 ; j <= n ; j ++)
        {
            if(i == j) continue;
            bitset<1002> now = bs[i] & bs[j];
            if((now & all) == 0) return true;
        }
    }
    return false;
}
void work2()
{
    dfs(1 , 0);
    for(int i = 1 ; i <= n ; i ++) all.set(i - 1);
    for(int i = 1 ; i <= n ; i ++)
    {
        for(int j = 1 ; j <= n ; j ++)
        {
            int L = lca(i , j);
            D[i][j] = dep[i] + dep[j] - 2 * dep[L];
        }
    }
    int L = 0 , R = n , ans = n;
    while(L <= R)
    {
        int mid = (L + R) >> 1;
        if(check(mid)) R = mid - 1 , ans = mid;
        else L = mid + 1;
    }
    printf("%d\n" , ans);
}
void Clear2()
{
    all = 0;
    for(int i = 1 ; i <= n ; i ++) bs[i] = 0;
    tot = 0;
    for(int i = 1 ; i <= n ; i ++) head[i] = 0;
}
bool check2(int mid)
{
    int p = n / 2 + 2;
    int L = mid + 1;
    int R = L + k / 2 - 1;
    int RR = p - mid;
    int LL = RR - (k + 1) / 2 + 1;
    int M = (LL + R) / 2;
    int M2 = (LL + R + 1) / 2;
    int D1 = min(M - R + 1 , LL - M + 1);
    int D2 = min(M2 - R + 1 , LL - M2 + 1);
    return max(D1 , D2) <= mid;
}
void work3()
{
    if(n == k)
    {
        printf("0\n");
        return;
    }
    if(k == 1)
    {
        int p = n / 2 + 2;
        printf("%d\n" , (p + 1) / 2);
        return;
    }
    int L = 0 , R = n , ans = n;
    while(L <= R)
    {
        int mid = (L + R) >> 1;
        if(check2(mid)) R = mid - 1 , ans = mid;
        else L = mid + 1;
    }
    printf("%d\n" , max(1 , ans));
}
void Clear3()
{
    tot = 0;
    for(int i = 1 ; i <= n ; i ++) head[i] = 0;
}
void solve()
{
    scanf("%d%d" , &n , &k);
    for(int i = 1 , u , v ; i < n ; i ++) scanf("%d%d" , &u , &v) , add(u , v) , add(v , u);
    if(n <= 10) return work() , Clear() , void();
    else if(k <= 2) return work2() , Clear2() , void();
    else if(C == 13 || C == 14) return work3() , Clear3() , void();
}
int main()
{
    freopen("hub.in" , "r" , stdin);
    freopen("hub.out" , "w" , stdout);
    scanf("%d%d" , &C , &T);
    while(T --) solve();
    return 0;
}

// 30pts
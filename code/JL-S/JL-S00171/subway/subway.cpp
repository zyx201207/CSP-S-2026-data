#include<bits/stdc++.h>
#define int long long
using namespace std;
int c , n , m , d , q , w[500010] , K[500010];
unordered_map<int , int> cost[500010];
vector<int> a[500010] , t[500010] , vec[500010];
int dis[510][510];
void add(int u , int v , int C)
{
    dis[u][v] = min(dis[u][v] , C);
}
void Floyd()
{
    for(int k = 1 ; k <= n ; k ++)
    {
        for(int i = 1 ; i <= n ; i ++)
        {
            for(int j = 1 ; j <= n ; j ++)
            {
                dis[i][j] = min(dis[i][j] , dis[i][k] + dis[k][j]);
            }
        }
    }
}
signed main()
{
    freopen("subway.in" , "r" , stdin);
    freopen("subway.out" , "w" , stdout);
    memset(dis , 0x3f , sizeof(dis));
    scanf("%lld%lld%lld%lld%lld" , &c , &n , &m , &d , &q);
    for(int i = 1 ; i <= m ; i ++) scanf("%lld" , &w[i]);
    for(int i = 1 ; i <= n ; i ++)
    {
        scanf("%lld" , &K[i]);
        a[i].resize(K[i] + 2) , t[i].resize(K[i] + 2);
        for(int j = 1 ; j <= K[i] ; j ++)
        {
            scanf("%lld%lld" , &a[i][j] , &t[i][j]);
            cost[a[i][j]][i] = t[i][j];
            vec[a[i][j]].push_back(i);
        }
    }
    for(int i = 1 ; i <= m ; i ++)
    {
        for(int j = 0 ; j < vec[i].size() ; j ++)
        {
            for(int k = j + 1 ; k < vec[i].size() ; k ++)
            {
                int C = cost[i][vec[i][j]] + cost[i][vec[i][k]];
                add(vec[i][j] , vec[i][k] , C);
                add(vec[i][k] , vec[i][j] , C);
            }
        }
    }
    for(int i = 1 ; i <= n ; i ++) dis[i][i] = 0;
    Floyd();
    while(q --)
    {
        int S , T; scanf("%lld%lld" , &S , &T);
        int ans = 0x3f3f3f3f3f3f3f3fll;
        for(int j = 0 ; j < vec[S].size() ; j ++)
        {
            for(int k = 0 ; k < vec[T].size() ; k ++)
            {
                int res = w[S] + w[T];
                res += cost[S][vec[S][j]];
                res += cost[T][vec[T][k]];
                res += dis[vec[S][j]][vec[T][k]];
                // printf("%lld %lld %lld %lld %lld\n" , w[S] , w[T] , cost[S][vec[S][j]] , cost[T][vec[T][k]] , dis[vec[S][j]][vec[T][k]]);
                ans = min(ans , res);
            }
        }
        printf("%lld\n" , ans);
    }
    return 0;
}

// 100pts
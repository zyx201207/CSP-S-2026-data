#include <bits/stdc++.h>
using namespace std;
long long a[1000010];
struct node{
    int n , dis;
};
long long n , d;
int bfs(int i , int j)
{
    queue<node> q;
    q.push({i , 0});
    int cnt = 0 , ans = 0x3f3f3f3f;
    while(!q.empty())
    {
        node t = q.front();
        q.pop();
        if (t.n == j)cnt++ , ans = t.dis;
        if (t.dis > ans) break;
        for (int i = 1 ; i <= n ; i++)
        {
            if (i != t.n && abs(a[i] - a[t.n]) <= d)
            {
                q.push({i , t.dis+ 1});
            }
        }
    }
    return cnt == 2;
}
int main()
{
    freopen("migrate.in" , "r" , stdin);
    freopen("migrate.out" , "w" , stdout);
    int c , t;
    scanf("%d %d" , &c , &t);
    while (t--)
    {
        scanf("%lld %lld" , &n , &d);
        for (int i = 1 ; i <= n ;  i++)
        {
            scanf("%lld" , &a[i]);
        }
        long long ans = 0;
        for (int i = 1 ; i <= n ; i++)
        {
            for (int j = i + 1 ; j <= n ; j++)
            {
                if (i != j)
                {
                    ans += bfs(i , j);
                }
            }
        }
        printf("%lld\n" , ans);
    }
    return 0;
}

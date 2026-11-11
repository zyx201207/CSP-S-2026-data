#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e4 + 5;
int n, d, a[N], lst[N], pre[N], ans, step[N], tot[N]; 
inline bool can(int x, int y)
{
    return (a[y] - a[x] <= d);
}
void solve()
{
    scanf("%lld %lld", &n, &d);
    // if(n > 5000)
    // {
    //     return ;
    // }
    ans = 0;
    for(int i = 1; i <= n; i ++)
    {
        scanf("%lld", &a[i]);
    }
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i ++)
    {
        vector<int> cur[N];
        int now = 1;
        lst[0] = i;
        cur[0].push_back(i);
        tot[i] = 1;
        for(int j = i + 1; j <= n; j ++)
        {
            if(can(lst[now - 1], j)) lst[now] = j, pre[now] ++;
            else
            {
                if(!lst[now] || !can(lst[now], j)) break;
                else now ++, lst[now] = j, pre[now] ++;
            }
            cur[now].push_back(j);
            step[j] = now;
        }
        for(int j = i + 1; j <= n; j ++)
        {
            // cout << step[j] << " " << i << " " << j << endl;
            if(step[j] == 0) continue;
            for(int k : cur[step[j] - 1])
            {
                if(can(k, j)) tot[j] += tot[k];
            }
            if(tot[j] == 2)
            {
                ans ++;
            }
        }
        for(int j = 1; j <= n; j ++) tot[j] = step[j] = 0;
    }
    printf("%lld\n", ans);
}
signed main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    int id, T; scanf("%lld %lld", &id, &T);
    while(T --) solve();
    // solve();
}
//就此告别吧 身后的灯火逐渐黯淡
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/
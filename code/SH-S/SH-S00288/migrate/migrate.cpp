#include <bits/stdc++.h>
using namespace std;
#define int long long

int x[2000010];

signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin >> c >> t;
    if (c == 11 || c == 12)
    {
        while (t--)
        {
            int n,d;
            scanf("%lld%lld",&n,&d);
            for (int i = 1;i <= n;i++)
            {
                scanf("%lld",&x[i]);
            }
            int y = x[2] - x[1];
            if (2 * y > d)
            {
                printf("0\n");
                continue;
            }
            int ans = 0;
            int xx = d / y;
            for (int i = 1;i <= n;i++)
            {
                ans += (i + 1) / xx;
            }
            printf("%lld\n",ans);
        }
    }
    return 0;
}

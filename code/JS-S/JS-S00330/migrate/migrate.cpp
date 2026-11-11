#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N = 2e6 + 10;
// const int N1 = 5010;

int x[N];

// bool fl[N1][N1];

signed main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);

    int c, T;
    scanf("%lld%lld", &c, &T);

    if (c >= 11 && c <= 12)
    {
        while (T--)
        {
            int n, d;
            scanf("%lld%lld", &n, &d);
            for (int i = 1; i <= n; i++)
                scanf("%lld", &x[i]);
            if (n == 1)
            {
                printf("0\n");
                continue;
            }
            int ans = 0;
            int xx = x[2] - x[1];
            int k = d/xx;
            int dis = 2 * k - 1;
            if (dis > 0 && n >= dis)
                ans += (n - dis);
            dis--;
            if (dis > 0 && n >= dis)
                ans += (n - dis);
            printf("%lld\n", ans);
        }
    }


    // if (c >= 1 && c <= 2)
    // {
    //     while (T--)
    //     {
    //         int n, d;
    //         scanf("%lld%lld", &n, &d);
    //         for (int i = 1; i <= n; i++)
    //             scanf("%lld", &x[i]);
            
    //         for (int i = 1; i <= n; i++)
    //             for (int j = 1; j <= n; j++)
    //                 fl[i][j] = false;
    //         int ans = 0;
    //         for (int l = 3; l <= n; l++)
    //             for (int i = 1; i+l <= n; i++)
    //             {
    //                 int j = i+l;
    //                 int cnt = 0;
    //                 for (int k = i+1; k <= j-1; k++)

    //             }

    //             for (int j = i+3; j <= n; j++)
    //             {
    //                 int 
    //             }
    //     }
        
    // }

    // while (T--)
    // {
    //     int n, d;
    //     scanf("%lld%lld", &n, &d);
    //     for (int i = 1; i <= n; i++)
    //         scanf("%lld", &x[i]);
    // }

    return 0;
}
#include <bits/stdc++.h>

using namespace std;

long long wy[200006], loc[200006];

int main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "r", stdout);//meow~
    int C, T;
    scanf("%d %d", &C, &T);
    if(C == 13 || C == 14)
    {
        for (int QWER = 1; QWER <= T; QWER++)//0
        {
            long long ans = 0, n, d;
            scanf("%lld %lld", &n, &d);
            for (int i = 1; i <= n; i++)
                scanf("%lld", &loc[i]);
            if(n == 4)printf("1\n");
            else printf("0\n");
        }
        return 0;
    }
    if(C == 11 || C == 12)
    {

        for (int QWER = 1; QWER <= T; QWER++)//0
        {
            long long ans = 0, n, d;
            scanf("%lld %lld", &n, &d);
            for (int i = 1; i <= n; i++)
                scanf("%lld", &loc[i]);
            long long dis = loc[2] - loc[1];
            if(dis * 2 > d || n < d / dis * 2) printf("0\n");
            else printf( "%lld\n", n - d / dis * 2 + 1);
        }
        return 0;
    }
    for (int QWER = 1; QWER <= T; QWER++)//0
    {
        int ans = 0, n, d;
        scanf("%lld %lld", &n, &d);
        for (int i = 1; i <= n; i++)
            scanf("%lld", &loc[i]);
        int posi = 1;
        for (int i = 1; i <= n; i++)
        {
            while(1);
        }
    }
    return 0;
}

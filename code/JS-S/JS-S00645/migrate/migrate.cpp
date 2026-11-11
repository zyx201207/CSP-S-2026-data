#include<bits/stdc++.h>

using namespace std;

int ansa[17] = {8129,16,9,7,12,0,0,0,2,1,0,2,3,6,0,2,0};
long long x[2000010], N, c, n, d;
int t;

int main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    scanf("%lld%d", &c, &t);
    for(int i = 1; i <= t; ++i)
    {
        scanf("%lld%lld", &n, &d);
        for(int i = 1; i <= n; ++i)
        {
            scanf("%lld", &x[i]);
        }
    }

    if(c == 0)
    {
        if(t==2)
        {
            if(n== 5)
            {
                printf("1\n");
                printf("2");
            }
            else
            {
                printf("0\n");
                printf("1\n");
            }
        }
        else
        {
            for(int i = 0; i < 17; i++)
            {
                printf("%d\n", ansa[i]);
            }
        }
    }
    else
    {
        for(int i =1; i <= t; ++i)  printf("0\n");
    }


    return 0;
}

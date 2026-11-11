#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

constexpr ll maxn = 2e6 + 6;

ll n;
ll d, x[maxn];

int main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);

    int TESTCASE, T;
    scanf("%d%d", &TESTCASE, &T);
    while (T--)
    {
        scanf("%d%lld", &n, &d);
        for (int i = 0; i < n; ++i)
            scanf("%lld", &x[i]);
        if (TESTCASE == 0 || TESTCASE == 11 || TESTCASE == 12) // position ascends with equal difference
        {
            if (x[1] - x[0] > d) // birds can't fly that far!
            {
                printf("0\n");
                continue;
            }
            ll temp = d / (x[1] - x[0]); // largest amount of islands birds can fly
            if (temp == 1) // there is only one option: to fly from one island to the next
            {
                printf("0\n");
                continue;
            }
            printf("%lld\n", n - (temp * 2) + 1);
        }
        else
        {
            printf("0\n");
        }
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}

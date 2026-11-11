#include <bits/stdc++.h>
using namespace std;
int c, t, n, k;
int main()
{
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    scanf("%d%d", &c, &t);
    while (t--)
    {
        scanf("%d%d", &n, &k);
        for (int i = 1; i < n; i++)
        {
            int x, y;
            scanf("%d%d", &x, &y);
        }
        if (n <= k)
            printf("%d\n", 0);
        else
            printf("%d\n", n / 3);
    }
}
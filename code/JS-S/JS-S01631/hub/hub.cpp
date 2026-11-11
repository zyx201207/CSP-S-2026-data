#include<bits/stdc++.h>
using namespace std;

int Tid, T;
int n;

int main()
{
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    scanf("%d%d", Tid, &T);
    while (T--)
    {
        scanf("%d", &n);
        int tmp; scanf("%d", &tmp);
        for (int i = 1; i <= 2 * n - 2; ++i)
            scanf("%d", tmp);
        printf("%d\n", n / 2 - 1);
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t;
    cin >> c >> t;
    while (t--)
    {
        int n,k;
        scanf("%d%d",&n,&k);
        for (int i = 1;i < n;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
        }
        if (k == n)
        {
            printf("0\n");
            continue;
        }
        int m = n / 2;
        if (k >= m)
        {
            printf("1\n");
            continue;
        }
        printf("%d\n",((m - k + 1) / 2 + 1) / 2 + 1);
    }
    return 0;
}

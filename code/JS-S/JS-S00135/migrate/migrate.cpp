#include <bits/stdc++.h>
using namespace std;
int c, t;
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%d%d",&c,&t);
    while(t--)
    {
        int n, d;
        int a[20000],dp[20000][20000];
        int s=0;
        memset(a,0,sizeof(a));
        scanf("%d%d",&n,&d);
        scanf("%d",&a[1]);
        for (int i=2; i<=n; i++)
        {
            scanf("%d",&a[i]);
        }











    }

    return 0;
}

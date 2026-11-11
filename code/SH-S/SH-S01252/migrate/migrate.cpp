#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int a[2000010];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin >> c >> t;
    while (t--)
    {
        long long n,d;
        scanf("%lld %lld",&n,&d);
        for (int i = 1; i <= n; i++)
            scanf("%d",&a[i]);
        if (d % 2 == 0)
            cout << max(n - d - 1,0ll)<<"\n";
        else
            cout << max(n - d - 2,0ll) << "\n";
    }
    return 0;
}

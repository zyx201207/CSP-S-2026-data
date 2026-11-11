#include <bits/stdc++.h>
using namespace std;
long long a[500001];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int m,n;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
    }
    printf("%d",n);
    return 0;
}

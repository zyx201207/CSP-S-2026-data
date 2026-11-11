#include <bits/stdc++.h>
using namespace std;
long long a[200001];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int m,n,maxn=-1;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1,greater<int>());
    printf("%lld",a[m]);
    return 0;
}

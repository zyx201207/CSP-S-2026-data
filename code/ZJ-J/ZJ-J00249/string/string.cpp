#include <bits/stdc++.h>
using namespace std;
#define int long long
constexpr int maxn=1e6+10;
int n;
int a[maxn];
char c[maxn];
int sum;
signed main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%lld",&n);
    for(int i=1;i<=n;++i)
    {
        scanf("%lld %c",a+i,c+i);
    }
    int l=1,r=n;
    while(l<r)
    {
        if(a[l]==a[r])
        {
            if(c[l]!=c[r])
            {
                sum+=a[l];
            }
            ++l,--r;
        }
        else if(a[l]<a[r])
        {
            if(c[l]!=c[r])
            {
                sum+=a[l];
            }
            a[r]-=a[l];
            ++l;
        }
        else
        {
            if(c[l]!=c[r])
            {
                sum+=a[r];
            }
            a[l]-=a[r];
            --r;
        }
    }
    printf("%lld",sum);
    return 0;
}

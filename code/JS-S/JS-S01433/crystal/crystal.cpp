#include<bits/stdc++.h>
#define lc p<<1
#define rc p<<1|1
using namespace std;
const int N=6e5+1;

long long a[N],m;
long long s[N];
int n;

inline bool check(int sum)
{
    for(int i=sum;i<=n;i++)
    {
        long long daijia=(sum-1)*a[i]-(s[i-1]-s[i-sum]);
        if(daijia<=m)
        {
            return 1;
        }
    }
    return 0;
}

int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d%lld",&n,&m);
    for(register int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)
    {
        s[i]=s[i-1]+a[i];
    }
    int l=0,r=n+1;
    while(l<r)
    {
        int mid=(l+r)>>1;
        if(check(mid))
        {
            l=mid;
        }
        else
        {
            r=mid-1;
        }
    }
    printf("%d",l);
    return 0;
}

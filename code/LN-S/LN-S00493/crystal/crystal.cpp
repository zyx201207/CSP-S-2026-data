#include <bits/stdc++.h>
using namespace std;
int n,m;
long long a[500009];
int ans=0;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+1+n);
    long long sum=0;
    int r=1,h=1;
    for(int i=2;i<=n;i++)
    {
        h++;
        sum+=1ll*(h-r)*(a[i]-a[i-1]);
        while(sum>m)
        {
            sum-=a[i]-a[r];
            r++;
        }
        ans=max(ans,h-r+1);
    }
    printf("%d",ans);

    return 0;
}

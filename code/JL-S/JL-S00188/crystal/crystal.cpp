#include<bits/stdc++.h>
using namespace std;
long long a[550000];
int main()
{
    long long n,m;
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1);
    int l;
    int ans=0;
    long long sum=0;
    l=1;
    ans=max(ans,1-l+1);
    for(int i=2;i<=n;i++)
    {
        sum+=((i-1)-l+1)*(a[i]-a[i-1]);
        while(sum>m)
        {
            sum-=(a[i]-a[l]);
            l++;
        }
        ans=max(ans,i-l+1);
    }
    printf("%d",ans);
}

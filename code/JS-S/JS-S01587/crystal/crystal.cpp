#include<bits/stdc++.h>
using namespace std;
long long m,a[500500],s,an,q,ans,n;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","r",stdout);
    scanf("%lld%lld",&n,&m);
    s=m;an=1;
    for(int i=0;i<n;i++)
        scanf("%lld",&a[i]);
    sort(a,a+n);
    for(int i=1;i<n;i++)
    {
        while(an*(a[i]-a[i-1])>s)
        {
            s+=a[i-1]-a[q];
            q++;
            an--;
        }
        s-=an*(a[i]-a[i-1]);
        an++;
        ans=max(ans,an);
    }
    printf("%lld",ans);
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int n;
long long m,a[500005];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d %lld",&n,&m);
    for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    int l=1,r=1,ans=1;
    long long k=0;
    while(r<n)
    {
        r++;
        k+=1ll*(r-l)*(a[r]-a[r-1]);
        while(k>m)
        {
            k-=a[r]-a[l];
            l++;
        }
        ans=max(ans,r-l+1);
    }
    printf("%d\n",ans);
    return 0;
}

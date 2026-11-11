#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n;
long long m,a[N];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d%lld",&n,&m);
    for(int i=1; i<=n; i++)
        scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    int ans=0,l=n;
    long long sum=0;
    for(int i=n; i>=1; i--)
    {
        while( l>1 && sum+a[i]-a[l-1]<=m )
            l--,sum+=a[i]-a[l];
        ans=max(ans,i-l+1);
        sum-=1ll*(i-l)*(a[i]-a[i-1]);
    }
    printf("%d\n",ans);
    return 0;
}

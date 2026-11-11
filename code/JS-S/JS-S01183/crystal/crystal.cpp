#include<bits/stdc++.h>
#define ll long long

using namespace std;

const int N=5e5+10;
int n;
ll m;
ll a[N];
ll sum[N];
int ans;

int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d%lld",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
        sum[i]=sum[i-1]+a[i];
    for(int l=1,r=0;l<=n;l++)
    {
        while(r<n&&a[r+1]*(r+1-l+1)-(sum[r+1]-sum[l-1])<=m)
            r++;
        ans=max(ans,r-l+1);
    }
    printf("%d\n",ans);
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
long long a[500010],m,sum[500010];
int n;

int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    int ans=0;
    for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
    for(int i=1;i<=n;i++)
    {
        int ansnow,l=1,r=i;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if((i-mid+1)*a[i]-(sum[i]-sum[mid-1])<=m) ansnow=i-mid+1,r=mid-1;
            else l=mid+1;
        }
        ans=max(ans,ansnow);
    }

    cout<<ans;
    return 0;
}

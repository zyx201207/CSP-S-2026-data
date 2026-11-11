#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500010];
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)a[i]+=a[i-1];
    int ans=0;
    for(int i=2;i<=n;i++)
    {
        int l=0,r=i;
        while(l<r)
        {
            int mid=l+r>>1;
            if((a[i]-a[i-1])*(i-mid+1)-a[i]+a[mid-1]>m)
            {
                l=mid+1;
            }
            else
            {
                r=mid;
            }
        }
        ans=max(i-r+1,ans);
    }
    cout<<ans;
return 0;
}
/*++rp*/

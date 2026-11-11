#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],ans=0,s[500005];
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
    for(int i=1;i<=n;i++)
    {
        int l=1,r=i,t=0;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(a[i]*mid-(s[i]-s[i-mid])<=m) l=mid+1,t=mid;
            else r=mid-1;
        }
        ans=max(ans,t);
    }
    cout<<ans<<"\n";
    return 0;
}

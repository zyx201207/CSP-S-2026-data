#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010];
#define int long long
bool chack(int mid)
{
    int ans=0;
    for(int i=1;i<mid;i++)
    {
        ans+=(a[mid]-a[i]);
    }
    return ans<=m;
}
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int l=1,r=n,ans=0;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(chack(mid))
        {
            ans=mid;
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
    cout<<ans;
    return 0;
}

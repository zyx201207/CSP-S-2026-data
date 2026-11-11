#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5,inf=0x3f3f3f3f;
int n,m,a[N],l=1,r,ans;
bool check(int x)
{
    int res=0;
    for(int i=1;i<=x;i++)
        res+=a[i];
    for(int i=1;i<=n-x+1;i++)
    {
        if(a[i+x-1]*x<=res+m)
            return 1;
        res=res-a[i]+a[i+x];
    }
    return 0;
}
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    r=n;
    while(l<=r)
    {
        int mid=(l+r)>>1;
        if(check(mid))
        {
            ans=mid;
            l=mid+1;
        }
        else
            r=mid-1;
    }
    cout<<ans<<endl;
    return 0;
}

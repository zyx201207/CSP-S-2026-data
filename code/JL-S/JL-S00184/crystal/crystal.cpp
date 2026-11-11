#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,a[N];
int c[N],q[N],qs[N],ans=1;
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<n;i++) c[i]=a[i+1]-a[i];
    for(int i=1;i<n;i++) q[i]=q[i-1]+c[i];
    for(int i=1;i<n;i++) qs[i]=qs[i-1]+i*c[i];
    for(int i=2;i<=n;i++)
    {
        int l=1,r=i-1,mid;
        while(l<r)
        {
            mid=(l+r)>>1;
            int res=qs[i-1]-qs[mid-1]-(mid-1)*(q[i-1]-q[mid-1]);
            if(res<=m) ans=max(ans,i-mid+1),r=mid-1;
            else l=mid+1;
        }
        int res=qs[i-1]-qs[l-1]-(l-1)*(q[i-1]-q[l-1]);
        if(res<=m) ans=max(ans,i-l+1);
    }
    cout<<ans<<"\n";
    return 0;
}

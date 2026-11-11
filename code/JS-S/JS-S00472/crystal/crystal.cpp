#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int M=5e5+10;
int n;
ll m;
ll a[M];
ll q[M];
int ans;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;++i) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;++i) q[i]=q[i-1]+a[i];
    for(int i=1;i<=n;++i)
    {
        int l=i,r=n;
        while(l<r)
        {
            int mid=(l+r+1)/2;
            if((ll)(mid-i+1)*a[mid]-(q[mid]-q[i-1])>m) r=mid-1;
            else l=mid;
        }
        //cout<<l<<endl;
        ans=max(ans,l-i+1);
    }
    cout<<ans<<endl;
    return 0;
}

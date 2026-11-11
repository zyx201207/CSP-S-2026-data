#include <bits/stdc++.h>
using namespace std;
#define int long long

int n,m,a[500010],cnt,ans,pre[500010];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(),cout.tie();

    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);a[0]=a[1];
    for (int i=1;i<=n;i++) {a[i]=a[i]-a[0];pre[i-1]=a[i];}
    // for (int i=1;i<=n;i++) cout<<i<<" "<<a[i]<<" ";cout<<"\n";
    // for (int i=1;i<n;i++) cout<<pre[i]<<" ";cout<<"\n";
    for (int i=1;i<n;i++) a[i]=a[i+1]-a[i];
    int l=1,r=1;
    while (l<=r && r<n) {
        cnt+=a[r]*(r-l+1);
        // cout<<l<<" "<<r<<" ";
        if (cnt<=m) ans=max(ans,r++-l+2);
        else {
            cnt-=pre[r]-pre[l-1]+a[r]*(r-l);
            if (l++==r) r++;
        }
        // cout<<cnt<<" "<<ans<<"\n";
    }
    cout<<ans<<"\n";
    // for (int i=1;i<n;i++) cout<<i<<" "<<a[i]<<" ";cout<<"\n";
    // for (int i=1;i<n;i++) {
    //     cnt+=a[i];
    //     // cout<<cnt<<" "<<cnt2<<"\n";

    //     if (cnt>m) {
    //         cout<<i<<"\n";
    //         return 0;
    //     }
    // }
    return 0;
}
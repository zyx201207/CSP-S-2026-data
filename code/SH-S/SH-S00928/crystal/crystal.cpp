#include<bits/stdc++.h>
using namespace std;
const int N=500010; long long a[N],sum[N];
int main() {
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(nullptr);
    int n; long long m; cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1); int mx=0;
    for(int i=1;i<=n;i++) {
        sum[i]=sum[i-1]+a[i];
        int l=1,r=i,ans=i+1;
        while(l<=r) {
            int mid=(l+r)>>1;
            if((i-mid+1)*a[i]-(sum[i]-sum[mid-1])<=m) ans=mid,r=mid-1;
            else l=mid+1;
        }
        mx=max(mx,i-ans+1);
    }
    cout<<mx;
    return 0;
}

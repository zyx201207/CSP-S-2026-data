#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m;
int a[N];
int ans=0;
int sum[N];

signed main() {
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
    for(int i=1;i<=n;i++) {
        int l=1,r=i,res=i;
        while(l<=r) {
            int mid=l+r>>1;
            if(sum[i]-sum[mid-1]+m>=(i-mid+1)*a[i]) {
                res=mid,r=mid-1;
            }
            else {
                l=mid+1;
            }
        }
        ans=max(ans,i-res+1);
    }
    cout<<ans<<'\n';
    return 0;
}
/*

5 8
-3 -1 2 2 7

*/

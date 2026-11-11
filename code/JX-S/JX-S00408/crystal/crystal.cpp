#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
int n;
ll m, a[500005], ans, sum[500005];
bool check(ll x) {
    for (int i=1; i+x-1<=n; i++) {
        if (sum[i+x-1]-sum[i-1]+m >= a[i+x-1]*x) {
            //cout<<"x: "<<x<<" i:"<<i<<"\n";
            return 1;
        }
    }
    return 0;
}
signed main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin>>n>>m;
    for (int i=1; i<=n; i++) cin>>a[i];
    for (int i=1; i<=n; i++) sum[i]=sum[i-1]+a[i];
    sort(a+1, a+1+n);
    ll l=1, r=5e5;
    while (l<=r) {
        ll mid=(l+r)/2;
        if (check(mid)) l=mid+1;
        else r=mid-1;
    }
    cout<<l-1;
    return 0;
}
//3845

#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
const int maxn = 5e5 +10;
int a[maxn],sum[maxn];
int l = 1,r,ans;

signed main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for(int i = 1 ; i <= n ; i ++) cin >> a[i];
    sort(a + 1,a + 1 + n);
    for(int i = 1 ; i <= n ; i ++) sum[i] = sum[i - 1] + a[i];
    while(r <= n) {
        while(l < r && ((r - l + 1) * a[r] - (sum[r] - sum[l - 1]) > m) ) {
            ++ l;
        }
        ans = max(ans,r - l + 1);
        ++ r;
    }
    cout << ans;
    return 0;
}

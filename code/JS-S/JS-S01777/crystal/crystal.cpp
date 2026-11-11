#include<bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll N=5e5+5;
ll ans=0, n, m, a[N], s[N];
int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out","w",stdout);
    cin.tie(0),cout.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for(int i=1; i<=n; i++) cin >> a[i];
    sort(a+1,a+n+1);
    for(int R=1; R<=n; R++) {
        s[R]=s[R-1]+a[R];
        ll l=1,r=R, L=0;
        while(l<r) {
            L=l+r>>1;
            if((R-L+1)*a[R]-s[R]+s[L-1] <= m) {
                r=L;
            }else {
                l=L+1;
            }
        }
        ans = max(ans, R-l+1);
    }
    cout << ans;
    return 0;
}

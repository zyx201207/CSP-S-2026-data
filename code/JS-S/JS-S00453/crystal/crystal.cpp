#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long var;
constexpr int MAX_N = 500010;

var n, m;
var a[MAX_N];
var sum[MAX_N];

bool check(const var L, const var R, const var x) {
    if(x * (R-L+1) - (sum[R]-sum[L-1]) <= m) {
        return true;
    }
    return false;
}

int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    
    // cin >> n >> m;
    scanf("%lld%lld", &n, &m);
    // for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=n;i++) scanf("%lld", &a[i]);
    sort(a+1, a+n+1);
    for(int i=1;i<=n;i++) sum[i] = sum[i-1] + a[i];
    
    var res = 0;
    for(int i=1;i<=n;i++) {
        const var x = a[i];
        var l = 1, r = n, ans = -1;
        while(l <= r) {
            const var mid = (l + r) >> 1;

            if(check(mid, i, x)) {
                // TODO
                r = mid - 1;
                ans = mid;
            } else {
                l = mid + 1;
            }
        }
        // cout << ans << "?\n";
        if(ans != -1)
            res = max(res, i - ans + 1);
    }
    // cout << res;
    printf("%lld", res);

    fclose(stdin);
    fclose(stdout);
    return 0;
}
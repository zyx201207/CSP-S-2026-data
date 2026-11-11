#include<bits/stdc++.h>
using namespace std;
#define int long long

int n, m, a[500005], s[500005];

bool check(int k) {
    for(int i = k ; i <= n ; i++)
        if(a[i] * (k - 1) - (s[i - 1] - s[i - k]) <= m)
            return 1;
    return 0;
}

signed main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    cin >> n >> m;
    s[0] = 0;
    for(int i = 1 ; i <= n ; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for(int i = 1 ; i <= n ; i++) {
        s[i] = s[i - 1] + a[i];
    }

    int l = 1, r = n, mid, ans = 1;
    while(l <= r) {
        mid = l + ((r - l) >> 1);
        if(check(mid)) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    cout << ans << endl;

    return 0;
}

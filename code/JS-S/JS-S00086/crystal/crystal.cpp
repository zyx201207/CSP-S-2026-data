#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 5e5 + 10;
ll n, m, a[maxn], sum[maxn], ans, q[maxn];
ll finds(int x) {
    ll l = 1, r = x, mid, res = -1, tmp;
    while(l <= r) {
        mid = (l + r) >> 1;
        tmp = sum[x] - sum[mid] - (q[mid] - (mid - 1) * (a[n] - a[x]));
        if(tmp > m) l = mid + 1;
        else {
            res = x - mid + 1;
            r = mid - 1;
        }
    }
    return res;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    for(int i = 2; i <= n; i++) {
        sum[i] = (a[i] - a[i - 1]) * (i - 1);
        sum[i] += sum[i - 1];
        q[i] = (a[n] - a[i]) * (i - 1);
    }
    for(int i = 1; i <= n; i++) {
        ans = max(ans, finds(i));
    }
    cout << ans;
    return 0;
}

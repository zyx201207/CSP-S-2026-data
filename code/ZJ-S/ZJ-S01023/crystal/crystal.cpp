#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 500005;
int n;
ll m, a[maxn], pre[maxn];
bool check(int pos, ll x, int poss) {
    x = x * 1ll * (poss - pos);
    ll need = pre[poss - 1] - pre[pos - 1];
    ll d = x - need;
    if (d <= m) return true;
    else return false;
}
int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) pre[i] = pre[i - 1] + a[i];
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int l = 1, r = i - 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (check(mid, a[i], i)) r = mid;
            else l = mid + 1; 
        }
        // cout << l << " " << r << '\n';
        ans = max(ans, i - l + 1);
    }
    cout << ans << '\n';
    return 0;
}
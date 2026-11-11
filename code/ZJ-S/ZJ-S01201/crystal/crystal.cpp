#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector<ll> num;
int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    ll n, k;
    cin >> n >> k;
    num.resize(n + 1);
    for (ll i = 1; i <= n; i++) {
        cin >> num[i];
    }
    sort(num.begin() + 1, num.end());
    ll cnt = 0, ans = 0;
    ll l = 1, r = 0;
    while (r <= n && l <= n) {
        while(r < n && (num[r + 1] - num[r]) * (r - l + 1) + cnt <= k) {
            cnt += (num[r + 1] - num[r]) * (r - l + 1); 
            r++;
        }
        ans = max(ans, r - l + 1);
        cnt = cnt - num[r] + num[l];
        l++;
    }
    cout << ans << '\n';
    return 0;
}
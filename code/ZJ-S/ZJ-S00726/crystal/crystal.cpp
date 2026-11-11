#include <bits/stdc++.h>
using std::cin; using std::cout; using std::cerr; using std::string; using std::endl; using std::vector; using std::min; using std::max; using std::sort;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    ll n, m;
    cin >> n >> m;
    vector <ll> nums(n, 0);
    vector <ll> sum_nums(n, 0);
    for (ll i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end());
    sum_nums[0] = nums[0];
    for (ll i = 1; i < n; ++i) {
        sum_nums[i] = sum_nums[i - 1] + nums[i];
    }
    
    ll ans = 1;
    for (ll i = 0; i < n; ++i) {
        ll l = 0, r = i;
        if (i == 0) ans = max(ans, 1LL);
        else {
            while (l <= r) {
                ll mid = l + ((r - l) >> 1);
                ll t = nums[i] * (i - mid) - sum_nums[i - 1];
                if (mid != 0) t += sum_nums[mid - 1];
                if (t > m) l = mid + 1;
                else r = mid - 1;
            }
            ans = max(ans, i - l + 1);
        }
    }
    cout << ans;

    return 0;
}
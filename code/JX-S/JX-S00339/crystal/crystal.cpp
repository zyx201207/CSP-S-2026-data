#include <bits/stdc++.h>
#define ll long long 
#define ull unsigned long long 
#define i128 __int128
#define fi first
#define se second
#define PII pair<int, int>
#define PLL pair<ll, ll>
#define INF 0x3f3f3f3f
#define INFx 0x3f3f3f3f3f3f3f3f
using namespace std;

const int N = 5e5 + 10;

int n;
ll m;
ll a[N];
vector<ll> lsh;
ll cnt[N], sum[N];

ll calc(ll x, int i, int j) {
    return x * (cnt[i] - cnt[j]) - (sum[i] - sum[j]);
}

int main() {
    freopen("crystal.in", "r", stdin); // modify!!!
    freopen("crystal.out", "w", stdout); // modify!!!
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        lsh.push_back(a[i]);
    }  

    sort(lsh.begin(), lsh.end());
    lsh.erase(unique(lsh.begin(), lsh.end()), lsh.end());

    for (int i = 1; i <= n; i++) {
        a[i] = lower_bound(lsh.begin(), lsh.end(), a[i]) - lsh.begin() + 1;
        cnt[a[i]]++, sum[a[i]] += lsh[a[i] - 1];
    }

    ll ans = 0;
    for (int i = 1; i <= lsh.size(); i++) {
        cnt[i] += cnt[i - 1];
        sum[i] += sum[i - 1];

        ll x = lsh[i - 1];
        int l = 1, r = i;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (calc(x, i, mid - 1) <= m) r = mid;
            else l = mid + 1;
        }

        ll res = m - calc(x, i, l - 1);
        if (l > 1) {
            ll y = lsh[l - 2];
            ans = max(ans, cnt[i] - cnt[l - 1] + res / (x - y));
        }
        else ans = max(ans, cnt[i]);
    }

    cout << ans << '\n';

    return 0;
}

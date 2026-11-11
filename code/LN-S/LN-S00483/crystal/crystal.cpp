# include <algorithm>
# include <iostream>
# include <vector>

using std::cin;
using std::cout;
using std::vector;

typedef long long ll;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    std::freopen("crystal.in", "r", stdin);
    std::freopen("crystal.out", "w", stdout);

    int n;
    ll m;
    cin >> n >> m;

    vector<ll> seq(n);

    for (auto &a: seq) {
        cin >> a;
    }

    std::sort(seq.begin(), seq.end());

    vector<ll> pre(n + 1, 0);

    for (int i = 0; i < n; ++i) {
        pre[i + 1] = pre[i] + seq[i];
    }

    auto chk = [&](int l, int i) -> bool {
        return seq[i] * (i - l) - (pre[i] - pre[l]) <= m;
    };

    int ans = 0;

    for (int i = 0; i < n; ++i) {
        int s = 0, t = i;

        while (s < t) {
            int mid = s + ((t - s) >> 1);
            if (chk(mid, i)) {
                t = mid;
            } else {
                s = mid + 1;
            }
        }

        ans = std::max(ans, i - s + 1);
    }

    cout << ans;

    return 0;
}


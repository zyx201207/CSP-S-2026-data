#include <algorithm>
#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using ll = long long;

const int N = 5e5 + 5;
int n, ans;
ll m;
ll a[N], sum[N];

int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    std::sort(a + 1, a + n + 1);

    for (int i = 1; i <= n; ++i) {
        sum[i] = sum[i - 1] + a[i];

        int l = 1, r = i;
        while(l < r) {
            int mid = (l + r) >> 1;

            if ((i - mid) * a[i] - (sum[i - 1] - sum[mid - 1]) <= m)
                r = mid;
            else
                l = mid + 1;
        }

        ans = std::max(ans, i - r + 1);
    }

    cout << ans << '\n';
}


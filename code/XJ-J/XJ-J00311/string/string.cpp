#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using ll = long long;

int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);

    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    std::vector<int> a(n + 1);
    std::vector<char> c(n + 1);

    ll len = 0;
    for (int i = 1; i <= n; ++i)
        cin >> a[i] >> c[i], len += a[i];

    ll pos = 0, ans = 0;
    int i = 1, j = n;
    for (; pos <= (len >> 1); ++i) {
        if (pos + a[i] > (len >> 1))
            break;
        int s = a[i], sum = a[i];
        while(s > 0 && s - a[j] >= 0) {
            s -= a[j];
            sum -= (c[j] == c[i]) * a[j--];
        }
        if (s > 0)
            sum -= (c[j] == c[i]) * s, a[j] -= s;
        ans += sum;
        pos += a[i];
    }

    if (pos < (len >> 1)) {
        int s = (len >> 1) - pos;
        int sum = s;
        while(s > 0 && s - a[j] >= 0) {
            s -= a[j];
            sum -= (c[j] == c[i]) * a[j--];
        }
        if (s > 0)
            sum -= (c[j] == c[i]) * s, a[j] -= s;
        ans += sum;
    }

    cout << ans << '\n';
}

#include <bits/stdc++.h>
using namespace std;

constexpr int N = 5e5 + 5;

long long a[N], sums[20][N];

int main () {

    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    int lg = __lg(n);
    for (int i = 1; i <= lg; i++) {
        for (int j = 1; j + (1 << i) - 1 <= n; j++) {
            sums[i][j] = sums[i - 1][j] + sums[i - 1][j + (1 << i - 1)] +
                    (a[j + (1 << i) - 1] - a[j + (1 << i - 1) - 1]) * (1 << i - 1);
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int x = i; long long rem = m;
        for (int j = lg; ~j; j--) {
            if (x + (1 << j) - 1 > n) continue;
            long long need = sums[j][x] + (x - i) *
                    (a[x + (1 << j) - 1] - a[x - 1]);
            if (need <= rem) {
                rem -= need;
                x += 1 << j;
            }
        }
        ans = max(ans, x - i);
    }
    cout << ans;
    return 0;
}

// ming yun yi ran zhu ding
// nu li jie zai dang jin

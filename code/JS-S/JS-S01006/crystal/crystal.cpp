#include <bits/stdc++.h>
using namespace std;

const int N = 5e5+10;

long long n, m;
long long a[N], r[N];


int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    r[1] = 0;
    for (int i = 2; i <= n; i ++) {
        r[i] = r[i - 1] + (a[i] - a[i - 1]) * (i - 1);
    }
    int ans = 1;
    for (int i = 1, j = 1; i <= n && j <= n; i ++, j ++) {
        for (; j <= n; j ++) {
            if (r[j] - r[i] - (i - 1) * (a[j] - a[i]) > m) {
                j --;
                break;
            }
            if (j - i + 1 > ans) ans = j - i + 1;
        }
    }
    cout << ans;
    return 0;
}

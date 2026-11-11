#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

long long a[500010], c[500010];

int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    long long m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1, greater<long long>());
    for (int i = n - 1; i >= 1; i--) {
        c[i] = a[i] - a[i + 1];
    }
    int lst = n, ans = 1;
    long long lstv = 0, sum = 0;
    for (int i = n - 1; i >= 1; i--) {
        lstv += (lst - i) * c[i];
        sum += c[i];
        if (lstv <= m) {
            ans = max(ans, lst - i + 1);
        }
        else {
            while (lstv > m && lst >= 1) {
                lstv -= sum;
                sum -= c[--lst];
            }
            if (lst < 1) {
                break;
            }
            ans = max(ans, lst - i + 1);
        }
    }
    cout << ans;
    return 0;
}

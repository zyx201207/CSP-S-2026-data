#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, a[N];
long long cnt;
char c[N];
int main() {
    freopen ("string.in", "r", stdin);
    freopen ("string.out", "w", stdout);
    cin >> n;
    bool flag = false;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> c[i];
        if (c[i] != c[1]) flag = true;
        cnt += a[i];
    }
    if (!flag) {
        cout << 0 << endl;
        return 0;
    }
    long long ans = 0;
    for (int i = 1, j = n; i < j; ) {
        if (cnt <= 0) break;
        if (a[i] >= a[j]) {
            if (c[i] != c[j]) ans += a[j];
            cnt -= a[j] * 2;
            a[i] -= a[j];
            a[j] = 0;
            j--;
        } else {
            if (c[i] != c[j]) ans += a[i];
            cnt -= a[i] * 2;
            a[j] -= a[i];
            a[i] = 0;
            i++;
        }
    }
    cout << ans << endl;
    return 0;
}
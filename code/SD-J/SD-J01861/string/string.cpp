#include <iostream>
#include <cstdio>
using namespace std;

int a[200010];
char c[200010];

int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    long long sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> c[i];
        sum += a[i];
    }
    int l = 1, r = n;
    long long cntl = 0, cntr = 0, ans = 0;
    while (sum - (cntl + cntr) > 1) {
        if (a[l] > a[r]) {
            ans += a[r] * (c[l] != c[r]);
            cntl += a[r];
            cntr += a[r];
            a[l] -= a[r--];
        }
        else if (a[l] < a[r]) {
            ans += a[l] * (c[l] != c[r]);
            cntl += a[l];
            cntr += a[l];
            a[r] -= a[l++];
        }
        else {
            ans += a[l] * (c[l] != c[r]);
            cntl += a[l++];
            cntr += a[r--];
        }
    }
    cout << ans;
    return 0;
}

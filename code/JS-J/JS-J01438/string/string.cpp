#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
long long a[N];
char c[N];

int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> c[i];
    }
    int l = 1, r = n;
    long long ans = 0;
    while (l <= r) {
        long long sum = a[r];
        if (c[l] != c[r]) {
            ans += a[r];
        }
        while (sum < a[l]) {
            r--;
            sum += a[r];
            if (c[l] != c[r]) {
                ans += a[r];
            }
        }
        if (sum > a[l]) {
            a[r] = sum - a[l];
            if (c[l] != c[r]) {
                ans -= a[r];
            }
        } else if (sum == a[l]) {
            r--;
        }
        l++;
    }
    cout << ans;

    return 0;
}

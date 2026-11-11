#include<bits/stdc++.h>
using namespace std;
long long n, ans;
long long a[200010];
char c[200010];
int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        cin >> c[i];
    }
    for (int i = 1, j = n; i < j; i++) {
        long long nw = a[i];
        while (nw > 0 && j > i) {
            if (c[i] == c[j]) {
                if (nw < a[j]) {
                    a[j] -= nw;
                    nw = 0;
                } else {
                    nw -= a[j];
                    a[j] = 0;
                    j--;
                }
            } else {
                if (nw < a[j]) {
                    ans += nw;
                    a[j] -= nw;
                    nw = 0;
                } else {
                    ans += a[j];
                    nw -= a[j];
                    a[j] = 0;
                    j--;
                }
            }
        }
    }
    cout << ans;
    return 0;
}
// red

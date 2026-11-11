#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 200007;

int n;
int a[N];
char c[N];
ll ans = 0;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> c[i];
    }

    int l = 1, l_rst = a[1];
    int r = n, r_rst = a[n];
    while (l <= r) {
        if (l_rst == r_rst) {
            if (c[l] != c[r]) {
                ans += l_rst;
            }
            l ++; l_rst = a[l];
            r --; r_rst = a[r];
            continue;
        }

        if (l_rst > r_rst) {
            if (c[l] != c[r]) {
                ans += r_rst;
            }
            l_rst -= r_rst;
            r --; r_rst = a[r];
        } else {
            if (c[l] != c[r]) {
                ans += l_rst;
            }
            r_rst -= l_rst;
            l ++; l_rst = a[l];
        } 
    }

    cout << ans << "\n";
    return 0;
}
#include <iostream>
#include <cstdio>
#include <string>

#include <cmath>
using namespace std;
using ll = long long;
ll n, a[200005], ans = 0;
string s = "";
char c[200005], piv; bool is = true;

int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> c[i]; // hope to AC!
        if (i == 1) {
            piv = c[i];
        } else {
            if (c[i] != piv && is) {
                is = false;
            }
        }
    }

    if (is) {
        cout << 0; return 0;
    }

    for (int i = 1, j = n; ; ) {
        if (i >= j) {
            break;
        }
        if (c[i] != c[j]) {
            if (a[i] == a[j]) {
                ans += a[i];
            } else {
                ans += abs(a[i] - a[j]);
            }
        }
        if (a[i] > a[j]) {
            a[j - 1] -= (a[i] - a[j]);
            a[i] -= (a[i] - a[j]);
            j = j - (a[i] - a[j]);
        } else if (a[i] < a[j]) {
            a[i + 1] -= (a[j] - a[i]);
            a[j] -= (a[j] - a[i]);
            i = i - (a[j] - a[i]);
        } else {
            i++, j--;
        }
        //cout << ans << ' ';
    }
    cout << ans;
    return 0;
}

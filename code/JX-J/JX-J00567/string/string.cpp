#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long LL;

const int N = 200005;

/*int n, a[N];
LL ans, pos[N];
char c[N];

int main() {
    // freopen("string.in", "r", stdin);
    // freopen("string.out", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i] >> c[i];

    for (int i = 1; i <= n; i++) pos[i] = pos[i - 1] + a[i];

    if (pos[n] & 1) {
        LL mid = pos[n] / 2 + 1;

        for (int i = 1; i <= n; i++) {
            if (pos[i] >= mid) {
                LL l = mid - pos[n - 1] -1, r = pos[n - 1] - mid;
                if (r == 0 && c[i] != c[i + 1]) ans += l;
                if (l != 0 && r != 0) ans += abs(r - l);

                break;
            }

            LL j = n - i + 1;
            LL l = pos[i] - pos[i - 1], r = pos[j] - pos[j - 1];

            if (c[i] != c[j]) {
                if (pos[j] >= mid && pos[j - 1] < mid) {
                    ans += r - 1;
                    break;
                }
                if (l >= r) ans += l, pos[j - 1] -= l - r;
                if (l < r) ans += r, pos[i] += r - l;
            }
        }
    }

    cout << ans;

    return 0;
}*/
int n, ans, a[N];
char c[N];
string s = "";

int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i] >> c[i];

    for (int i = 1; i <= n; i++) s += string(a[i], c[i]);
    int L = s.size();
    s = " " + s;
    for (int i = 1; i <= (L + 1) / 2; i++)
        if (s[i] != s[L + 1 - i])
            ans++;

    cout << ans;

    return 0;
}

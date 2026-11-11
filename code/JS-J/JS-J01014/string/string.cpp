#include <iostream>
#include <cmath>
using namespace std;

const int N = 2e5 + 5;

int n;
long long ans;
int a[N], b[N];
char c[N], d[N];

int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> c[i];
    }
    for (int i = 1; i <= n; i++) {
        b[i] = a[n - i + 1];
        d[i] = c[n - i + 1];
    }

    //for (int i = 1; i <= n; i++) {
    //    cout << a[i] << ' ' << c[i] << endl;
    //}
    //for (int i = 1; i <= n; i++) {
    //    cout << b[i] << ' ' << d[i] << endl;
    //}

    long long i = 1, j = 1, l = 0, r = 0, nl, nr;
    while (true) {
        nl = max(l, r);
        nr = min(l + a[i], r + b[j]);
        if (c[i] != d[j]) {
            //cout << i << ' ' << j << endl;
            ans += nr - nl;
        }
        //cout << i << ' ' << j << ' ' << l << ' ' << r << ' ' << nl << ' ' << nr << ' ' << ans << endl;
        if (i == n && j == n) {
            break;
        } else if (i == n) {
            r += b[j];
            j++;
        } else if (j == n) {
            l += a[i];
            i++;
        } else if (l + a[i] >= r + b[j]) {
            r += b[j];
            j++;
        } else {
            l += a[i];
            i++;
        }
    }

    cout << ans / 2 << endl;
    return 0;
}

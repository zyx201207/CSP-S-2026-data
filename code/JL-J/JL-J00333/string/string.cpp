#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int n;
int a[N];
char c[N];
long long len = 0;

long long huiwen() {
    int l = 1, zl = 1, r = a[n], zr = n;
    long long k = 0;
    for (long long i = 1; i <= len / 2; i++) {
        l++;
        r--;
        if (c[zl] != c[zr]) {
            k++;
        }
        if (r == 1) {
            zr--;
            r = a[zr];
        }
        if (l == a[zl]) {
            l = 1;
            zl++;
        }
    }
    return k;
}

void solve() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for (int i  = 1; i <= n; i++) {
        cin >> a[i] >> c[i];
        len += a[i];
    }
    cout << huiwen();

}

int main() {
    int ac = 1;
    // cin >> ac;
    while(ac--) {
        solve();
    }
}

#include <iostream>
#include <algorithm>
using namespace std;

template<typename _Tp>
void read(_Tp& x) {
    x = 0;
    int f = 0, c = getchar();
    while (!isdigit(c)) {
        f |= c == '-', c = getchar();
    }
    while (isdigit(c)) {
        x = x * 10 + (c & 15), c = getchar();
    }
    x = f ? -x : x;
}

int n;
long long m, a[500001];

void solve() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    read(n), read(m);
    for (int i = 1; i <= n; ++i) {
        read(a[i]);
    }
    sort(a + 1, a + n + 1), a[0] = a[1];
    int ans = 0, l = 1, r = 1;
    long long cst = 0;
    for (; r <= n; ++r) {
        cst += 1ll * (r - l) * (a[r] - a[r - 1]);
        while (cst > m and l < r) {
            cst -= a[r] - a[l++];
        }
        ans = max(ans, r - l + 1);
    }
    printf("%d\n", ans);
}

int main() {
    solve();
    return 0;
}
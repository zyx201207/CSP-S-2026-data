#include <bits/stdc++.h>
#define ll long long
using namespace std;

template <typename T> void read(T &x) {
    x = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) f = (ch == '-') ? -1 : f, ch = getchar();
    while (isdigit(ch)) x = x * 10 + (ch & 15), ch = getchar(); x *= f;
}

const int N = 500005;
int n; ll m, a[N];

signed main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
//    freopen("crystal4.in", "r", stdin);
//    freopen("my-crystal.out", "w", stdout);
    
    read(n), read(m);
    for (int i = 1; i <= n; i++) read(a[i]);
    sort(a + 1, a + n + 1);
    ll cst = 0; int ans = 0;
    for (int i = 1, j = 1; i <= n; i++) {
        while (j < i && cst > m) cst -= (a[i] - a[j]), j++;
        ans = max(ans, i - j + 1);
        if (i < n) cst += (i - j + 1) * (a[i + 1] - a[i]);
    }
    printf("%d", ans);
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

ifstream inf("crystal.in");
ofstream ouf("crystal.out");

#define vec vector
using i64 = long long;

int main() {
    ios::sync_with_stdio(false), inf.tie(nullptr);

    int n; i64 m;
    inf >> n >> m;
    vec<i64> a(n + 1);
    for (int i = 1; i <= n; ++i) inf >> a[i];

    sort(a.begin() + 1, a.end());
    i64 sum = 0; int p = 1;
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        sum += a[i];
        while (p < i && a[i] * (i - p + 1) - sum > m)
            sum -= a[p], ++p;
        ans = max(ans, i - p + 1);
    }
    ouf << ans << "\n";

    ouf.flush();
    return 0;
}
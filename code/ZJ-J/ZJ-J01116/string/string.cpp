#include <iostream>
#include <cstdio>
#include <algorithm>
using quad = long long;
using namespace std;

constexpr quad N = 2e5 + 1;
quad n;
quad a[N];
quad pa[N];
char c[N];
quad cnt;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for (quad i = 1; i <= n; ++i) {
        cin >> a[i] >> c[i];
        pa[i] = a[i] + pa[i - 1];
    }
    const quad mid = pa[n] >> 1;
    quad cnt = 1;
    quad lit = 1;
    quad rit = n;
    quad ans = 0;
    while (cnt <= mid && lit != rit) {
        const quad mn = min(a[lit], a[rit]);
        if (c[lit] != c[rit]) {
            ans += mn;
        }
        a[lit] -= mn;
        a[rit] -= mn;
        if (a[lit] == 0) {
            ++lit;
        }
        if (a[rit] == 0) {
            --rit;
        }
        cnt += mn;
    }
    cout << ans << '\n';
    cout.flush();
    fclose(stdin);
    fclose(stdout);
    return 0;
}
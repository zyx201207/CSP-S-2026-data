#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define ull unsigned long long 
#define sqr(x) ((x) * (x))
using namespace std;

constexpr unsigned int NR = 5e5 + 5;
int n;
ll m, a[NR], s[NR];
void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++ i)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; ++ i)
        s[i] = s[i - 1] + a[i];
    auto check = [&](int mid) -> bool {
        for (int i = mid; i <= n; ++ i)
            if (a[i] * mid - (s[i] - s[i - mid]) <= m)
                return 1;
        return 0;
    };
    int l = 1, r = n;
    while (l < r) {
        int mid = (l + r + 1) >> 1;
        if (check(mid))
            l = mid;
        else
            r = mid - 1;
    }
    cout << l << '\n';
}

int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int oT_To = 1;
    // cin >> oT_To;
    while (oT_To --)
        solve();
    return 0; 
}

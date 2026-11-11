#include <bits/stdc++.h>
#define sfr return cout << "safe\n", 0;
#define sf_void return cout << "safe\n", void();
using namespace std;
using ll = long long;
using i128 = __int128;
using pr = pair<int, int>;
#define FILEIO "string"
const int N = 4e5 + 10;

int n, cnt[N], cls[N]; ll S, rS, L, ans;

auto main() -> signed {
    #ifdef FILEIO
        freopen(FILEIO ".in", "r", stdin);
        freopen(FILEIO ".out", "w", stdout);
    #endif
    // sfr
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> n;
    char ch;
    for (int i = 1; i <= n; ++i) cin >> cnt[i] >> ch, cls[i] = ch, L += cnt[i];
    // sfr
    // for (int i = 1; i <= n; ++i) cerr << cls[i] << " \n"[i == n];
    for (int i = 1, j = n, lmt; ; ++i) {
        S += cnt[i]; S = min(S, L / 2); // lmt = L - S + 1;
        ++j;
        while (i < j && rS <= S) {
            rS += cnt[--j];
            int ovr = max(0ll, rS - S);
            rS = min(rS, S);
            if (cls[i] != cls[j]) { ans += cnt[j] - ovr; }
            cnt[j] = ovr;
            if (ovr) break;
            // cerr << j << " " << ans << ": j & ans\n";
        }
        // cerr << i << " " << j << ": i & j\n";
        if (S >= L / 2) break;
        if (i >= j) break;
    }
    cout << ans << "\n";
}
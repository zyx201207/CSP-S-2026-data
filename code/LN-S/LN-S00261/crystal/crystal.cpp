#include <bits/stdc++.h>
#define sfr return cerr << "safe\n", 0;
#define sfv return cerr << "safe\n", void();
using namespace std;
using ll = long long;
using i128 = __int128;
using pr = pair<int, int>;
using prt = tuple<int, int>;
using tpt = tuple<int, int, int>;
#define FILEIO "crystal"
const int N = 5e5 + 10;

int n, ans = 1; ll m, a[N]; i128 jjj[N], jj[N];

// struct BIT {
//     int c[N];
//     auto lowbit(int x) { return x & (-x); }
//     auto add(int p, int k) {
//         for ( ; p > 0; p -= lowbit(p)) c[p] += k;
//     }
//     auto 
// };

deque<int> dq;

auto main() -> signed {
    #ifdef FILEIO
        freopen(FILEIO ".in", "r", stdin);
        freopen(FILEIO ".out", "w", stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = n - 1; i >= 1; --i) {
        jjj[i] = a[i + 1] - a[i];
        jjj[i] += jjj[i + 1];
    }
    for (int i = n - 1; i >= 1; --i) {
        jj[i] = jjj[i] + jj[i + 1];
    }
    dq.emplace_back(1);
    for (int i = 2; i <= n; ++i) {
        while (!dq.empty() && jj[dq.front()] - jj[i] - (i128) (i - dq.front()) * jjj[i] > (i128) m) {
            dq.pop_front();
        }
        if (!dq.empty()) ans = max(ans, i - dq.front() + 1);
        dq.emplace_back(i);
    }
    cout << ans << "\n";
}
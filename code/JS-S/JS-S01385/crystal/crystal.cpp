#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef unsigned long long u64;
typedef long long i64;
typedef unsigned u32;
typedef signed i32;
namespace INIT {
    #define dbg(...) _dbg(#__VA_ARGS__,__VA_ARGS__)
    void _dbg(const char*) {cerr << "\n";}
    template<class T, class ...U>
    void _dbg(const char* s, T x, U... y) {
        while (*s&&*s!=',') cerr << *s++;
        cerr << '=' << x;
        if (*s == ',') {
            cerr << ',';
            _dbg(s + 1, y...);
        } else {
            cerr << '\n';
        }
    }
    template<typename T>
    T mabs(T x) {return x<=0?-x:x;}
}
using namespace INIT;
bool Mbeg;
const int MAX_SIZE = 1024;
const int N(5e5 + 5);
int n, m, a[N], qzh[N];
bool check(int p, int v) {
    int tot = v * a[p];
    int hv = qzh[p] - qzh[p - v];
    return tot - hv <= m;
}
void solve(int tid) {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) qzh[i] = qzh[i - 1] + a[i];
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int l = 1, r = i + 1;
        while (l < r) {
            int mid = l + r >> 1;
            if (check(i, mid)) l = mid + 1;
            else r = mid;
        }
        l--;
        ans = max(ans, l);
    }
    cout << ans << '\n';
}
bool Med;
signed main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin.tie(0), cout.tie(0)->sync_with_stdio(0);
    int T = 1;
    // cin >> T;
    for (int i = 1; i <= T; i++) solve(i);
    return 0;
}
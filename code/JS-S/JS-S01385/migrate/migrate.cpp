#include <bits/stdc++.h>
#define eb emplace_back
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
const int N(2e6 + 15);
int n, D, x[N];
int le[N], ri[N], lp[N], rp[N];
int val[N][2];
void clear() {
    for (int i = 0; i <= n + 5; i++) {
        x[i] = 0;
        le[i] = ri[i] = lp[i] = rp[i] = 0;
    }
    n = D = 0;
}
void sri() {
    int l = 1;
    for (int i = 2; i <= n; i++) {
        while (x[i] - x[l] > D) l++;
        lp[i] = l;
    }
}
void sle() {
    int r = n;
    for (int i = n - 1; i; i--) {
        while (x[r] - x[i] > D) r--;
        rp[i] = r;
    }
}
void solve(int cid) {
    cin >> n >> D;
    for (int i = 1; i <= n; i++) cin >> x[i];
    if (n <= 3) {
        cout << 0 << '\n';
        clear();
        return;
    }
    sle(), sri();
    int ans = 0;
    ///*
    for (int i = 1; i <= n; i++) {
        int p = rp[i], le = p + 1, ri;
        if (p == i + 1) continue;
        if (lp[p - 1] > i) continue;
        if (p > i + 2) le = rp[p - 2] + 1;
        ri = rp[p - 1];
        ans += max(0ll, ri - le + 1);
    }
    for (int a = 1; a <= n; a++) {
        int b = rp[a];
        if (b == a + 1) continue;
        int c = rp[b];
        if (rp[b - 1] < c - 1 || lp[c - 1] > b - 1) continue;
        int rd = rp[c], ld = rp[c - 1] + 1;
        int l1 = rp[c - 2], l2 = rp[c - 1];
        val[a][0] = max(0ll, rd - ld + 1);
        val[a][1] = max(0ll, min(rd, l2) - max(ld, l1 + 1) + 1);
        // assert(val[a][1] == 0);
    }
    //*/
    for (int i = 1; i <= n; i++) {
        int cur = i;
        vector<int> V;
        V.eb(i);
        int typ = 0;
        auto chk = [&](int a, int b, int c) {
            if (rp[b - 2] >= c) return 2;
            if (rp[b - 1] >= c) return 1;
            return 0;
        };
        auto chk2 = [&](int a, int b, int c, int d) {
            if (b == a + 1) return 0;
            if (rp[b - 1] >= c - 1
             && lp[c - 1] <= b - 1 && rp[c - 1] >= d) return 2;
            return 0;
        };
        while (typ <= 1 && cur != n) {
            int rr = rp[cur];
            if (V.size() >= 3)
            for (int j = cur + 1; j <= rr; j++) {
                int sz = V.size();
                int v1 = sz >= 2 ? chk(V[sz - 2], V[sz - 1], j) : 0;
                int v2 = sz >= 3 ? chk2(V[sz - 3], V[sz - 2], V[sz - 1], j) : 0;
                if (typ + v1 + v2 == 1) ++ans;//, dbg(i, j, sz);
            }
            V.eb(rp[cur]);
            if (V.size() >= 3) {
                int sz = V.size();
                typ += chk(V[sz - 3], V[sz - 2], V[sz - 1]);
            }
            if (V.size() >= 4) {
                int sz = V.size();
                typ += chk2(V[sz - 4], V[sz - 3], V[sz - 2], V[sz - 1]);
            }
            cur = rp[cur];
            if (rp[cur] == cur) break;
        }
        // dbg(i, cur, typ);
    }
    cout << ans << '\n';
    clear();
}
bool Med;
signed main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin.tie(0), cout.tie(0)->sync_with_stdio(0);
    int c, T = 1;
    cin >> c >> T;
    for (int i = 1; i <= T; i++) solve(c);
    return 0;
}
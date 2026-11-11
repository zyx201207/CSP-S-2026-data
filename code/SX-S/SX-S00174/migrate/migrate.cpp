#include <bits/stdc++.h>
using namespace std;
template <class T> T lowbit(T x) {return x & -x;}
template <class T> T lg(T x) {return x == 0 ? 0 : __lg(x);}
template <class T> T ctz(T x) {return x == 0 ? 0 : __builtin_ctzll(x);}
#define gcd __gcd
#define popcount __builtin_popcountll
#define fi first
#define se second
using u32 = unsigned int;
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using u128 = unsigned __int128;
mt19937 rand32(time(0));
mt19937_64 rand64(time(0));
template <class T>
ostream& operator<< (ostream& out, const vector<T>& v) {
	out << '['; int n = v.size();
	for (const auto& i : v) out << i << (--n ? ", " : "");
	return out << ']';
}
#undef assert
#ifdef LOCAL
#define FLOCAL(x) freopen(x".in", "r", stdin), freopen(x".out", "w", stdout)
#define FILE(x) void()
#define assert(x) ((x) ? void() : (cerr << "Assertion Failed on Line " << __LINE__ << endl, exit(0)))
#define debug(x) (cerr << "On Line " << __LINE__ << ": " << #x << " = " << (x) << endl)
void _o(auto&&... x) {bool f = 1; ((cerr << (f?"":", ") << x, f = 0), ...);}
#define mdebug(...) (cerr << "On Line " << __LINE__ << ": {" << #__VA_ARGS__ << "} = [", _o(__VA_ARGS__), cerr << "]\n")
#else
#define FILE(x) freopen(x".in", "r", stdin), freopen(x".out", "w", stdout)
#define FLOCAL(x) void()
#define assert(x) void()
#define debug(x) void()
#define mdebug(...) void()
#endif

// #define int long long
const int N = 2e6 + 5, inf = 1e9;
int num, n, to[N]; i64 k, a[N];

using node = pair<int, int>;
const node I = {inf, 0};
node operator+ (const node& a, const node& b) {
    if (a.fi != b.fi) return a.fi < b.fi ? a : b;
    return {a.fi, a.se + b.se};
}

namespace BF {
    const int N = 5005;
    struct segtree {
        #define ls (rt << 1)
        #define rs (rt << 1 | 1)
        node tag[4*N];
        void build(int l = 1, int r = n, int rt = 1) {
            tag[rt] = I;
            if (l == r) return;
            int mid = (l + r) >> 1;
            build(l, mid, ls), build(mid+1, r, rs);
        }
        void update(int tl, int tr, const node& c, int l = 1, int r = n, int rt = 1) {
            if (tl <= l && r <= tr) return tag[rt] = tag[rt] + c, void();
            int mid = (l + r) >> 1;
            if (tl <= mid) update(tl, tr, c, l, mid, ls);
            if (tr > mid) update(tl, tr, c, mid+1, r, rs);
        }
        node ask(int x, int l = 1, int r = n, int rt = 1) {
            if (l == r) return tag[rt];
            int mid = (l + r) >> 1;
            return tag[rt] + (x <= mid ? ask(x, l, mid, ls) : ask(x, mid+1, r, rs));
        }
    } T;
    void _main() {
        int cnt = 0;
        for (int u = 1; u <= n; u++) {
            // fill(f + u, f + n + 1, node{inf, 0});
            T.build(), T.update(u, u, {0, 1});
            for (int v = u; v <= n; v++) {
                auto [d, c] = T.ask(v);
                if (c > 2) continue;
                if (c == 2) cnt++;
                T.update(v+1, to[v], {d+1, c});
                // for (int j = v+1; j <= to[v]; j++) f[j] = f[j] + node{f[v].fi + 1, f[v].se};
            }
        }
        cout << cnt << '\n';
    }
}

// namespace SubA {
//     void _main() {
//         int m = to[1];
//         if (m <= 2) return cout << 0 << '\n', void();
//         m -= 2;
//         int s = 2 * m + 1;
//         if (n < s) return cout << 0 << '\n', void();
//         n = n - s + 1;
//         i64 u = 3 * m + 3, d = 0, cnt = 0;
//         for (int i = 0; i < n; i++) {
//             if (i % u == 0) ++d;
//             cnt += d;
//         }
//         cout << cnt << '\n';
//     }
// }

// namespace SubB {
//     int h[N];
//     void _main() {
//         for (int i = n, j = n; i >= 1; i--) {
//             if (j > i) j = i;
//             while (j > 1 && a[i] - a[j-1] <= k) j--;
//             h[i] = j;
//         }
//         int p = -1;
//         for (int i = 1; i <= n; i++) if (h[i] == 1 && to[i] == n) {
//             p = i; break;
//         }
//         if (p == -1) return cout << -1 << '\n', void();
//         i64 cnt = 0;
//         for (int i = 1; i <= n; i++) cnt += n - to[i];
//         cout << cnt << '\n';
//     }
// }

void _main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1, j = 1; i <= n; i++) {
        if (j < i) j = i;
        while (j < n && a[j+1] - a[i] <= k) j++;
        to[i] = j;
    }
    // if (11 <= num && num <= 12) return SubA::_main(), void();
    if (num <= 10) return BF::_main(), void();
    // if (13 <= num && num <= 14) 
    // return SubB::_main(), void();
    // debug(vector<int>(to + 1, to + n + 1));
    cout << 0 << '\n';
} signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
    FILE("migrate");
    // FLOCAL("migrate4");

	int t = 1; for (cin >> num >> t; t--; ) _main();
	return 0;
}

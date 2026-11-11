#include <bits/stdc++.h>
using namespace std;
template <class T> T lowbit(T x) {return x & -x;}
template <class T> T lg(T x) {return x == 0 ? 0 : __lg(x);}
template <class T> T ctz(T x) {return x == 0 ? 0 : __builtin_ctzll(x);}
#define gcd __gcd
#define pb emplace_back
#define popcount __builtin_popcountll
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
const int N = 505, M = 5e5 + 5;
const i64 inf = 0x3f3f3f3f3f3f3f3f;
int c, n, m, d, q;
i64 w[M], f[N][N];
vector<pair<int, i64>> e[M];

void _main() {
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++) cin >> w[i];
    for (int i = 1, k; i <= n; i++) {
        cin >> k;
        for (i64 u, c; k--; ) cin >> u >> c, e[u].pb(i, c); 
    }
    memset(f, 0x3f, sizeof(f));
    for (int i = 1; i <= n; i++) f[i][i] = 0;
    for (int i = 1; i <= m; i++) 
        for (auto [u, c1] : e[i]) for (auto [v, c2] : e[i]) 
            f[u][v] = min(f[u][v], c1 + c2);
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
    for (int x, y; q--; ) {
        cin >> x >> y;
        i64 res = inf;
        for (auto [u, c1] : e[x])
            for (auto [v, c2] : e[y])
                res = min(res, c1 + c2 + f[u][v]);
        cout << res + w[x] + w[y] << '\n';
    }
} signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
    FILE("subway");
    // FLOCAL("subway7");

	int t = 1; for (/*cin >> t*/; t--; ) _main();
	return 0;
}

// g++ subway.cpp -o subway -std=c++14 -O2 -static -DLOCAL

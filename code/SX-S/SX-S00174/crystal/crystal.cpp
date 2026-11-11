#include <bits/stdc++.h>
using namespace std;
template <class T> T lowbit(T x) {return x & -x;}
template <class T> T lg(T x) {return x == 0 ? 0 : __lg(x);}
template <class T> T ctz(T x) {return x == 0 ? 0 : __builtin_ctzll(x);}
#define gcd __gcd
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

#define int long long
const int N = 5e5 + 5;

int n, m, a[N], s[N];

void _main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) s[i] = s[i-1] + a[i];
    int cnt = 1;
    for (int i = 1, j; i <= n; i = j) {
        j = i;
        while (j <= n && a[i] == a[j]) j++;
        int lo = 1, hi = i-1, p = i;
        while (lo <= hi) {
            int mid = (lo + hi) >> 1;
            if (s[i-1] - s[mid-1] + m >= (i-1-mid+1) * a[i]) p = mid, hi = mid-1;
            else lo = mid+1;
        }
        // [i, j)
        cnt = max(cnt, j - i + i - 1 - p + 1);
    }
    cout << cnt;
} signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
    FILE("crystal");

	int t = 1; for (/*cin >> t*/; t--; ) _main();
	return 0;
}

/*
//freopen
//feropen
//freopne

shumale.
qudou jiawanle.
yuyuzheng.
why???? I ask myself.

I'm too vegetable.

g++ crystal.cpp -o crystal -O2 -std=c++14 -static
*/

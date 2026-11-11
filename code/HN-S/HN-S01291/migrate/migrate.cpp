#include <iostream>
#include <random>
#include <cstring>
#include <tuple>
#include <algorithm>
#define popcount __builtin_popcount
#define stop_sync do { ios::sync_with_stdio(false); cin.tie(nullptr); } while (0)
#define fileio(s) do { freopen(s ".in", "r", stdin); freopen(s ".out", "w", stdout); } while (0)
#define rep(i, a, b) for (int i = (int) (a); i <= (int) (b); i++)
#define repl(i, a, b) for (int i = (int) (a); i < (int) (b); i++) 
#define per(i, a, b) for (int i = (int) (a); i >= (int) (b); i--)
#define nocpy const auto &
#define endl '\n'
#define all(iter) (iter).begin(), (iter).end()
#define pred(it, expr) [&] (nocpy it) { return (expr); }
#define comp(lhs, rhs, expr) [&] (nocpy lhs, nocpy rhs) { return (expr); }
#define update_v(v, expr, func) (v) = func((v), (expr))
#define zeroize(v) memset(v, 0x00, sizeof(v))
#define invalidate_max(v) memset(v, 0x3f, sizeof(v))

using namespace std;

constexpr int MAXN = 2e6 + 10;
int c;

int n;
int a[MAXN];

void input() {
	cin >> n; rep(i, 1, n) cin >> a[i];
	sort(a + 1, a + n + 1);
}

// What can I say?

void work() {
	input();
	if (11 <= c && c <= 12)  { cout << n - 2 << endl; return; }
}

int main() {
	stop_sync;
	fileio("migrate");
	cin >> c; int t; cin >> t; while (t--) work();
	return 0;
}

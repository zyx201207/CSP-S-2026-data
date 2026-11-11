#include <bits/stdc++.h>
#define FOR(i, l, r) for (int i = (l); i <= (r); ++i)
#define ROF(i, r, l) for (int i = (r); i >= (l); --i)
#define popc(x) __builtin_popcountll((x))
#define SZ(v) int((v).size())
#define allc(v) (v).begin(), (v).end()
#define PB push_back
#define FI first
#define SE second
#define MP make_pair 
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
template<typename A, typename B>
void chkmax(A &a, B b) { a = (a > b) ? a : b; }
template<typename A, typename B>
void chkmin(A &a, B b) { a = (a < b) ? a : b; } 
bool Mbe;
namespace lyl {
	const int N = 5e5 + 5;
	int n;
	ll a[N], m, sum[N];
	void solve() {
		cin >> n >> m;
		FOR (i, 1, n) cin >> a[i];
		sort(a + 1, a + n + 1);
		FOR (i, 1, n) sum[i] = sum[i - 1] + a[i];
		int j = 1, ans = 0;
		FOR (i, 1, n) {
			while (a[i] * (i - j + 1) - (sum[i] - sum[j - 1]) > m) ++j;
			chkmax(ans, i - j + 1); 
		}
		cout << ans << '\n';
	}
}
bool Meb;
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	lyl::solve();
//	cerr << "Time: " << clock() * 1000.0 / CLOCKS_PER_SEC << "ms\n"; 
//	cerr << "Space: " << fabs(&Mbe - &Meb) / 1024.0 / 1024.0 << "MB\n";
	return 0;
}

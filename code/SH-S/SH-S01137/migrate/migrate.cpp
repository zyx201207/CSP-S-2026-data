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
	const int N = 2e6 + 5;
	ll f[N][3];
	int n, nxt[N];
	ll a[N], d;
	void solve() {
		cin >> n >> d;
		FOR (i, 1, n) cin >> a[i], f[i][0] = f[i][1] = f[i][2] = 0;
		int j = n;
		ROF (i, n, 1) {
			while (a[j] - a[i] > d) --j;
			nxt[i] = j;
		}
		ll ans = 0;
		ROF (i, n, 1) {
			if (nxt[i] == i) continue;
			if (nxt[i] == i + 1) {
				f[i][0] = f[i + 1][0] + nxt[i + 1] - (i + 1);
				f[i][1] = f[i + 1][1] + f[i + 1][2];
				continue;
			}
			f[i][0] = nxt[nxt[i]] - nxt[nxt[i] - 1];
			f[i][2] = nxt[nxt[i] - 1] - nxt[nxt[i] - 2];
			if (nxt[nxt[i] - 1] != nxt[nxt[i]]) f[i][0] += f[nxt[i]][0], f[i][1] += f[nxt[i]][1];
			else if (nxt[nxt[i] - 2] < nxt[nxt[i]]) f[i][2] += f[nxt[i]][0];
			if (nxt[nxt[i] - 1] < nxt[nxt[i]] - 1) f[i][1] += f[nxt[i]][2];
		}
		FOR (i, 1, n) ans += f[i][1] + f[i][2];
		cout << ans << '\n';
	}
}
bool Meb;
int main() {
	 freopen("migrate.in", "r", stdin);
	 freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int cid, T; cin >> cid >> T;
	while (T--) lyl::solve();
//	cerr << "Time: " << clock() * 1000.0 / CLOCKS_PER_SEC << "ms\n"; 
//	cerr << "Space: " << fabs(&Mbe - &Meb) / 1024.0 / 1024.0 << "MB\n";
	return 0;
}

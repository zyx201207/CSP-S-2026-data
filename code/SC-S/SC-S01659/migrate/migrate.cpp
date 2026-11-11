#include<bits/stdc++.h>
#define LoveFurina ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define F(x, l, r) for(int x = l; x <= r; ++x)
#define B(x, r, l) for(int x = r; x >= l; --x)
#define ll long long
#define pii pair<int, int>
#define st first
#define nd second
using namespace std;

const int N = 2e6 + 10;

int c, t, n;
ll d, x[N];
ll f[N], g[N];

inline void init() {
	F (i, 1, n) f[i] = g[i] = 0;
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	LoveFurina;
	
	cin >> c >> t;
	while (t--) {
		init(); cin >> n >> d;
		F (i, 1, n) cin >> x[i];
		
		ll ans = 0;
		F (i, 1, n) {
			int l = i; ll minF = 0, sumG = 1; f[i] = 0, g[i] = 1;
			F (j, i + 1, n) {
				while (x[j] - x[l] > d) sumG -= g[l++];
				if (minF != f[l]) {
					minF = f[l], sumG = 0;
					F (k, l, j) {
						if (f[k] == minF) sumG += g[k];
						else break;
					}
				}
				f[j] = minF + 1, ans += (g[j] = sumG) == 2;
			}
		}
		cout << ans << '\n';
	}
	
return 0;
}
// 关注 luogu @DanseSolo 谢谢 awa 
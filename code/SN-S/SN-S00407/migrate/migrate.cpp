#include<bits/stdc++.h>
using namespace std;
constexpr int N = 2e6 + 1;
int n; long long d, a[N];
int f[N]; long long g[N], cnt[N];
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int T; cin >>T >>T;
	while(T--) {
		cin >>n >>d;
		for(int i = 1; i <= n; ++i) cin >>a[i];
		long long ans = 0;
		for(int k = 1; k <= n; ++k) {
			for(int i = 1; i <= n; ++i) cnt[i] = 0;
			cnt[f[k] = 0] = g[k] = 1;
			for(int i = k + 1, j = k; i <= n; ++i) {
				while(a[i] - a[j] > d) cnt[f[j]] -= g[j], ++j;
				g[i] = cnt[f[j]], cnt[f[i] = f[j] + 1] += g[i];
			}
			for(int i = k; i <= n; ++i) if(g[i] == 2) ++ans;
		}
		cout <<ans <<'\n';
	}
	return 0;
}

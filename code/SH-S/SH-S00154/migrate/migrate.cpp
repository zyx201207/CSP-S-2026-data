#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 2e6 + 1;
int c, t, n; 
ll d, x[maxn], bycl[maxn], bycr[maxn], ans;

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout); 
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> c >> t;
	if (c <= 2) {
		while (t--) {
			int dis[301][301], isdui[301][301];
			cin >> n >> d;
			for (int i = 1; i < n; ++i)
				for (int j = i + 1; j <= n; ++j) dis[i][j] = 0x3f3f3f3f;
			for (int i = 1; i <= n; ++i) {
				cin >> x[i];
				int nowi = i;
				dis[i][i] = 0;
				for (int j = i - 1; j >= 1; --j) {
					while (nowi > j && x[nowi] - x[j] > d) --nowi;
					if (nowi == j) break;
					dis[j][i] = dis[nowi][i] + 1;
				}
			}
			for (int i = 1, j = 1; i <= n; ++i) {
				while (j < n && x[j + 1] - x[i] <= d) ++j;
				bycl[i] = j;
			}
			for (int i = n, j = n; i >= 1; --i) {
				while (j > 1 && x[i] - x[j - 1] <= d) --j;
				bycr[i] = j;
			}
			for (int i = 1; i < n; ++i)
				for (int j = i + 1; j <= n; ++j) 
					if (bycl[i] == bycr[j] + 1) isdui[i][j] = 1;
			ans = 0;
			for (int i = 1; i < n; ++i) {
				for (int j = i + 1; j <= n; ++j) {
					int sans = 0;
					for (int k = i; k < j; ++k) 
						for (int o = k + 1; o <= j; ++o) 
							if (isdui[k][o] && dis[i][k] + dis[o][j] + 2 == dis[i][j]) ++sans;
					if (sans == 1) ++ans;
				}
			}
				
			cout << ans << "\n";
		}
	} else if (c == 11 || c == 12) {
		while (t--) {
			cin >> n >> d;
			for (int i = 1; i <= n; ++i) cin >> x[i];
			int yc = d / (x[2] - x[1]);
			if (yc <= 1) cout << "0\n";
			else cout << max(0, n - 2 * yc + 1) << "\n";
		}
	} else {
		while (t--) {
			cin >> n >> d;
			for (int i = 1; i <= n; ++i) cin >> x[i];
			for (int i = 1, j = 1; i <= n; ++i) {
				while (j < n && x[j + 1] - x[i] <= d) ++j;
				if (j - i > 1) ++bycl[j];
			}
			for (int i = n, j = n; i >= 1; --i) {
				while (j > 1 && x[i] - x[j - 1] <= d) --j;
				if (i - j > 1) ++bycr[j];
			}
			ans = 0;
			for (int i = 3; i < n; ++i) ans += bycl[i] * bycr[i - 1];
			cout << ans << "\n";
			for (int i = 1; i <= n; ++i) bycl[i] = bycr[i] = 0;
		}
	} 
	return 0;
} 


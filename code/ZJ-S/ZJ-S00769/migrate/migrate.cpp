#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define p_b push_back
#define LB lower_bound
#define UB upper_bound

const int N = 5e3+5;
int c, t, n, res = 0, len[N][N], cnt[N][N];
ll x[N], D;

signed main() 
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> c >> t; while (t--) {
		cin >> n >> D; res = 0;
		for (int i = 1; i <= n; ++i) cin >> x[i];
		for (int d = 1; d <= n-1; ++d) {
			for (int l = 1; l + d <= n; ++l) {
				int r = l + d;
				if (x[r] - x[l] <= D) len[l][r] = cnt[l][r] = 1;
				else if (d == 1) len[l][r] = N, cnt[l][r] = 0;
				else {
					ll mn = LLONG_MAX; int mnc = 0;
					for (int k = l + 1; k <= r - 1; ++k) {
						if (len[l][k] + len[k][r] < mn) 
							mn = len[l][k] + len[k][r], mnc = cnt[l][k] * cnt[k][r];
						else if (len[l][k] + len[k][r] == mn) mnc += cnt[l][k] * cnt[k][r];
					}
					if (mnc == 2) ++res;
					len[l][r] = mn, cnt[l][r] = mnc;
				}
			}
		}
		printf("%d\n", res);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
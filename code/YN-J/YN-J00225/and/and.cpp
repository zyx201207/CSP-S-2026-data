#include <bits/stdc++.h>
using namespace std;
const long long N = 2 * 1e5;
long long n, m;
long long c[N], d[N];
long long ans;

int main() {
	//freopen(" travel.in", "r", stdin);
	//freopen(" travel.out", "w", stdout);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> c[i];
	for (int i = 1; i <= n; i++) {
		long long cnt = c[i];
		for (int j = 1; j < m; j++) {
			long long w;
			long long o = 0;
			for (int k = 1; k <= n; k++) {
				bool flag = 0;
				long long sum = cnt;
				sum &= c[k];
				for (int z = 0; z < j; z++) {
					if (k == d[z]) {
						flag = 1;
					}
				}
				if (sum > o && flag == 0 && k != i) {
					o = sum;
					w = k;
				}
			}
			cnt &= c[w];
			d[j] = w;
		}
		memset(d, 0, sizeof(d));
		ans = max(ans, cnt);
	}
	cout << ans;
	return 0;
}
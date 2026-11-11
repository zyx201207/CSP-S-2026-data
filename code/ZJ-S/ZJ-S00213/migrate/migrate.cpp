#include <bits/stdc++.h> 
#define int long long
using namespace std;
const int N = 2e6 + 5;
int x[N];
map< pair<int, int>, pair<int, int> > a;
int c, t, n, d, cnt = 0;
signed main () {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	scanf("%lld%lld",&c, &t);
	while (t--) {
		cnt = 0;
		scanf("%lld%lld", &n, &d);
		for (int i = 1; i <= n; i++) {
			scanf("%lld", x+i);
		}
		for (int i = 1; i <= n; i++) {
			a[{i, i}] = {1, 1};
			for (int j = i + 1; j <= n; j++) {
				a[{i, j}] = {0, 0};
				int dj = 1;
				while(x[j] - x[j - dj] <= d && j - dj >= i) {
					if ( a[{i, j}].second == a[{i, j - dj}].second + 1|| a[{i, j}].second == 0) {
						a[{i, j}].first += a[{i, j - dj}].first;
						a[{i, j}].second = a[{i, j - dj}].second + 1;
					}
					else if (a[{i, j}].second != 0 && a[{i, j}].second > a[{i, j - dj}].second + 1) {
						a[{i, j}].first = a[{i, j - dj}].first;
						a[{i, j}].second = a[{i, j - dj}].second + 1;
					}
					dj ++;
				}
//				printf("a[%lld,%lld] = %lld  cnt = %lld\n", i, j, a[{i,j}], cnt);
				if (a[{i, j}].first == 2) {
					cnt++;
				}
//				printf("a[%lld,%lld] = %lld  cnt = %lld\n", i, j, a[{i,j}].first, cnt);
			}
		}
		printf("%lld\n", cnt);
	}
	return 0;
}

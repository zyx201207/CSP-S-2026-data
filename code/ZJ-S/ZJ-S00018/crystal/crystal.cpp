#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 5e5+5;

int n, m;
int a[N];
ll b[N];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", a+i);
	sort(a+1, a+n+1);
	for (int i = 1; i <= n; i++)
		b[i] = b[i-1]+a[i];
//	for (int i = 1; i <= n; i++)
//		printf("%lld ", b[i]);
//	puts("\n---");
	int ans = 0;
	for (int i = 2; i <= n; i++) {
		int L = 0, R = i;
		while (L+1 < R) {
			int M = (L+R)>>1;
			if (1ll*(i-M)*a[i]-(b[i-1]-b[M-1]) <= m)
				R = M;
			else
				L = M;
		}
//		printf("%d %lld\n", R, 1ll*(i-R)*a[i]-(b[i-1]-b[R-1]));
		ans = max(ans, i-R+1);
	}
	printf("%d", ans);
}
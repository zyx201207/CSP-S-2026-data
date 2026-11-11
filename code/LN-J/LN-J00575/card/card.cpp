#include <cstdio>
#include <cstring>
using namespace std;
const int N = 5e5 + 10, M = 3e5 + 10;
int n, m, beg = 1;
int a[N];
int q[N], tt;
int idx[M];
int cnt[M];
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	while (beg <= n) {
		memset(idx, 0, sizeof(idx));
		tt = 0;
		for (int i = beg; i <= n; ++i) {
			if (idx[a[i]] == 0) {
				q[++tt] = a[i];
				idx[a[i]] = tt;
			}
			else {
				while (tt != idx[a[i]]) 
				idx[q[tt--]] = 0;
			}
		}
		for (int i = 1; i <= tt; ++i) ++cnt[q[i]];
		++beg;
	}
	for (int i = 1; i <= m; ++i) printf("%d ", cnt[i]);
	puts("");
	return 0;
}

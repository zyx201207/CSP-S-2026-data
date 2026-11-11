#include <cstdio>
#include <algorithm>
using namespace std;
int n;
long long m;
long long a[500005];
long long s;
int l = 1;
int ans;
int cur;
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%d%lld", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		s += (i - l) * (a[i] - a[i - 1]);
		cur++;
		if (m < s) {
			while (m < s) {
				s -= (a[i] - a[l]);
				l++;
				cur--;
			}
		}
		ans = max(ans, cur);
	}
	ans = max(cur, ans);
	printf("%d", ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
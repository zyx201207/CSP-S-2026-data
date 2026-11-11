#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;
const int N = 5e5 + 5;
int n, ans;
ll m, sum;
ll a[N];
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%d%lld", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%lld", &a[i]);
	sort(a + 1, a + n + 1);
	for (int i = 1, j = 1; j <= n; j++) {
		sum += (a[j] - a[j - 1]) * (j - i);
		while (i < j && sum > m) sum -= a[j] - a[i++];
		ans = max(ans, j - i + 1);
	}
	printf("%d", ans);
	return 0;
}

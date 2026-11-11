#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 5e5 + 10;
int n;
ll m;
ll a[maxn], b[maxn];
int cnt[maxn], sum[maxn], chazhi[maxn];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	memset(b, 0, sizeof(b));
	scanf("%d %lld", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		b[i] = a[i] - a[i - 1];
	}
	int ans = 0, x = 2;
	memset(sum, 0, sizeof(sum));
	memset(cnt, 0, sizeof(cnt));
	cnt[1] = 1;
	while (x <= n) {
		sum[1] += (b[x] * cnt[1]);
		chazhi[1] += b[x] + b[2];
		cnt[1]++;
		x++;
		if (sum[1] >= m) {
			break;
		}
	}
	if (x >= n) {
		printf("%d", n);
		return 0;
	}
	if (sum[1] > m) {
		cnt[1]--;
		x--;
		sum[1] -= (b[x] * cnt[1]);
	} else {
		while (b[x] == 0) {
			cnt[1]++;
			x++;
		}
	}
	for (int i = 2; i < n - 1; i++) {
		sum[i] = sum[i - 1] - chazhi[i - 1];
		cnt[i] = cnt[i - 1] - 1;
		chazhi[i] = chazhi[i - 1] - (b[i] * (i - 1));
		for (int j = x + 1; j <= n; j++) {
			sum[i] += (b[j] * cnt[i]);
			if (sum[i] > m) {
				continue;
			} else {
				cnt[i] += 1;
				chazhi[i] += b[j];
				x++;
			}
		}
	}
	for (int i = 1; i < n - 1; i++) {
		ans = max(ans, cnt[i]);
	}
	printf("%d", ans);
	return 0;
}
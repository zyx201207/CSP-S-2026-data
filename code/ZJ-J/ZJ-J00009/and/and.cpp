#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+5;

int n, m;
int a[N];
int b[N], lb;
int c[N], lc;

int main() {
	freopen("and.in", "r", stdin);
	freopen("ans.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	int maxcan = -1;
	for (int i = 30; i >= 0; i--) {
		int cnt = 0;
		for (int j = 1; j <= n; j++)
			if ((a[j] >> i) & 1)
				++cnt;
		if (cnt >= m) {
			maxcan = i;
			break;
		}
	}
	for (int i = 1; i <= n; i++)
		if ((a[i] >> maxcan) & 1)
			b[++lb] = a[i];
	for (int i = maxcan-1; i >= 0; i--) {
		int cnt = 0;
		for (int j = 1; j <= lb; j++)
			if ((b[j] >> i) & 1)
				++cnt;
		if (cnt >= m && cnt < lb) {
			// update;
			lc = 0;
			for (int j = 1; j <= lb; j++)
				if ((b[j] >> i) & 1)
					c[++lc] = b[j];
			lb = lc;
			for (int j = 1; j <= lb; j++)
				b[j] = c[j];
		}
	}
	int ans = b[1];
	for (int i = 1; i <= lb; i++)
		ans &= b[i];
	printf("%d", ans);
}
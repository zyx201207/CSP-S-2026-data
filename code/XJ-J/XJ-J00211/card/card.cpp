#include <bits/stdc++.h>
using namespace std;

const int N = 500011;
const int M = 300011;
int n, m, a[N], c[N], ans[M], cnt[M];
bool vis[M];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	int ok = 1;
	for (int i = 2; i <= n; i++) {
		if (a[i - 1] > a[i]) {
			ok = 0;
			break;
		}
	}
	if (n <= 500 && m <= 200) {
		for (int i = 1; i <= n; i++) ans[i] = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) vis[j] = false;
			int top = 0;
			for (int j = i; j <= n; j++) {
				if (!vis[a[j]])
					vis[a[j]] = true, c[++top] = a[j];
				else {
					while (top > 0 && c[top] != a[j])
						vis[c[top--]] = false;
				}
			}
			for (int j = 1; j <= m; j++) vis[j] = false;
			for (int j = 1; j <= top; j++)
				if (!vis[c[j]])
					vis[c[j]] = true, ++ans[c[j]];
		}
		for (int i = 1; i <= m; i++)
			printf("%d ", ans[i]);
		puts("");
		return 0;
	}
	if (ok) {
		for (int i = 0; i <= m; i++) cnt[i] = 0;
		for (int i = 1; i <= n; i++)
			cnt[a[i]]++;
		for (int i = 1; i <= m; i++)
			cnt[i] += cnt[i - 1];
		for (int i = 1; i <= m; i++)
			printf("%d ", cnt[i]);
		puts("");
		return 0;
	}
	return 0;
}

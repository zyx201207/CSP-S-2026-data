#include <bits/stdc++.h>
using namespace std;
const int N = 3e6;
int n, m, a[N], now[N], mid, rear;
int mono[N], ans[N];

bool find(int x) {
	for (int i = 1; i <= n; i++) {

		if (now[i] == x) {
			mid = i;
			return true;
		}
	}

	return false;
}

void Onion(int x) {
	for (int i = x; i <= n; i++)

		now[i] = 0, mono[i] = 0;
}

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++)

		scanf("%d", &a[i]);
	int round = n;
	memset(ans, 0, sizeof(ans));
	int st = 1;

	while (round--) {

		memset(now, 0, sizeof(now));
		memset(mono, 0, sizeof(mono));

		for (int i = st; i <= n; i++) {

			if (find(a[i]) == true) {
				Onion(mid);
				rear = mid;
				now[rear++] = a[i], mono[a[i]] = 1;
			} else {
				now[++rear] = a[i];
				mono[a[i]] = 1;
			}
		}

		for (int i = 1; i <= m; i++)

			ans[i] += mono[i];
		st++;
	}

	for (int i = 1; i <= m; i++)

		printf("%d ", ans[i]);
	return 0;
}
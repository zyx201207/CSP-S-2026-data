#include <bits/stdc++.h>
using namespace std;
const int N = 3e6;
int n, m, a[N], ans = -0x3f3f3f3f, temp, eRear = 1;
int e[N];
queue<int> q;

void f(int x, int y) {
	for (int i = x; i < y; i++)

		temp = e[i] & e[i + 1];
	ans = max(temp, ans);
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++)

		scanf("%d", &a[i]);

	for (int i = 1; i <= n * 4; i++) {

		if (eRear > n)
			eRear = 1;
		e[i] = a[eRear++];
	}

	for (int i = 1; i <= n; i++) {

		int l = 0, r = 1;

		for (int j = 1; j <= m; j++) {

			l = l + 1, r = r + m - 1;

			//if (l > n)
			//l = 1, r = l + m - 1;

			//if (r > n)
			//r = 1;
			f(l, r);
		}
	}

	printf("%d", ans);


	return 0;
}

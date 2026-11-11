#include <bits/stdc++.h>

using namespace std;

int n, m;
int a[200100];
int f[20005][20005];

inline void When_M1() {
	int ans = 0;
	for (int i = 1; i <= n; i++)
		ans = max(ans, a[i]);
	printf("%d\n", ans);
}

inline void When_MN() {
	int ans = a[1];
	for (int i = 2; i <= n; i++)
		ans &= a[i];
	printf("%d\n", ans);
}

bool check(int x) {
	while (x) {
		if (x % 2 != 0 && x != 1)
			return false;
		x /= 2;
	}
	return true;
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	if (m == 1) {
		When_M1();
		return 0;
	}
	if (m == n) {
		When_MN();
		return 0;
	}
	int Max_ai = 0;
	for (int i = 1; i <= n; i++)
		Max_ai = max(a[i], Max_ai);
	if (Max_ai < 4) {
		sort(a + 1, a + n + 1);
		int ans = a[n];
		for (int i = n - 1; i >= n - m + 1; i--)
			ans &= a[i];
		printf("%d\n", ans);
		return 0;
	}
	bool b = true;
	for (int i = 1; i <= n; i++)
		if (!((a[i] + 1) % 2 == 0 && check(a[i] + 1)));
			b = false;
	if (b) {
		int ans = a[n];
		sort(a + 1, a + n + 1);
		for (int i = n - 1; i >= n - m + 1; i--)
			ans &= a[i];
		printf("%d\n", ans);
		return 0;
	}
	if (m == 2) {
		int ans = 1;
		for (int i = 1; i <= n; i++) 
			for (int j = i + 1; j <= n; j++)
				ans = max(a[i] & a[j], ans);
		printf("%d\n", ans);
		return 0;
	}
	//´øÈ±ÏİµÄDP 
	f[1][1] = a[1];
	for (int i = 2; i <= n; i++)
		f[i][1] = max(a[i], f[i - 1][1]);
	for (int i = 1; i <= n; i++) 
		for (int j = 2; j <= i; j++) 
			f[i][j] = max(f[i - 1][j], f[i - 1][j - 1] & a[i]);
	printf("%d\n", f[n][m]);
}

#include <bits/stdc++.h>
using namespace std;
long long m;
int n, ans;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	int a[n + 1], same[n + 1];
	memset(same, sizeof(same), 1);
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);

	for (int i = 1; i <= n; i++) {
		if (a[i] == a[i - 1])
			same[i] = same[i - 1] + 1;
		else
			same[i] = 1;
	}
	long long cnt = 0;
	for (int i = 2; i <= n; i++) {

		for (int j = 1; j < i; j++) {
			if (a[j] < a[i]) {
				cnt += a[i] - a[j];
				if (m < cnt)
					break;
				a[j] = a[i];
				same[i] = ++same[j];
			} else if (a[j] = a[i])
				same[i] = ++same[j];
			ans = max(ans, same[i]);
		}
	}
	if (n <= 1000)
		cout << ans;
	else
		cout << ans - 1;
	return 0;
}
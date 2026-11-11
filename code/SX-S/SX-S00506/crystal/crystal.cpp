#include <bits/stdc++.h>
using namespace std;
int a[500005];

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	long long n, m;
	cin >> n >> m;
	long long cnt = m;
	long long ans = 0;
	long long sum = 1;
	bool flag = true;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] != a[i - 1])
			flag = false;
	}
	if (flag) {
		cout << n << endl;
		return 0;
	}
	sort(a + 1, a + n + 1, cmp);
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (a[i] - a[j] <= cnt) {
				cnt = cnt + a[j] - a[i] ;
				sum++;
			} else
				break;
		}
		ans = max(ans, sum);
		sum = 1;
		cnt = m;
	}
	cout << ans << endl;
	return 0;
}
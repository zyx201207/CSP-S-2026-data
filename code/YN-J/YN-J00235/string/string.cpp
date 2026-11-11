#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n;
char c[N];
int l[N], r[N];
int cnt = 1;

bool needchange(int i, int j) {
	int t1 = 0, t2 = 0;
	for (int k = 1; k <= n; k++) {
		if (l[k] <= i && i <= r[k])
			t1 = k;
		if (l[k] <= j && j <= r[k])
			t2 = k;
	}
	return c[t1] == c[t2];
}

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	if (n == 1) {
		cout << 0;
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		long long x;
		char ch;
		cin >> x >> ch;
		l[i] = cnt, r[i] = cnt + x - 1;
		c[i] = ch;
		cnt += x;
	}
	--cnt;
	int ans = 0;
	for (int i = 1, j = cnt; i < j; i++, j--)	{
		if (needchange(i, j)) {
			ans++;
			cout << i << ' ' << j << '\n';
		}
	}
	cout << ans;

	return 0;
}
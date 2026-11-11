#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N = 2e5 + 5;
int n, a[N];
char c[N];
LL ans;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i] >> c[i];

	int l = 1, r = n;
	while (l < r) {
		int cnt = min(a[l], a[r]);
		if (c[l] != c[r])
			ans += cnt;
		a[l] -= cnt, a[r] -= cnt;
		if (a[l] == 0)
			l++;
		if (a[r] == 0)
			r--;
	}
	
	cout << ans;

	return 0;
}

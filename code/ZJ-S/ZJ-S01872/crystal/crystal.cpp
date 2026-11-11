%:include <bits/stdc++.h>
using namespace std;

# define il inline

using i64 = long long;

il void read (int &x) {
	x = 0;
	char ch = getchar ();
	int negative = 0;
	for (; !isdigit (ch); ch = getchar ())
		negative = (ch == '-');
	for (; isdigit (ch); ch = getchar ())
		x = (x << 3) + (x << 1) + (ch & 15);
	negative ? x = -x : 0;
}

il void read_i64 (i64 &x) {
	x = 0;
	char ch = getchar ();
	int negative = 0;
	for (; !isdigit (ch); ch = getchar ())
		negative = (ch == '-');
	for (; isdigit (ch); ch = getchar ())
		x = (x << 3) + (x << 1) + (ch & 15);
	negative ? x = -x : 0;
}

constexpr int N = 5e5 + 5;	

int n;
i64 m, a [N], sum [N];

il bool check (int x) {
	for (int i = 1, j = x; j <= n; i++, j++) {
		const i64 cost = a [j] * x - (sum [j] - sum [i - 1]);
		if (cost <= m)
			return 1;
	}
	return 0;
}

int main () {
	freopen ("crystal.in", "r", stdin);
	freopen ("crystal.out", "w", stdout);
	
	read (n), read_i64 (m);
	for (int i = 1; i <= n; i++)
		read_i64 (a [i]);
		
	sort (a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++)
		sum [i] = sum [i - 1] + a [i];
	
	int l = 1, r = n;
	int ans = 1;
	while (l <= r) {
		const int mid = l + r >> 1;
		if (check (mid)) {
			l = mid + 1;
			ans = mid;
		}
		else {
			r = mid - 1;
		}
	}
	printf ("%d\n", ans);
	return 0;
}

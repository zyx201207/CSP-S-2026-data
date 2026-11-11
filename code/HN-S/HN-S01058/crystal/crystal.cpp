#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define file(s)	freopen(#s".in", "r", stdin), freopen(#s".out", "w", stdout)
const int N = 5e5 + 10;
int n, front = 1, rear;
ll m, a[N], s[N], q[N];
signed main() {
	file(crystal);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)	cin >> a[i];
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; ++i)	s[i] = s[i - 1] + a[i];
	int ans = 1;
	for (int i = 1; i <= n; ++i) {
		while (front <= rear && a[i] * (rear - front + 1) - s[q[rear]] + s[q[front] - 1] > m)	front++;
		q[++rear] = i;
		ans = max(ans, rear - front + 1);
	}
	cout << ans;
	return 0;
} 
//ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

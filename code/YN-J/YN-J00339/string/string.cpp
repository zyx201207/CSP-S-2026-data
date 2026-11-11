#include <bits/stdc++.h>
using namespace std;
int n, s[200010], m;
long long all, cnt, sum, ans;
char a[200010];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> s[i] >> a[i];
		all += s[i];
	}
	int head = 1, end = n;
	while (head < end) {
		int maxx = max(s[head], s[end]), minn = min(s[head], s[end]);
		if (a[head] != a[end]) {
			ans += minn;
		}
		s[head] -= minn;
		s[end] -= minn;
		cnt += minn;
		sum += minn;
		if (s[head] == 0) {
			head++;
		}
		if (s[end] == 0) {
			end--;
		}
	}
	cout << ans;
	return 0;
}
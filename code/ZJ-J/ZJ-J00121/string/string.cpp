#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 5;
struct node {
	long long num;
	char ch;
	long long sum;
} s[N], rs[N];
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	long long n;
	cin >> n;
	long long l = 0, all = 0;
	while (n--) {
		string c;
		long long a;
		cin >> a >> c;
		if (l && s[l].ch == c[0]) {
			s[l].sum += a;
			s[l].num += a;
		}
		else {
			l++;
			s[l] = {a, c[0], s[l - 1].sum + a};
		}
		all += a;
	}
	for (long long i = l; i; i--)
		rs[l - i + 1] = {s[i].num, s[i].ch, rs[l - i].sum + s[i].num};
	long long i = 1, j = 1, now = 0, ans = 0;
	while (now < all / 2)
		if (s[i].sum < rs[j].sum) {
			if (s[i].ch != rs[j].ch)
				ans += s[i].sum - now;
			now = s[i].sum;
			i++;
		} else if (s[i].sum > rs[j].sum) {
			if (s[i].ch != rs[j].ch)
				ans += rs[j].sum - now;
			now = rs[j].sum;
			j++;
		} else {
			if (s[i].ch != rs[j].ch)
				ans += s[i].sum - now;
			now = s[i].sum;
			i++;
			j++;
		}
	cout << ans << '\n';
	return 0;
}

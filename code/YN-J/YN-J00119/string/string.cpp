#include <bits/stdc++.h>
using namespace std;

//两边比大小，谁大，把另一个与其替换，继续比较。
struct sss {
	long long a;
	char t;
};
sss s[200010];
long long n, l, r;
long long k[200010];
long long q[200010];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> s[i].a >> s[i].t;
	}
	int d = 1;
	k[1] = s[1].a;
	q[1] = s[1].t - 'a' + 1;
	for (int i = 2; i <= n; i++) {
		if (s[i - 1].t == s[i].t) {
			k[d] += s[i].a;
		} else {
			k[d + 1] = s[i].a;
			q[d + 1] = s[i].t - 'a' + 1;
			d++;
		}
	}
	int l = 1;
	if (k[d] == 0) {
		r = d - 1;
	} else {
		r = d;
	}
	long long ans = 0;
	while (l != r) {
		if (k[l] > k[r] && q[l] != q[r]) {
			ans += k[r];
			k[l] -= k[r];
			r--;
		} else if (k[l] < k[r] && q[l] != q[r]) {
			ans += k[l];
			k[r] -= k[l];
			l++;
		} else if (k[l] < k[r] && q[l] == q[r]) {
			k[r] -= k[l];
			l++;
		} else if (k[l] > k[r] && q[l] == q[r]) {
			k[l] -= k[r];
			r--;
		} else if (k[l] == k[r] && q[l] == q[r] && r - 1 > l) {
			l++;
			r--;
		} else if (r - 1 == l && k[l] == k[r]) {
			ans += k[l];
			break;
		} else if (k[l] == k[r] && q[l] != q[r] && r - 1 > l) {
			ans += k[l];
			l++;
			r--;
		}
	}
	cout << ans;
	return 0;
}

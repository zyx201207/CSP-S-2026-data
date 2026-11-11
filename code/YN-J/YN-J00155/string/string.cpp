#include <bits/stdc++.h>
using namespace std;
#define int long long

struct node {
	long long num;
	char s;
};
node a[200005], b[200005];
stack<node> st1, st2;

signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	long long n;
	cin >> n;
	long long sum = 0;
	for (long long i = 0; i < n; i++) {
		cin >> b[i].num >> b[i].s;
		sum += b[i].num;
	}
	long long t = 0, k = b[0].num;
	for (long long i = 1; i < n; i++) {
		if (b[i - 1].s != b[i].s) {
			a[t].num = k;
			a[t].s = b[i - 1].s;
			t++;
			k = 0;
			k += b[i].num;
		} else {
			k += b[i].num;
		}
	}
	a[t].num = k;
	a[t].s = b[n - 1].s;
//	for (long long i = 0; i <= t; i++) {
//		cout << a[i].num << " " << a[i].s << endl;
//	}

	long long mid, m = 0, mt = 0;
	if (sum % 2 == 0) {
		mid = sum / 2;
	} else {
		mid = (sum + 1) / 2;
		int nw = 0, ff = 0;
		for (int i = 0; i <= t; i++) {
			nw += a[i].num;
			if (nw >= mid and ff == 0) {
				ff = 1;
				a[i].num = a[i].num - 1;
				sum -= 1;
			} else {
				a[i] = a[i];
			}
		}
		mid = sum / 2;
	}
	bool f = 0;
	long long l = 0, r = 0;
	for (long long i = 0; i <= t; i++) {
		m += a[i].num;
		mt++;
		if (m > mid) {
			f = 1;
			r = m - mid;
			l = a[i].num - r;
			st1.push({l, a[i].s});
			t++;
			break;
		} else if (m == mid) {
			st1.push(a[i]);
			mt--;
			break;
		}
		st1.push(a[i]);
	}
	if (f) {
		for (long long i = t; i > mt; i--) {
			st2.push(a[i - 1]);
			if (i == (mt + 1)) {
				st2.push({r, a[mt - 1].s});
			}
		}
	} else {
		for (long long i = t; i > mt; i--) {
			st2.push(a[i]);
		}
	}
//	cout << mid << " " << m << " " << mt << " " << f << " " << l << " " << r;
	int ans = 0;
	while (!st1.empty() and !st2.empty()) {
		if (st1.top().s == st2.top().s) {
			if (st1.top().num == st2.top().num) {
				st1.pop();
				st2.pop();
			} else if (st1.top().num < st2.top().num) {
				int g = st2.top().num - st1.top().num;
				char sss = st2.top().s;
				st1.pop();
				st2.pop();
				st2.push({g, sss});
			} else {
				int g = st1.top().num - st2.top().num;
				char sss = st1.top().s;
				st2.pop();
				st1.pop();
				st1.push({g, sss});
			}
		} else {
			if (st1.top().num == st2.top().num) {
				ans += st1.top().num;
				st1.pop();
				st2.pop();
			} else if (st1.top().num < st2.top().num) {
				ans += st1.top().num;
				int g = st2.top().num - st1.top().num;
				char sss = st2.top().s;
				st1.pop();
				st2.pop();
				st2.push({g, sss});
			} else {
				ans += st2.top().num;
				int g = st1.top().num - st2.top().num;
				char sss = st1.top().s;
				st2.pop();
				st1.pop();
				st1.push({g, sss});
			}
		}
	}
	cout << ans << endl;
	return 0;
}
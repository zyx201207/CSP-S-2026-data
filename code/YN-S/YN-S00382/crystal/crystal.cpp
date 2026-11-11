#include <bits/stdc++.h>
using namespace std;

struct node {
	long long a = 0, b = 0;
}
s[500005];

bool cmp2(node a, node b) {
	return a.b < b.b;
}

bool cmp1(node a, node b) {
	return a.a < b.a;
}
long long q[500005];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	long long n, m;
	cin >> n >> m;
	int k = 0;
	bool pp = true;
	long long ans = -1;
	for (int i = 1; i <= n; i++) {
		cin >> s[i].a;
	}
	sort(s + 1, s + 1 + n, cmp1);
	k = max(s[1].a, s[2].a) - min(s[1].a, s[2].a);
	for (int i = 2; i <= n; i++) {
		if (s[i].a - s[i - 1].a != k)
			pp = false;
	}
	if (pp) {
		int p1, p2;
		p1 = 1, p2 = 2;
		for (int i = 1; i <= n; i++) {
			p1 *= 2;
			p2 *= 2;
			if (p1 <= m && m <= p2) {
				cout << i + 1;
				return 0;
			}
		}
	} else {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				s[i].b += abs(s[i].a - s[j].a);
//				cout << s[i].b << " ";
			}
		}
	}
	memset(q, 0, sizeof(q));
	sort(s + 1, s + 1 + n, cmp2);
	int yu = s[1].a;
	sort(s + 1, s + 1 + n, cmp1);
	for (int i = 2; i <= n; i++) {
		q[i - 1] = abs(s[i].a - s[1].a);
	}
//	for (int i = 1; i < n; i++) {
//		cout << s[i].a << "  " << q[i] << endl << endl;
//	}
	sort(q + 1, q + n);
//	for (int i = 1; i < n; i++) {
//		cout << q[i] << endl;
//	}
//	cout << n << endl << m << endl;
	int tt = 1;
	while (m > 0) {
//		cout << "wc";
		m -= q[tt];
//		cout << q[tt] << endl;
		ans++;
		tt++;
	}
//	cout << endl << endl << m << endl;
	if (m == 0)
		ans++;
	cout << ans;
	return 0;
}
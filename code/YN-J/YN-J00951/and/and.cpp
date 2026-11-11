#include <bits/stdc++.h>
using namespace std;
bool t[40];

struct node {
	long long a, q, c = 0;
	bool e[40];
} s[200005];

bool cmp(node x, node y) {
	if (x.q == y.q) {
		return x .a > y.a;
	}
	return x.q > y.q;
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	long long n, m;
	cin >> n >> m;
	for (long long i = 1; i <= n; i++) {
		cin >> s[i].a;
		long long p = s[i].a;
		long long j = 1;
		while (p) {
			if (p % 2 == 1) {
				s[i].q++;
				s[i].e[j] = 1;
			}
			p /= 2;
			j++;
			s[i].c++;
		}
	}
	sort(s + 1, s + n + 1, cmp);
	//cout << endl;
	long long zd = -1;
	for (long long i = 1; i <= 3; i++) {
		zd = max(zd, s[i].c);
	}
	for (long long i = 1; i <= 40; i++) {
		t[i] = 1;
	}
	long long toi = -1;
	for (long long i = 1; i <= m; i++) {
		//cout << s[i].a << " ";
		for (long long j = 1; j <= zd; j++) {
			if (s[i].e[j] == 0) {
				t[j] = 0;
			}

		}
		toi = max(toi, s[i].c);
	}
	//cout << endl;
	//cout << toi << endl;
	long long shu = 0;

	for (long long i = 1; i <= toi; i++) {
		//cout << t[i] << " ";
		shu += t[i] * pow(2, i - 1);
	}
	//cout << endl;
	cout << shu;
	return 0;
}
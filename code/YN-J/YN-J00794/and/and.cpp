#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 5;
int a[N];
string sss[N];
string s1, s2, s3;

string jjzh1(int sz) {
	string s;
	while (sz) {
		if (sz % 2 == 0) {
			s += "0";
		} else {
			s += "1";
		}
		sz /= 2;
	}
	reverse(s.begin(), s.end());
	return s;
}

void jjzh2(string ss) {
	reverse(ss.begin(), ss.end());
	int z = 0;
	for (int i = 0; i < ss.size(); i++) {
		int y = pow(2, i);
		int cw = (ss[i] - '0');
		z += (cw * y);
	}
	cout << z;
}

signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n, m, cnt = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	if (m == 1) {
		cout << a[n];
	} else if (m == 2) {
		s1 = jjzh1(a[n]);
		s2 = jjzh1(a[n - 1]);
		int maxcd = max(s1.size(), s2.size());
		for (int i = 0; i < n; i++) {
			if (s1[i] == s2[i]) {
				s3 += "1";
			} else {
				s3 += "0";
			}
		}
		jjzh2(s3);
	} else {
		for (int i = n; i >= n - m + 1; i--) {
			sss[i] = jjzh1(a[i]);
			int maxcd = max(s3.size(), sss[i].size());
			for (int j = 0; j < n; j++) {
				if (s3[j] == sss[i][j]) {
					s3[j] = '1';
				} else {
					s3[j] = '0';
				}
			}
		}
		jjzh2(s3);
	}
	return 0;
}
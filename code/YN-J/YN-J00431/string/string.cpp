#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, len = 0;
struct node {
	int a;
	char c;
} m[200005];
string s, s1;
int maxn = 0, t[30];

signed main() {
	cin >> n;

	for (int i = 1; i <= n; i++) {

		cin >> m[i].a >> m[i].c;
		t[m[i].c]++;

		for (int i = 0; i < m[i].a; i++) {

			s += m[i].c;
			s1 += m[i].c;

		}
	}

	bool flag = 0;
	reverse(s.begin(), s.end());


	for (int i = 0; i < s1.size(); i++) {



		for (int j = 0; j < s.size(); j++) {

			if (s1[i] != s[j]) {
				flag = 0;

			} else {
				flag = 1;

			}
		}
	}

	if (!flag) {
		if (n == 2) {
			for (int i = 1; i <= n; i++) {

				for (int j = i; j <= n; j++)

					if (m[i].a > m[j].a) {
						cout << m[j].a;
						return 0;
					} else {
						cout << m[i].a;
						return 0;
					}
			}
		}

		if (n == 1) {
			cout << 0;
			return 0;
		}
	}

	cout << 0;
	return 0;
}
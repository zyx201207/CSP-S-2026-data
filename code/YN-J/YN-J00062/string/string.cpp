#include <bits/stdc++.h>
using namespace std;

struct s {
	int a;
	string t;
};

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	s m[10005]
	string s1;
	int n, m;
	for (int i = 0; i <= n - 1; i++) {
		cin >> m[i].a >> m[i].t ;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= m[i].a; j++) {
			s1 = s1 + t;
		}
	}
	for (int n = 0; n <= s1.long / 2; n++) {
		if (s1[n] != s1[s1.long - n - 1]) {
			m++;
		}
	}
	cout << m;


	return 0;
}
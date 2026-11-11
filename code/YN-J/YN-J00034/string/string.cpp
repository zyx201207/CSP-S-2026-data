#include <bits/stdc++.h>
using namespace std;

struct str {
	long long a;
	char c;
};
str s[200005];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	s[0].a = 0;
	string s1 = " ";
	for (int i = 1; i <= n; i++) {
		int a1;
		cin >> a1 >> s[i].c;
		s[i].a = s[i - 1].a + a1;
		for (int j = 1; j <= a1; j++) {
			s1 += s[i].c;
		}
	}
	long long i = 1, j = s[n].a;
	long long cnt = 0;
	int ai = 1, aj = n - 1;

	int len = s1.size();
	for (int i = 1; i < len / 2 + 1; i++) {
		if (s1[i] != s1[len - i]) {
			cnt++;
		}
	}
	cout << cnt ;
	return 0;
}
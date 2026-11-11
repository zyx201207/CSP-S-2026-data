#include <bits/stdc++.h>
using namespace std;
int n, m, sum;
char c;
string s, s1;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	while (n--) {
		cin >> m >> c;
		for (int i = 1; i <= m; i++) {
			s += c;
		}
	}
	for (int i = s. size() - 1; i > 0; i--) {
		c = s[i];
		s1 += c;
	}
	for (int i = 0; i < s. size(); i++) {
		if (s[i] != s1[i]) {
			sum++;
		}
	}
	cout << sum / 2;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
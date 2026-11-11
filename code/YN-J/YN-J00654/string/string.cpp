#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	string s;
	char c;
	int m;
	for (int i = 0; i < n; i++) {
		cin >> m >> c;
		for (int j = 0; j < m; j++) {
			s += c;
		}
	}
	long long y = 0;
	for (int i = 0; i < s.size() / 2; i++) {
		bool t = true;
		for (int i = 0; i < s.size() / 2; i++) {
			if (s[i] != s[s.size() - i]) {
				t = false;
			}
		}
		if (t) {
			break;
		} else {
			if (s[i] != s[s.size() - i]) {
				s[i] = s[s.size() - i];
				y++;
			}

		}
	}
	cout << y;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
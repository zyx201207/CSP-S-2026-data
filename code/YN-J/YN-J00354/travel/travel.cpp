#include <bits/stdc++.h>

using namespace std;

bool q3(const string &a, const string &b) {
	if (a[2] == 'A' || a[2] == 'B' || a[2] == 'C') {
		if (b[2] == 'A' || b[2] == 'B' || b[2] == 'C')
			return 1;
		else
			return 0;
	} else if (a[2] == 'D' || a[2] == 'F') {
		if (b[2] == 'D' || b[2] == 'F')
			return 1;
		else
			return 0;
	}
	return 0;
}

bool q4(const string &a, const string &b) {
	if (a[2] == 'A' || a[2] == 'C') {
		if (b[2] == 'B')
			return 1;
	}
	if (a[2] == 'B') {
		if (b[2] == 'A' || b[2] == 'C')
			return 1;
		else
			return 0;
	}
	if (a[2] == 'D' || a[2] == 'F') {
		if (b[2] == 'D' || b[2] == 'F')
			return 1;
		else
			return 0;
	}
	return 0;
}

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	bool ans[4] = {0};
	if (c1 == c2) {
		ans[0] = 1;
		if (s1[0] == s2[0] && s1[1] == s2[1]) {
			ans[1] = 1;
			if (q3(s1, s2)) {
				ans[2] = 1;
				if (q4(s1, s2)) {
					ans[3] = 1;
				}
			}
		}
	}
	for (int i : ans)
		cout << i;
	cout << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
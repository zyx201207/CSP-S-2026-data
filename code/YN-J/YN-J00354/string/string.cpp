#include <bits/stdc++.h>

using namespace std;

struct pd {
	int total;
	char sy;
};

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	vector<pd> s(n);
	for (int i = 0; i < n; i++) {
		int a;
		char c;
		cin >> a >> c;
		s[i].total = a;
		s[i].sy = c;
	}
	long long ans = 0;
	for (int i = 0, j = 0, js = 1; js < s.size(); js++) {
		if (s[i].total != s[s.size() - 1 - j].total && s[i].sy != s[s.size() - 1 - j].sy) {
			int tmp = min(s[i].total, s[s.size() - 1 - j].total);
			ans += tmp;
			s[i].total -= tmp;
			s[s.size() - 1 - j].total -= tmp;
		} else if (s[i].sy != s[s.size() - 1 - j].sy) {
			int tmp = s[i].total;
			ans += tmp;
			s[i].total -= tmp;
			s[s.size() - 1 - j].total -= tmp;
		} else if (s[i].total == s[s.size() - 1 - j].total) {
			int tmp = s[i].total;
			s[i].total -= tmp;
			s[s.size() - 1 - j].total -= tmp;
		} else {
			int tmp = min(s[i].total, s[s.size() - 1 - j].total);
			s[i].total -= tmp;
			s[s.size() - 1 - j].total -= tmp;
		}
		if (s[i].total == 0)
			i++;
		if (s[s.size() - 1 - j].total == 0)
			j++;
	}
	cout << ans << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
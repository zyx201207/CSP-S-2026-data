#include <bits/stdc++.h>
using namespace std;

bool hw(string s) {
	string s1 = s;
	reverse(s.begin(), s.end());
	if (s == s1) {
		return 1;
	} else {
		return 0;
	}
}

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	long long a;
	char c;
	string s;
	long long cnt = 0;
	string sq, sh;
	for (int i = 1; i <= n; i++) {
		cin >> a >> c;
		for (int i = 1; i <= a; i++) {
			s += c;
		}
	}
	if (hw(s)) {
		cout << "0";
	} else {
		int b = s.size();
		if (b % 2 == 1) {
			sq = s.substr(0, ((b + 1) / 2) - 1);
			sh = s.substr(((b + 1) / 2), b - (((b + 1) / 2) + 1) + 1);
			reverse(sh.begin(), sh.end());
		} else {
			sq = s.substr(0, (b / 2) );
			sh = s.substr(b / 2, b - (b / 2));
			reverse(sh.begin(), sh.end());
		}
		for (int i = 0; i <= sq.size() - 1; i++) {
			if (sq[i] != sh[i]) {
				cnt++;
			}
		}
		cout << cnt;
	}
	return 0;
}


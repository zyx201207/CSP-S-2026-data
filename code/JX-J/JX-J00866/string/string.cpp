#include <bits/stdc++.h>
using namespace std;
int n, cnt;
long long cur[200005];
char c[200005];
string s;
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	bool flag = 0;
	for (int i = 1; i <= n; i++) {
		cin >> cur[i];
		cin >> c[i];
		if (c[i] != c[i - 1] && i > 1) flag = 1;
		for (int j = 0; j < cur[i]; j++) {
			s = s + c[i];
		}
	}
	if (flag == 0) {
		cout << "0";
		return 0;
	}
	long long len = s.size();
	for (int i = 0; i <= len / 2; i++) {
		if (s[i] != s[len - i - 1]) {
			cnt++;
		}
	}
	cout << cnt;
    return 0;
}

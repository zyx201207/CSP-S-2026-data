#include <bits/stdc++.h>
using namespace std;
int n;
int a[200005];
long long qzh[200005];
char c[200005];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	long long ans = 0;
	long long sum = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> c[i];
		qzh[i] = qzh[i - 1] + a[i];
	}
	sum = qzh[n];
	if (qzh[n] < 1e9) {
		string s;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= a[i]; j++) {
				s += c[i];
			}
		}
		//cout << s << endl;
		int len = s.size();
		//cout << len << endl;
		for (int i = 0; i <= len / 2; i++) {
			if (s[i] != s[len - 1 - i]) {
				ans++;
			}
		}
		cout << ans;
		return 0;
	}
	int f = 0;
	char ch;
	ch = c[1];
	for (int i = 1; i <= n; i++) {
		if (c[i] == ch) {
			f = 1;
			break;
		}
	}
	if (f == 0) {
		cout << 0;
	} else {
		cout << qzh[n];
	}
	return 0;
}
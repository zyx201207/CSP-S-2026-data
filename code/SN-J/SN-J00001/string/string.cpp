#include <bits/stdc++.h>
using namespace std;
struct ak{
	long long a;
	char c;
}x[1000005];
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	string s;
	long long cnt = -1;
	for (int i = 1; i <= n; i++) {
		cin >> x[i].a >> x[i].c;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= x[i].a; j++) {
			cnt++;
			s += x[i].c;
		}
	}
	cnt++;
	int ans = 0;
	for (int i = 0; i < cnt / 2; i++) {
		if (s[i] != s[cnt - 1 - i]) {
			ans++;
		}
	}
	cout << ans;
	return 0;
}


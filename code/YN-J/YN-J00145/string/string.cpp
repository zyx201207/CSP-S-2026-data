#include <bits/stdc++.h>
using namespace std;
long long m[1000001];
char ch[1000001];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	long long n, t = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> m[i];
		cin >> ch[i];
		t += m[i];
	}
	long long ans = 0;
	int x = 0;
	string s;
	for (int i = 1; i <= n; i++) {
		for (int j = x + 1; j <= x + m[i]; j++) {
			s[j] = ch[i];
		}
		x += m[i];
	}
	for (int i = 1; i <= t / 2; i++) {
		if (s[i] != s[t - i + 1])
			ans++;
	}
	cout << ans;
	return 0;
}
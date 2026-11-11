#include <bits/stdc++.h>
using namespace std;
int a[200010];
char c[200010];
string s;
long long ans;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> c[i];
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= a[i]; j++) {
			s += c[i];
		}
	}

	int j = s.size() - 1;
	for (int i = 0; i < s.size() / 2; i++) {
		if (s[i] != s[j]) {
			ans++;
		}
		j--;
	}
	cout << ans;
	return 0;
}

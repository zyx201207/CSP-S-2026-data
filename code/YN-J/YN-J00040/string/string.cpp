#include <bits/stdc++.h>
using namespace std;
string s;
int a[200005];
char b[200005];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	long long ans = 0, cnt = 0, ans1 = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {


		cin >> a[i] >> b[i];
		ans += a[i];
		for (int j = 1; j <= a[i]; j++)
			s += b;
	}

	for (int i = 1; i <= ans / 2 + 1; i++) {
		if (s[i] != s[ans - i])
			cnt++;
	}
	cout << cnt;
	return 0;


}
#include <bits/stdc++.h>
using namespace std;
const int N = 2 * 1e5 + 5;
long long n;
long long a[N];
char s[N];
long long ans;
string t;
string x, y;

int main() {
	//freopen(" travel.in", "r", stdin);
	//freopen(" travel.out", "w", stdout);
	//ios::syoc::with::stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	int k = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> s[i];
		for (int j = 1; j <= a[i]; j++, k++) {
			t += s[i];
			if (k <= n / 2)
				x += s[i];
			else
				y += s[i];
		}
	}
	for (int i = 0 ; i <= k / 2; i++) {
		if (x[i] != y[k / 2 - i - 1])
			ans++;
	}
	cout << ans;
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[200005];
char c[200005];
ll pre[200005];
string s, s1;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> c[i];
		for (int j = 1; j <= a[i]; j++) {
			s = s + c[i];
		}
	}
	if (n == 1) {
		cout << 0;
		return 0;
	}
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		pre[i] = pre[i - 1] + a[i];
	}


	bool modnum = (pre[n] % 2 == 0);
	ll midnum = 0;
	if (modnum) {
		midnum = pre[n] / 2;
	} else {
		midnum = (pre[n] + 1) / 2;
	}
	for (int i = 0; i <= midnum; i++) {
		int x = pre[n] - i - 1;
		if (s[i] != s[x]) {
			ans++;
			s[x] == s[i];
		}
	}
	cout << ans << endl;

	return 0;
}

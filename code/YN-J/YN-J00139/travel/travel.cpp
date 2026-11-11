#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string s, ss, a, aa;
	cin >> s >> ss >> a >> aa;
	if (s == a) {
		cout << 1;
	} else {
		cout << 0;
	}
	int n;
	cin >> n;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (ss[i] == aa[i]) {
			cout << 1;
		} else {
			cout << 0;
		}
		if (ss[2] == 'A' || ss[2] == 'B' || ss[2] == 'C') {
			cout << 1;
		} else if (aa[2] == 'D' || aa[2] == 'F') {
			cout << 1;
		} else if (ss[i + 1] == aa[i]) {
			cout << 1;
		} else if {
		ans++;
		continue;
	}
	cout << ans;
}
if (s[1] != 1 && s[1] != 16 && a[1] != 1 && a[1] != 16 && s[1] <= 17 && a[1] <= 17) {
		cout << 1;
	} else {
		cout << 0;
		return 0;
	}
	return 0;
}
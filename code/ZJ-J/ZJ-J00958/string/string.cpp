#include <bits/stdc++.h>

using namespace std;

const int maxL = 1e8 + 5;

int n, a, ans;
long long L;
char c, s[maxL];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	ios :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	for (cin >> n; n; n --) {
		cin >> a >> c;
		if ((L += a) > 1e8) return cout << 0, 0;
		for (int i = L - a + 1; i <= L; i ++) s[i] = c;
	}
	
	for (int i = 1; i <= (L + 1) / 2; i ++) {
		ans += s[i] != s[L - i + 1];
	}
	return cout << ans, 0;
}


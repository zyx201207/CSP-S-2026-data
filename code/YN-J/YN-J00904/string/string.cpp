#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 2e5 + 5;

struct Node {
	int a;
	char c;
} S[MAXN];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> S[i].a >> S[i].c;
	}

	int l = 1, r = n;
	ll ans = 0;
	while (l < r) {
		int gb = min(S[l].a, S[r].a);
		if (S[l].c != S[r].c) {
			ans += gb;
		}
		if (S[l].a > S[r].a) {
			S[l].a -= gb;
			r--;
		} else {
			S[r].a -= gb;
			l++;
		}
	}
	cout << ans;
	return 0;
}
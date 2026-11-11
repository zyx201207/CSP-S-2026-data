#include <bits/stdc++.h>
using namespace std;
string S;
int n, a, ans;
char c;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a >> c;
		for (int j = 0; j < a; ++j)
			S = S + c;
	}
	for (int i = 0; i < S.size() / 2; ++i) {
		if (S[i] != S[S.size() - i - 1])
			ans++;
	}
	cout << ans;
	return 0;
}
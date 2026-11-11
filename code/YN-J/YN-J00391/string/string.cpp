#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN = 2e5 + 5;


int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	string t = "";
	for (int i = 1; i <= n; i++) {
		int a;
		char c;
		cin >> a >> c;
		while (a--)
			t += c;
	}
	int ans = 0;
	for (int i = 0; i < t.size() / 2; i++) {
		if (t[i] != t[t.size() - i - 1])
			ans++;
	}
	cout << ans;
	return 0;
}
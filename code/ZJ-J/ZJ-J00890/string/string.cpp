#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 2 * 1e5 + 5;
int n, ans;
char c[maxn];
LL a[maxn];
string s;
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> c[i];
		for (int j = 1; j <= a[i]; j++)
			s += c[i];
	}
	for (int i = 0; i < s.length() / 2; i++)
		if (s[i] != s[s.length() - i - 1])
			ans++;
	cout << ans;
}
#include <iostream>
#define ll long long
using namespace std;
int n;
int a[200050];
char c[200050];
string s;
ll ans; 
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i] >> c[i];
		for (int j = 1; j <= a[i]; ++j)
			s += c[i];
	}
	for (int l = 0, r = s.size() - 1; l <= r; ++l, --r)
		if (s[l] != s[r]) ++ans;
	cout << ans;
	return 0;
}

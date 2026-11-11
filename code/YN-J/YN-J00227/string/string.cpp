#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 10;
int n;
unsigned long long ans;

struct node {
	int a;
	char c;
} a[N];
string s;

signed main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].a >> a[i].c;
		for (int j = 1; j <= a[i].a; j++)
			s += a[i].c;
	}
	int l = s.size();
	for (int i = 0; i < l / 2; i++) {
		if (s[i] == s[l - i - 1])
			continue;
		ans += 1;
	}
	cout << ans;
	return 0;
}
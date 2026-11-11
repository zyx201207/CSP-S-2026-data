#include <bits/stdc++.h>
//#define int long long
using namespace std;
long long n, ans;
string s;

struct node {
	long long x;
	char c;
} a[200005];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i].x >> a[i].c;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= a[i].x; j++)
			s += a[i].c;
	}
	for (int i = 0, j = s.size() - 1; i <= j; i++, j--)
		if (s[i] != s[j])
			ans++;
	cout << ans;
	return 0;
}
/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
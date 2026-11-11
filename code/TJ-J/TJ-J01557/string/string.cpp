#include <bits/stdc++.h>
using namespace std;
int n;

struct x {
	int a;
	char c;
} x[200005];
string s;
long long ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> x[i].a >> x[i].c;
		for (int j = 1; j <= x[i].a; j++) {
			s += x[i].c;
		}
	}
	long long l = 0;
	long long r = (int)s.size() - 1;
	while ( l <= r ) {
		if ( s[l] != s[r] ) {
			ans++;
		}
		l++;
		r--;
	}
	cout << ans;
	return 0;
}
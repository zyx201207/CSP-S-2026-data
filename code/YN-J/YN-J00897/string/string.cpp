#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, cnt;
string s;

signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	while (n--) {
		int aa;
		char a;
		cin >> aa >> a;
		while (aa--) {
			s += a;
		}
	}
	int i = 0, j = s.size() - 1;
	while (1) {
		if (s[i] != s[j])
			cnt++;
		if (i == (s.size() - 1 ) / 2 )
			break;
		i++;
		j--;
	}
	cout << cnt;
	return 0;
}
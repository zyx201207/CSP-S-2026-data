#include <bits/stdc++.h>
#define int long long
using namespace std;
string s;
int ans, cnt, j;
signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w" , stdout);
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		char x;
		int op;
		cin >> op >> x;
		ans += op;
		int jj = j;
		for (j; j <= jj + op - 1; j++) {
			s[j] = x;
		}
	}
	int aans = ans / 2;
	for (int i = 1; i <= aans; i++){
		if (s[i] != s[ans - i + 1]) cnt++;
	}
	cout << cnt;
	return 0;
}

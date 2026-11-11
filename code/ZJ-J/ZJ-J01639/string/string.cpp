#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, cnt = 0, len;
string s;

signed main () {
	
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	cin >> n;
	while (n--) {
		int x;
		char c;
		cin >> x >> c;
		while (x--) {
			s += c;
		}
	}
	
	len = s.length();
	
	for (int i = 0; i <= (len-1)/2; i++) {
		int j = len-i-1;
		if (s[i] != s[j]) cnt++;
	}

	cout << cnt;
	
	return 0;
}


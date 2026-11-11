#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
string s;
string re(string s) {
	string s1;
	for (int i = s.length() - 1; i >= 0; i--) s1 += s[i];
	return s1;
}
signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout); 
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x;
		char a;
		cin >> x >> a;
		for (int j = 1; j <= x; j++) s += a;
	}
	string op;
	op = re(s);
	if (op == s) cout << 0;
	else {
		int dis = s.length();
		int cnt  = 0;
		int mid = 0;
		if (dis % 2 == 0) { 
			mid = dis / 2;
			for (int l = 1, r = dis; l <= mid, r >= mid + 1; l++, r--) { 
				if (s[l - 1] != s[r - 1]) cnt++;
			}
			cout << cnt;
		}
		else { 
			mid = dis / 2 + 1;
			for (int l = 1, r = dis; l <= mid, r >= mid; l++, r--) { 
				if (s[l - 1] != s[r - 1]) cnt++;
			}
			cout << cnt;
		}
	}
	return 0;
}

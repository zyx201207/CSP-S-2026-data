#include <bits/stdc++.h>
#define N 200005
using namespace std;
namespace eggy {
	void work() {
		bool ok = 1;
		int n, a[N];
		char c[N];
		string s;
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> a[i] >> c[i];
		for (int i = 1; i <= n; i++) {
			int d = a[i];
			while (d--) s += c[i];
		}
//		cout << s;
		int len = s.size();
		for (int i = 0; i < len; i++) 
			if (s[i] != s[s.size() - i - 1]) {
				ok = 0;
				break;
			}
		if (ok) {
			cout << 0;
			return;
		}
		if (len == 2) {
			char c1 = s[0], c2 = s[1];
			if (c1 == c2) {cout << "0"; return;}
			else {cout << "1"; return;}
		}
		string s1, s2;
		int sum1 = 0;
		if (len % 2) {
			for (int i = 0, k = len - 1; i <= (len - 1) / 2 - 1 && k >= (len + 1) / 2; i++, k--) 
				if (s[i] != s[k]) sum1++;
		}
		else 
			for (int i = 0, k = len - 1; i <= len / 2 - 1 && k >= len / 2; i++, k--)
				if (s[i] != s[k]) sum1++;
		cout << sum1;
		 
	}
}
signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	return eggy::work(), 0;
} 
/*
6
1000000 a
1000000 a
1000000 a
1000000 b
1000000 b
1000000 b
*/
/*
>v< >v< >v< >v<
AC AC AC AC AC 
*/

#include <bits/stdc++.h>
using namespace std;

int solve(string s) {
	int l = 0 , r = s.size();
	r -= 1;
	int daan = 0;
	while (l <= r) {
		if (s[l] != s[r]) {
			daan++;
		}
		l ++;
		r --;
	}
	return daan;
} 

int main() {
	freopen ("string.in" , "r" , stdin);
	freopen ("string.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	if (n == 1) {
		string s;
		long long sum = 0;
		for (int i = 1; i <= n; i++) {
			int x;
			char a;
			cin >> x >> a;
			sum += x;
		}		
			cout << 0;
		return 0;
	} else if (n == 2) {
		string s;
		long long sum = 0;
		bool flag = 0 , fg = 0;
		char same;
		int mn = 1e8;
		for (int i = 1; i <= n; i++) {
			int x;
			char a;
			cin >> x >> a;
			mn = min (x , mn);
			if (flag == 0) {
				same = a;
				flag = 1;
			}
			if (same != a) {
				fg = 1;
			}  
			sum += x;
		}
		if (fg == 0) {
			cout << 0; 
		} else {
			cout << mn;
		}
	} else {
		string s;
		long long sum = 0;
		bool flag = 0 , fg = 0;
		char same;
		int mn = 1e8;
		for (int i = 1; i <= n; i++) {
			int x;
			char a;
			cin >> x >> a;
			if (flag == 0) {
				same = a;
				flag = 1;
			}
			if (same != a) {
				fg = 1;
			}  
			sum += x;
			for (int i = 1; i <= x; i++) {
				s += a;
			}
		}
		if (fg == 0) {
			cout << 0; 
		}		
		int ans = solve(s);
		cout << ans;
	}
	return 0;
}

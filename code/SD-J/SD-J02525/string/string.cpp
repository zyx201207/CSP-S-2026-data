#include <bits/stdc++.h>
using namespace std;
int n, m, ans, len;
string s;
char c;
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	s = s + ' ';
	for(int i = 1; i <= n; i++) {
		cin >> m >> s;
		while(m--) s = s + c;
	}
	
	for(int i = 0; i < len / 2; i++) {
		if(s[i] != s[len - i + 1]) ans++;
		
	}
	cout << ans;
	return 0;
} 

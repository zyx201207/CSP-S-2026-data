#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	unsigned long long n;
	string s = "";   
	cin >> n;  
	for (unsigned long long i = 1;i <= n; i++) {
		unsigned long long a;
		char c;
		cin >> a >> c;
		string tmp = "";
		tmp += c;
		for (unsigned long long j = 1;j <= a; j++) s += c;
	}    
	unsigned long long len = s.size() - 1, ans = 0;
	for (unsigned long long i = 0;i <= len / 2; i++) 
		if (s[i] != s[len - i]) ans++;
	cout << ans;
	return 0;
}
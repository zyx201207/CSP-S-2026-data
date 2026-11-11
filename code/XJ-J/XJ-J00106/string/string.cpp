#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
ll n, len, ans;
string s;

int main() {
	
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	cin >> n;
	for(int i = 1, x; i <= n; i ++) {
		char c;
		cin >> x >> c;
		for(int j = 1; j <= x; j ++) {
			s += c;
		}
		len += x;
	}
	
	ll mid = (1 + len) >> 1;
	for(int i = 0; i < mid; i ++) {
		if(s[i] != s[len - i - 1]) {
			ans ++;
		}
	}
	
	cout << ans;
	
	return 0;
} 

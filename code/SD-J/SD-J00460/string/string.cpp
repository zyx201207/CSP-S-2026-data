#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5; 

int n, m, x, cnt;
long long len;
char c;
string s;
int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0);
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	cin >> n;
	for (int i = 1; i <= n; i ++) {
		cin >> m >> c;
		len += m;
		for (int j = 1; j <= m; j ++) {
			s += c;
		}
	}
		//len = s.size();
	s = ' ' + s;
	x = len / 2;
		
		//cout << s << x << '\n';
	for (int i = 1; i <= x; i ++) {
		if (s[i] != s[len + 1 - i]) {
			cnt ++;
		}
			//cout << i << ' ' << j << '\n';
	}
	cout << cnt;
	
	
	
	return 0;
} 

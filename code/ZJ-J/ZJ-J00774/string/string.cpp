#include <bits/stdc++.h>
using namespace std;
int n, a, ans, len, mx;
char c;
string s;
int main(){
	freopen ("string.in", "r", stdin);
	freopen ("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a >> c;
		for (int j = 1; j <= a; j++)  s += c;
		len += a;
	}
	mx = (len - 1) / 2;
	for (int i = 0; i <= mx; i++)
		if (s[i] != s[len - i - 1])
			ans++;
	cout << ans;
	return 0;
}

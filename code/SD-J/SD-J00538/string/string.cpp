#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
int x;
char y;
string s1;
int ans;
signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	while (n--) {
		cin >> x >> y;
		while (x--) s1 += y;
	}
	string s2 = s1;
	reverse(s2.begin(), s2.end());
	int len = s1.length();
	for (int i = 0; i < (len + 1) / 2; i++) 
		if (s1[i] != s2[i]) ans++;
	cout << ans;
	return 0;
}

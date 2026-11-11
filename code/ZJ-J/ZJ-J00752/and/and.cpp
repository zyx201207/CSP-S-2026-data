#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
long long n, m, s[N], a[N], c[N], b[N];
string str[N];
bool cmp (string a, string b) {
	return a > b;
}
int main () {
	freopen ("and.in", "r", stdin);
	freopen ("and.out", "w", stdout);
	s[0] = 1;
	for (int i = 1; i <= 30; i++)
		s[i] = s[i - 1] * 2;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		long long x = a[i];
		for (int j = 30; j >= 0; j--)
			if (x >= s[j]) x -= s[j], c[j]++; 
	}
	long long mx = -1;
	for (int i = 30; i >= 0; i--)
		if (c[i] >= m) {
			mx = i;
			break;
		}
	
	if (mx == -1) {
		cout << 0;
		return 0;
	}
	long long cnt = 0;
	for (int i = 1; i <= n; i++)
		if (a[i] >= s[mx]) {	
			for (int j = mx; j >= 0; j--)
				if (a[i] >= s[j]) a[i] -= s[j], str[cnt] += "1";
				else str[cnt] += "0"; 
			cnt++;
		}
	sort (str, str + cnt, cmp);
	long long ans = 0;
	for (int i = 0; i < str[m - 1].size(); i++)
		if (str[m - 1][i] == '1') ans += s[mx - i];
	cout << ans;
	return 0;
}                                          
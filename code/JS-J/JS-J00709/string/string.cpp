#include <bits/stdc++.h>

using namespace std;


const int N = 3e5 + 5;

int n, a[N];
char c[N];
string s;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> c[i];
		for (int j = 1; j <= a[i]; j++)
			s.push_back (c[i]);
	}
	string v = s;
	reverse(v.begin(), v.end());
	int ans = 0;
	for (int i = 0; i < (int) s.size(); i++)
		if (s[i] != v[i])
			ans++;
	cout << ans / 2;
}

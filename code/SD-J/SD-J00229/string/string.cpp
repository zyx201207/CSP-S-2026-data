#include <bits/stdc++.h>
using namespace std;
#define ll long long

string s;
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++) {
		int a;
		char c;
		scanf("%d %c", &a, &c);
		while (a--) s += c;
	}
	int ans = 0;
	for (int i = 0; (i + 1) * 2 < s.size(); i++) {
		if (s[i] != s[s.size() - 1 - i]) ans++;
	}
	
	cout << ans << endl;
	return 0;
}

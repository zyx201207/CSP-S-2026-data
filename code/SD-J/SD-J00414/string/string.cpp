#include <bits/stdc++.h>
using namespace std;
int n;
int a[200005], top;
char c[200005], s[100000005];
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> c[i];
		for (int j = 1; j <= a[i]; j++) {
			top++;
			s[top] = c[i];
		} 
	}
	int l = 1, r = top, ans = 0;
	while (l <= r) {
		if (s[l] != s[r]) ans++;
		l++, r--;
	}
	cout << ans;
	return 0;
} 

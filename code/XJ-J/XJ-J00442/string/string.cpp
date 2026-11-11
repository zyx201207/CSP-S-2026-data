#include <bits/stdc++.h>
using namespace std;

int n;
long long ans = 0;
int a[200005];
char b[200005];
string s1, s2;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i] >> b[i];
	}
	for(int i = 1; i <= n/2; i++) {
		if(a[i] != b[n-i+1] && b[i] != b[n-i+1]) {
			ans += max(a[i], a[n-i+1]);
		} else if (a[i] != a[n-i+1] && b[i] == b[n-i+1]) {
			ans += max(a[i], a[n-i+1]) - min(a[i], a[n-i+1]);
		} else ans += 0;
	}
	cout << ans;
	
	return 0;
}
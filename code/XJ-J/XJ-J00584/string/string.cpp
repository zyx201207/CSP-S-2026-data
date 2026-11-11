#include <bits/stdc++.h>
using namespace std;

int n, a[200005], sum;
string s; 
bool f = 1, f1; 

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i] >> s[i];
	
	for (int i = 2; i <= n; i++) if (s[i] != s[i-1]) f = 0;
	if (f) {
		cout << 0;
		return 0;
	}

	for (int i = 1; i <= n/2; i++) {
		if (a[i] == a[n+1-i] && s[i] != s[n+1-i]) sum += a[i];
		else if(a[i] != a[n+1-i] && s[i] == s[n+1-i]) sum += abs(a[i]-a[n+1-i])+2;
	}
	cout << sum;

	return 0;
}
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 2e5;
bool spA = true; // Ai a[i] = 1
int n;
int a[MAXN + 7];
char s[100000007];
int l;
char c[MAXN + 7];
int gcdZAIa;

signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> c[i];
		if (a[i] != 1) spA = false;
		if (i == 1) gcdZAIa = a[i];
		else gcdZAIa = __gcd(a[i], gcdZAIa);
	}
	for (int i = 1; i <= n; i++) {
		a[i] /= gcdZAIa;
		for (int j = l + 1; j <= l + a[i]; j++) {
			s[j] = c[i];
		}
		l += a[i];
	}
	if (spA) {
		//cout << "SPA\n";
		int ans = 0;
		for (int i = 1; i <= n / 2; i++) {
			if (c[i] != c[n - i + 1])
				ans++;
		}
		cout << ans << '\n';
		return 0;
	}
	if (n == 1) {
		cout << 0 << '\n';
	}
	int ans = 0;
	for (int i = 1; i <= l / 2; i++) {
		//cout <<i<< ' ' << s[i] << ' ' << s[l - i + 1] << '\n';
		if (s[i] != s[l - i + 1])
			ans++;//, cout << i << '\n';
	}
	cout << ans * gcdZAIa << '\n';
	
	
	return 0;
}

/*
9  
1 b 
1 c
1 d
1 b
1 b
1 b
1 b
1 b
1 b

*/

#include <bits/stdc++.h>
using namespace std;
long long n, ans, length;
string s;
int main(){
	freopen ("string.in", "r", stdin); 
	freopen ("string.out", "w", stdout);
	scanf ("%lld", &n);
	for (int i = 1; i <= n; i++){
		long long x;
		char c;
		scanf ("%lld%c", &x, &c);
		length += x;
		for (long long j = 1; j <= x; j++){
			s += c;
		}
	}
	for (long long i = 0; i < length >> 1; i++){
		if (s[i] != s[length - i - 1]) ans++;
	}
	cout << ans;
	return 0;
}

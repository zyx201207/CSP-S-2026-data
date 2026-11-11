#include<bits/stdc++.h>
using namespace std;
const long long N = 1E9;
char s[N+2];
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	long long n;
	cin >> n;
	long long cnt = 1;
	long long cntnt = 0;
	for(long long i = 1; i <= n; i++) {
		long long a;
		cin >> a;
		char b;
		cin >> b;
		cntnt += a;
		for(long long j = 1; j <= a; j++) {
			s[cnt] = b;
			cnt++;
		}
	}
	long long ans = 0;
	long long t = cntnt;
	if(t%2 == 0) {
		t/=2;
	}
	else {
		t/=2;
		t++;
	}
	for(long long i = 1; i <= t; i++) {
		if((char)(s[i]) != (char)(s[cntnt+1-i])) {
			ans++;
			s[cntnt+1-i] = s[i];
		}
	}
	cout << ans;
	return 0;
}

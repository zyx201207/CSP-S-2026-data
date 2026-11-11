#include <bits/stdc++.h>
using namespace std;

struct word {
	long long c;
	char s;	
}; 

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	long long n, ans = 0;
	cin >> n;
	word w[n + 5];
	for(long long i = 0; i < n; i ++) {
		cin >> w[i].c >> w[i].s;
	}
	for(long long i = 0, j = n - 1; i < j; i += 0, j -= 0) {
		long long add = min(w[i].c, w[j].c);
		w[i].c -= add; w[j].c -= add;
		if(w[i].s != w[j].s) {
			ans += add;
		}
		if(w[i].c == 0) i ++;
		if(w[j].c == 0) j --;
	}
	cout << ans;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
bool k;
long long n, a[200005];
char s[200005];
long long c;
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	cin >> n;
	for(int i = 1; i <= n; i ++) {
		cin >> a[i] >> s[i];
		if(s[i] == s[i - 1]) k = 1;
		else k = 0;
	}
	if(k == 1) {
		cout << 0;
		return 0;
	}
	int l = 1, r = n;
	while(r > l) {
		if(s[l] != s[r]) {
			if(r - l == 1) {
				c += abs(a[l] - a[r]);
				break;
			}
			if(a[l] == a[r]) {
				c += a[l];
				l ++;
				r --;
			}
			else if(a[l] > a[r]) {
				c += a[l] - a[r];
				a[l] -= a[r];
				r --;
			}
			else {
				c += a[r] - a[l];
				a[r] -= a[l];
				l ++;
			}
		}
		else {
			if(r - l == 1) {
				break;
			}
			if(a[l] == a[r]) {
				l ++;
				r --;
			}
			else if(a[l] < a[r]) {
				c += a[r] - a[l];
				a[r] -= a[l];
				l ++;
			}
			else {
				c += a[l] - a[r];
				a[l] -= a[r];
				r --;
			}
		}
	}
	cout << c;
	
	return 0;
}


#include<bits/stdc++.h>
using namespace std;
long long a[200005];
char c[200005];
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	long long n, len = 0;
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		cin >> c[i];
		len += a[i];
	}
	long long ans = 0, l = 1, r = n;
	while(l < r) {
		if(a[l] > a[r]) {
			if(c[l] != c[r]) {
				ans += a[r];
			}
			a[l] -= a[r];
			r--;
		}
		else if(a[r] > a[l]) {
			if(c[r] != c[l]) {
				ans += a[l];	
			}
			a[r] -= a[l];
			l++;
		}
		else if(a[l] == a[r]) {
			if(c[l] != c[r]) {
				ans += a[l];
				
			}
			l++;
			r--;
		}
	}
	cout << ans;
	return 0;
}

#include <bits/stdc++.h>

using namespace std;

const int N = 2e5+78;
typedef long long ll;

ll a[N];
char c[N];

int main () {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	for (int i = 1;i <= n;i++) {
		scanf("%lld %c",&a[i],&c[i]);
	}
	ll ans = 0;
	int l = 1,r = n;
	while (l < r) {
		if (a[l] == a[r] && c[l] == c[r]) {
			l++;r--;
		} else if (a[l] == a[r] && c[l] != c[r]) {
			ans += a[l];
			c[r] = c[l];
			l++;r--;
		} else if (a[l] != a[r] && c[l] == c[r]){
			if (a[l] > a[r]) {
				a[l] = a[l] - a[r];
				r--;
			} else {
				a[r] = a[r] - a[l];
				l++;
			}
		} else if (a[l] != a[r] && c[l] != c[r]) {
			if (a[l] > a[r]) {
				a[l] = a[l] - a[r];
				ans += a[r];
				c[r] = c[l];
				r--;
			} else {
				a[r] = a[r] - a[l];
				ans += a[l];
				c[l] = c[r];
				l++;
			}
			
		}
	}
	printf("%lld",ans);
	
	return 0;
}

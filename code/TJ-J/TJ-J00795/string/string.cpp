#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int n;
long long a[maxn], ans;
char c[maxn];
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i] >> c[i];
	int l = 1, r = n;
	while(l < r) {
		if(a[l] <= a[r]) {
			if(c[l] != c[r]) ans += a[l];
			a[r] -= a[l];
			l++;
		}
		else {
			if(c[l] != c[r]) ans += a[r];
			a[l] -= a[r];
			r--;
		}
	}
	cout << ans << endl;
	return 0;
}

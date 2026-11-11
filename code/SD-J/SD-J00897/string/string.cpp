#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ll n, a[200005], sh1 = 1, sh2, ans = 0;
	char s[200005];
	cin >> n;
	sh2 = n;
	for (ll i = 1; i <= n; i++)
		cin >> a[i] >> s[i];
	while (sh1 != sh2 && sh1 < sh2) {
		if (a[sh1] == a[sh2]) {
			if (s[sh1] != s[sh2])
				ans += a[sh1];
			sh1++;
			sh2--;
		}
		else {
			ll k = min(a[sh1], a[sh2]);
			if (s[sh1] != s[sh2]) ans += k;
			if (a[sh1] == k) {
				sh1++;
				a[sh2] -= k;
			}
			else {
				sh2--;
				a[sh1] -= k;
			}
		}
	}
	cout << ans;
	return 0;
}

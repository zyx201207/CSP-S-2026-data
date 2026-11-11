//RE? 12/25 <= 1e8
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define f first
#define s second

int n;
pair <ll,char> a[200010];
ll l = 0;
ll ans = 0;

int main () {
	ios::sync_with_stdio (0);
	cin.tie (0);
	cout.tie (0);
	
	freopen ("string.in","r",stdin);
	freopen ("string.out","w",stdout);
	
	cin >> n;
	
	a[0].f = 0;
	for (int i = 1;i <= n;i++) {
		int ai;
		char ci;
		cin >> ai >> ci;
		a[i].f = ai + a[i - 1].f;
		a[i].s = ci;
		l += ai;
	}
	//cout << s << " " << l;
	
	int p = 1,pp = n;
	for (ll i = 1;i <= l / 2;i++) {
		ll j = l - i + 1;
		if (i > a[p + 1].f) {
			p++;
		}
		if (j < a[pp - 1].f) {
			pp--;
		}
		if (a[p].s != a[pp].s) {
			ans++;
		}
	}
	cout << ans << "\n";
	//cout << clock ();
	return 0;
}

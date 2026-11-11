#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5+5;
ll n;
ll m, a[N], b[N], ans = 1;

int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); //一定要删注释
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	
	for (ll i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	for (ll i = 1; i <= n; i++) {
		b[i] = b[i - 1] + a[i];
		ll now = a[i];
		ll nl = 1, nr = i;
		while (nl <= nr) {
			if (nl == nr) {
				ans = max(ans, ll(i - nl +1));
				break;
			}
			ll nmid = (nl + nr + 1)/2;
			//cout << nmid <<" " << nl <<" " << nr<< endl;
			if ((ll(i - nmid + 1) * now) - (b[i] - b[nmid - 1]) <= m) {
				nr = nmid - 1;
				ans = max(ans, ll(i - nmid +1));
			} else {
				nl = nmid + 1;
			}
		}
		//cout << endl << ans << "\n";
	}
	cout << ans;
	return 0;
}
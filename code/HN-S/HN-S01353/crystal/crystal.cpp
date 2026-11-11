#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	freopen("crystal.in","r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n, m, a[50005],ans = 0;
	cin >> n >> m;
	for (ll i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);
	
	for (ll i = 0; i < n - 1; i++)
		a[i] = a[i + 1] - a[i];
	a[n - 1] = 0;	
	for (ll i = 0; i < n - 1; i++) {
		ll j = 0;ll x = m - a[i];
		while(++j) {
			x -= (1 + j) * a[i + j];
			if (x == 0 && a[i + j + 1] != 0) {
				j++;
				break;
			}
			else {
				if(x < 0) {
//					j--;
					break;
				}
			}
			if (i + j + 1== n) break;
 		}
		ans = max(ans, j + 1);
//      cout << j + 1 << " " ;
	}
	cout << ans << '\n';
	return 0;	
} 

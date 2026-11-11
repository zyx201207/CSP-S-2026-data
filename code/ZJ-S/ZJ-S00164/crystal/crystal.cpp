/*
	Name: crystal
	Copyright: CSP-S
	Author: CLP666
	Date: 31/10/26 15:40
	Description: 
*/
#include <bits/stdc++.h>
#define rks register
using namespace std;
typedef long long ll;
const ll MAXN = 5e5+5;
//const ll MOD = ;
ll n, m;
ll a[MAXN] = {-1e12}, b[MAXN];
                                      
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll l, r, mid, sum, mxp = 0;
	bool flg = true;
	cin >> n >> m;
	for(rks ll i = 1; i <= n; i++)
		cin >> a[i];
	sort(a+1, a+n+1);
	for(rks ll i = 1; i <= n; i++)
		b[i] = b[i-1]+a[i];
	for(rks ll i = 1; i <= n; i++) {
		if(a[i] != a[i-1]) {
			flg = false;
			break;
		}
	}
	if(flg) {
		cout << n;
		return 0;
	}
	l = 1, r = n;
	while(l+1 < r) {
		flg = false, mid = (l+r+1)>>1, mxp = 0;
		for(rks ll i = 1; i <= n-mid+1; i++) {
			sum = b[i+mid-1]-b[i-1];
			if(i <= mxp && mxp <= i+mid-1) {
				if(a[i+mid-1] > a[mxp])
					mxp = i+mid-1;
			} else {
				mxp = 0;
				for(rks ll j = 0; j < mid; j++)
					if(a[i+j]>=a[mxp])
						mxp = i+j;
			}
			if(mxp != 0 && mid*a[mxp]-sum <= m) {
				flg = true;
				break;
			}
		}
		if(flg)
			l = mid;
		else
			r = mid-1;
	}
	cout << l;
	return 0;
}

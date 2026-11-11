#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ll n,m;
	cin >> n >> m;
	ll a[n+5];
	for (int i =1 ; i <= n; i++){
		cin >> a[i];
	}
	sort(a+1,a+1+n);
	ll maxn=-1e7;
	for (ll i = 1; i <= n; i++){
		for (ll j = 1; j <= n; j++){
			if (j==i){
				continue;
			}
			ll o=a[i];
			for (ll k = j,g=1; g <= m; k++,g++){
				o=(o&a[k]);
			}
			maxn=max(maxn,o);
		}
	}
	cout << maxn;
	return 0;
}

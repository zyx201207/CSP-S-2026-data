#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n, m, mm, i, j, zcf, a[555555], cf[555555], ans;
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (ll k = 0 ; k < n ; k++){
		cin >> a[k];
	}
	sort(a, a + n);
	cf[0] = a[0];
	for (int k = 1 ; k < n ; k++){
		cf[k] = a[k] - a[k - 1];
	}
	i = 0, j = 0;
	while (j < n){
		mm += (j - i) * cf[j];
		while (mm > m){
			i++;
			mm -= zcf;
			zcf -= cf[i];
		}
		ans = max(ans, j - i + 1);
		j++;
		zcf += cf[j];
	}
	printf("%lld", ans);
	return 0;
} 

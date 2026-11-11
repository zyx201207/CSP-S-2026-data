#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n, m, cntm, cntmm, ii, aaa, jh, a[222222], aa[222222][66], cnt[222222], poww[66], ans;
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (ll i = 0 ; i < n ; i++){
		cin >> a[i];
		aaa = a[i];
		for (ll j = 0 ; aaa ; j++){
			aa[i][j] = aaa % 2;
			aaa = aaa / 2;
		}
	}
	poww[0] = 1;
	for (ll i = 1 ; i <= 61 ; i++){
		poww[i] = poww[i - 1] * 2;
	}
	for (ll i = 60 ; i >= 0 ; i--){
		cntm = 0;
		for (ll j = 0 ; j < n ; j++){
			if (aa[j][i]){
				cnt[cntm] = j;
				cntm++;
			}
		}
		if (cntm >= m){
			ans += poww[i];
			ii = i - 1;
			break;
		}
	}
	for (ll i = ii ; i >= 0 ; i--){
		cntmm = 0;
		for (ll j = 0 ; j < cntm ; j++){
			if (aa[cnt[j]][i]){
				jh = cnt[cntmm];
				cnt[cntmm] = cnt[j];
				cnt[j] = jh;
				cntmm++;
			}
		}
		if (cntmm >= m){
			ans += poww[i];
			cntm = cntmm;
		}
	}
	printf("%lld", ans);
	return 0;
}

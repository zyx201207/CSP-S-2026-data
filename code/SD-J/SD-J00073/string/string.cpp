#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll i, j, n, a[222222], csi, csj, minn, ans;
string c[222222];
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (ll k = 0 ; k < n ; k++){
		cin >> a[k] >> c[k];
	}
	minn = 0;
	i = 0, j = n - 1;
	csi += a[i];
	csj += a[j];
	while (i < j){
		if (csi < csj){
			if (c[i] != c[j]){
				ans += (csi - minn);
			}
			minn = min(csi, csj);
			i++;
			csi += a[i];
		}
		else if (csi > csj){
			if (c[i] != c[j]){
				ans += (csj - minn);
			}
			minn = min(csi, csj);
			j--;
			csj += a[j];
		}
		else if (csi == csj){
			if (c[i] != c[j]){
				ans += (csi - minn);
			}
			minn = min(csi, csj);
			i++;
			j--;
			csi += a[i];
			csj += a[j];
		}
	}
	printf("%lld", ans);
	return 0;
}

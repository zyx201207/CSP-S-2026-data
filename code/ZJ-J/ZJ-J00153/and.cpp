#include<bits/stdc++.h>
#define int long long
using namespace std;
int n, m, a[500001], ans, k;
signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	if(n == m){
		ans = a[1];
		for(int i = 1;i <= n;i++){
			ans = ans & a[i];
		}
	}
	if(m == 1){
		for(int i = 1;i <= n;i++){
			ans  = max(ans ,a[i]);
		}
	}
	if(m == 2){
		for(int i = 1;i <= n;i++){
			for(int j = i + 1;j <= n;j++){
				ans = max(ans, a[i] & a[j]);
			}
		}
	}
	if(m == n - 1){
		for(int i = 1;i <= n;i++){
			if(i == 1){
				k = a[2];
			}
			else{
				k = a[1];
			}
			for(int j = 1;j <= n;j++){
				if(j == i){
					continue;
				}
				k = k & a[j];
			}
			ans = max(ans, k);
		}
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
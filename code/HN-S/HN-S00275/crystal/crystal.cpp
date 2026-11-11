#include <bits/stdc++.h>
using namespace std;
int n, ca;
long long m, sum, ans, sw = -10000000000000, a[500005];
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a, a + n + 1);
	for(int i = 2; i <= n; i++){
		sum = 0;
		for(int j = 1; j < i; j++){
			sum += a[i] - a[j];
			if(sum >= m){
				if(sum == m && j + 1 > ans){
					ans = j + 1;
					sw = a[i];
				}
				else if(sum > m && j > ans){
					ans = j;
					sw = a[i];
				}
				else if(sum > m && j < ans){
					for(int k = 1; k <= i - 1; k++){
						if(a[k] == sw) ca++;
					}
					if(sw != -10000000000000) cout << ans + ca - 1;
					else cout << ans;
					return 0;
				}
				sum = 0;
			}
		}
	}
	for(int i = 1; i <= n; i++){
		if(a[i] == sw) ca++;
	}
	if(sw != -10000000000000) cout << ans + ca - 1;
	else cout << ans;
	return 0;
}

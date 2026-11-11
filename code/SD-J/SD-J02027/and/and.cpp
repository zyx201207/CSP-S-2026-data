#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[200005];
int main(){
	freopen ("and.in", "r", stdin); 
	freopen ("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort (a + 1, a + n + 1, greater<int>());
	if (m == 1){
		cout << a[1];
		return 0;
	}
	else if (m == n){
		int ans = 1;
		for (int i = 1; i <= n; i++){
			ans &= a[i];
		}
		cout << ans;
		return 0;
	}
	else if (m == n - 1){
		int maxa = 0;
		for (int i = 1; i <= n; i++){
			int ans = 1;
			for (int j = 1; j <= n; j++){
				if (j != i) ans &= a[i];
			}
			maxa = max (ans, maxa);
		}
		cout << maxa;
		return 0;
	}
	else if (m == 2){
		int maxa = 0;
		for (int i = 1; i <= n; i++){
			for (int j = i + 1; j <= n; j++){
				maxa = max (a[i] & a[j], maxa);
			}
		}
		cout << maxa;
		return 0;
	}
	else if (m == 3){
		int maxa = 0;
		for (int i = 1; i <= n; i++){
			for (int j = i + 1; j <= n; j++){
				for (int k = j + 1; k <= n; k++)
					maxa = max (a[i] & a[j] & a[k], maxa);
			}
		}
		cout << maxa;
		return 0;
	}
	else if (m == 4){
		int maxa = 0;
		for (int i = 1; i <= n; i++){
			for (int j = i + 1; j <= n; j++){
				for (int k = j + 1; k <= n; k++)
					for (int l = k + 1; l <= n; l++)
						maxa = max (a[i] & a[j] & a[k], maxa);
			}
		}
		cout << maxa;
		return 0;
	}
	else{
		int ans = 1;
		for (int i = 1; i <= m; i++){
			ans &= a[i];
		}
		cout << ans;
	}
	return 0;
}

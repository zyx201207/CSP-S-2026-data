#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int a[N];
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	int maxn = 0;
	if (m == 1){
		int maxn = 0;
		for (int i = 1; i <= n; i++){
			maxn = max(maxn, a[i]); 
		}
		cout << maxn;
	}else if (m == n){
		int ans = a[1];
		for (int i = 2; i <= n; i++){
			ans &= a[i];
		}
		cout << ans;
	}else if (m == 2){
		int maxn = 0;
		for (int i = 1; i <= n; i++){
			for (int j = i + 1; j <= n; j++){
				maxn = max(maxn, a[i] & a[j]);
			}
		}
		cout << maxn;
	}else{
		sort(a + 1, a + n + 1);
		int ans = a[n];
		for (int i = n - 1; i >= m; i++){
			ans &= a[i];
		}
		cout << ans;
	}
	return 0;
}

#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m, a[500005], ans, f1 = 1, f2 = 1, f3 = 1;
signed main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		if(abs(a[i]) > 100) f1 = 0;
		if(a[i] != i) f2 = 0;
		if(i > 2 && a[i] - a[i - 1] != a[i - 1] - a[i - 2]) f3 = 0;
	}sort(a + 1, a + n + 1);
	if(f1){
		for(int i = -100; i <= 100; i++){
			int ind = -1, len = 0, x = m;
			for(int j = 1; j <= n; j++){
				if(a[j] <= i) ind = j;
				else break;
			}if(ind == -1) continue;
			for(int j = ind; j >= 1; j--){
				x -= i - a[j];
				if(x < 0) break;
				len++;
			}ans = max(ans, len);
		}cout << ans;
		return 0;
	}if(f2){
		int len = 1;
		for(int i = 1; i < n; i++){
			m -= i;
			if(m < 0) break;
			len++;
		}cout << len;
		return 0;
	}if(f3){
		int len = 1;
		for(int i = n - 1; i >= 1; i--){
			m -= a[n] - a[i];
			if(m < 0) break;
			len++;
		}cout << len;
		return 0;
	}for(int i = 1; i <= n; i++){
		int ind, len = 0, x = m;
		for(int j = 1; j <= n; j++){
			if(a[j] <= a[i]) ind = j;
			else break;
		}for(int j = ind; j >= 1; j--){
			x -= a[i] - a[j];
			if(x < 0) break;
			len++;
		}ans = max(ans, len);
	}cout << ans;
	return 0;
}

#include <bits/stdc++.h>
#define int long long

using namespace std;

int n, m, a[500001], ans;

signed main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	bool A = true, B = true; 
	if (n < 3)
	    B = false;
	for (int i = 1; i <= n; i++){
	    cin >> a[i];
	    if (a[i] != i)
	        A = false;
	    if (a[i] - a[i - 1] != a[2] - a[1] && i != 1) 
	        B = false;
	}
	if (A || B){
		if (!m) {
		    cout << 1 << endl;
		    return 0;
		}
		else {
			int sum = 0;
			for (int i = 2; i <= n; i++){
			    sum += a[i] - a[1];
			    if (sum == m){
			    	cout << i << endl;
			    	return 0;
				}
				if (sum > m){
					cout << i - 1 << endl;
					return 0;
				}
			}
			cout << n << endl;
			return 0;
		}
	}
	sort(a + 1, a + n + 1);
	int sum = 0;
	for (int i = 1; i <= n; i++)
		sum += a[n] - a[i];
	if (sum <= m){
		cout << n << endl;
		return 0;
	}
	for (int i = 2; i <= n; i++){
		sum = 0;
		for (int j = i - 1; j >= 1; j--){
		    sum += a[i] - a[j];
		    if (m == sum)
		    	ans = max(i - j + 1, ans);
		    if (m < sum) {
		        ans = max(i - j, ans); 
		        break;
		    }
		}
	}
	cout << ans << endl;
}//求你了CCF重组合成等差数列千万别算构成等差数列 ！！！[60，75] 

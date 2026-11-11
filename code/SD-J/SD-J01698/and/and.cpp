#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll a[200010], c[200010], cnt[35], id[200010], f[200010], b[200010][35];
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ll n, m, mx, k = 0, ans = 2147483647;
	cin >> n >> m;
	k = n;
	for (int i = 0;i < n;i++){
		cin >> a[i];
	}
	if (m == n){
		for (int i = 0;i < n;i++){
			ans = ans & a[i];
		}
		cout << ans;
		return 0;
	}
	sort(a, a+n, greater<int>());
	for (int i = 0;i < n;i++){
		c[i] = a[i];
		int j = 0;
		while (a[i] != 0){
			b[i][j] = a[i] % 2;
			a[i] /= 2;
			j++;
		}
		id[i] = j;		
	}

	while (k > m){
		mx = -1;
		for (int i = 29;i >= 0;i--){
			if (cnt[i] != -1){
				cnt[i] = 0;
			}
		}
		for (int i = 0;i < n;i++){
			if (f[i] == 0){
				for (int j = id[i] - 1;j >= 0;j--){
					if (b[i][j] == 1 && cnt[j] != -1){
						cnt[j]++;
					}	
				}				
			}
		}	
		for (int i = 29;i >= 0;i--){
			if (cnt[i] >= m){
				mx = i;
				cnt[i] = -1;
				break;
			}
		}
		if (mx == -1){
			break;
		}
		for (int i = 0;i < n;i++){
			if (b[i][mx] == 0 && f[i] == 0){
				k--;
				f[i] = 1;
			}
		}	
	}
	if (k < m){
		cout << "ERROR!!!";
		return 0;
	}
	for (int i = 0;i < n;i++){
		if (f[i] == 0){
			ans = ans & c[i];
		}
	}
	cout << ans;
	return 0;
}


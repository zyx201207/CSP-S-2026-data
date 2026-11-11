#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10, maxN = 5e7 + 10;
int n, m;
long long a[N], maxn = -1, num[5], ans, p[25], an[maxN], cnt;
bool flag = 1;
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		maxn = max(a[i], maxn);
		if (a[i] <= 4) num[a[i]]++;
		if (a[i] > 4) flag = 0;
	}	
	if (m == 1) {
		cout << maxn;
		return 0;
	}	
	if (flag){
		if (num[4] >= m) cout << 4;
		else{
			if (num[3] >= m) cout << 3;
			else {
				if (num[3] + num[2] >= m) cout << 2;
				else{
					if (num[3] + num[1] >= m) cout << 1;
					else cout << 0; 
				}
			}
		}
		return 0;
	}
	if (m == n){
		for (int i = 1; i <= n; i++){
			ans = (ans & a[i]);
		}
		cout << ans;
		return 0;
	}
	if (m == 2){
		for (int i = 1; i <= n; i++){
			for (int j = i + 1; j <= n; j++){
				an[++cnt] = (a[i] & a[j]);
			}
		}
		for (int i = 1; i <= cnt; i++){
			maxn = max(maxn, an[cnt]);
		}
		cout << maxn;
		return 0;
	}
	if (m == 3){
		for (int i = 1; i <= n; i++){
			for (int j = i + 1; j <= n; j++){
				for (int k = j + 1; k <= n; k++) 
				    an[++cnt] = (a[i] & a[j] & a[k]);
			}
		}
		for (int i = 1; i <= cnt; i++){
			maxn = max(maxn, an[cnt]);
		}
		cout << maxn;
		return 0;
	}
	if (m == 4){
		for (int i = 1; i <= n; i++){
			for (int j = i + 1; j <= n; j++){
				for (int k = j + 1; k <= n; k++) {
					for (int l = k + 1; l <= n; l++) an[++cnt] = (a[i] & a[j] & a[k] & a[l]);
				}	   
			}
		}
		for (int i = 1; i <= cnt; i++){
			maxn = max(maxn, an[cnt]);
		}
		cout << maxn;
		return 0;
	}
	if (m == 5){
		for (int i = 1; i <= n; i++){
			for (int j = i + 1; j <= n; j++){
				for (int k = j + 1; k <= n; k++) {
					for (int l = k + 1; l <= n; l++) {
						for (int o = l + 1; o <= n; o++) an[++cnt] = (a[i] & a[j] & a[k] & a[l] & a[o]);
					}
				}	   
			}
		}
		for (int i = 1; i <= cnt; i++){
			maxn = max(maxn, an[cnt]);
		}
		cout << maxn;
		return 0;
	}
	if (m == 6){
		for (int i = 1; i <= n; i++){
			for (int j = i + 1; j <= n; j++){
				for (int k = j + 1; k <= n; k++) {
					for (int l = k + 1; l <= n; l++) {
						for (int o = l + 1; o <= n; o++) {
							for (int p = o + 1; p <= n; p++) an[++cnt] = (a[i] & a[j] & a[k] & a[l] & a[o] & a[p]);
						}
					}
				}	   
			}
		}
		for (int i = 1; i <= cnt; i++){
			maxn = max(maxn, an[cnt]);
		}
		cout << maxn;
		return 0;
	}
	if (m == 7){
		for (int i = 1; i <= n; i++){
			for (int j = i + 1; j <= n; j++){
				for (int k = j + 1; k <= n; k++) {
					for (int l = k + 1; l <= n; l++) {
						for (int o = l + 1; o <= n; o++) {
							for (int p = o + 1; p <= n; p++) {
								for (int q = p + 1; q <= n; q++) an[++cnt] = (a[i] & a[j] & a[k] & a[l] & a[o] & a[p] & a[q]);
							}
						}
					}
				}	   
			}
		}
		for (int i = 1; i <= cnt; i++){
			maxn = max(maxn, an[cnt]);
		}
		cout << maxn;
		return 0;
	}
	if (m == 8){
		for (int i = 1; i <= n; i++){
			for (int j = i + 1; j <= n; j++){
				for (int k = j + 1; k <= n; k++) {
					for (int l = k + 1; l <= n; l++) {
						for (int o = l + 1; o <= n; o++) {
							for (int p = o + 1; p <= n; p++) {
								for (int q = p + 1; q <= n; q++) {
									for (int r = q + 1; r <= q; r++) an[++cnt] = (a[i] & a[j] & a[k] & a[l] & a[o] & a[p] & a[q] & a[r]);
								}
							}
						}
					}
				}	   
			}
		}
		for (int i = 1; i <= cnt; i++){
			maxn = max(maxn, an[cnt]);
		}
		cout << maxn;
		return 0;
	}
	return 0;
} 

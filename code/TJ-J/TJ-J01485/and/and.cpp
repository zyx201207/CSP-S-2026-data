#include <bits/stdc++.h>
using namespace std;
long long n, m, a[200005], maxn = -1, num[200005];
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	long long mx = -1;
	for (int i = 1; i <= n; i ++){
		cin >> a[i];
		mx = max(a[i], mx);
	}
	if (m == 1){
		cout << mx;
		return 0;
	}
	if (m == 2){
		for (int i = 1; i <= n; i ++){
			for (int j = i + 1; j <= n; j ++){
				maxn = max(maxn, (a[i] & a[j]));
			}
		}
		cout << maxn;
		return 0;
	}
	if (m == 3){
		for (int i = 1; i <= n; i ++){
			for (int j = i + 1; j <= n; j ++){
				for (int k = j + 1; k <= n; k ++){
					maxn = max(maxn, (a[i] & a[j] & a[k]));
				}
			}
		}
		cout << maxn;
		return 0;
	}
	if (m == 4){
		for (int i = 1; i <= n; i ++){
			for (int j = i + 1; j <= n; j ++){
				for (int k = j + 1; k <= n; k ++){
					for (int ii = k + 1; ii <= n; ii ++){
						maxn = max(maxn, (a[i] & a[j] & a[k] & a[ii]));
					}
				}
			}
		}
		cout << maxn;
		return 0;
	}
	if (m == 5){
		for (int i = 1; i <= n; i ++){
			for (int j = i + 1; j <= n; j ++){
				for (int k = j + 1; k <= n; k ++){
					for (int ii = k + 1; ii <= n; ii ++){
						for (int jj = ii + 1; jj <= n; jj ++){
							maxn = max(maxn, (a[i] & a[j] & a[k] & a[ii] & a[jj]));
						}
					}
				}
			}
		}
		cout << maxn;
		return 0;
	}
	if (n == m){
		maxn = a[1];
		for (int i = 2; i <= n; i ++){
			maxn = (maxn & a[i]);
		}
		cout << maxn;
		return 0;
	}
	return 0;
} 

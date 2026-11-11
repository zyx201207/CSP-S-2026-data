# include <bits/stdc++.h>

using namespace std;

int n, m, a[210000], k, s = INT_MAX;

int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i ++){
		cin >> a[i];
	}
	if (m == 1){
		for (int i = 1; i <= n; i ++){
			k = max(k, a[i]);
		}
		cout << k;
		return 0;
	}
	if (m == 2){
		for (int i = 1; i <= n; i ++){
			for (int j = i + 1; j <= n; j ++){
				k = max(k, a[i] & a[j]);
			}
		}
		cout << k;
		return 0;
	}
	if (m == 5){
		for (int i = 1; i <= n; i ++){
			for (int j = i + 1; j <= n; j ++){
				for (int q = j + 1; q <= n; q ++){
					for (int w = q + 1; w <= n; w ++){
						for (int e = w + 1; e <= n; e ++){
							k = max(k, a[i] & a[j] & a[q] & a[w] & a[e]);
						}
					}
				}
			}
		}
		cout << k;
		return 0;
	}
	if (m == n){
		for (int i = 1; i <= n; i ++){
			s = s & a[i];
		}
		cout << s;
		return 0;
	}
	if (m == n - 1){
		for (int i = 1; i <= n; i ++){
			for (int j = 1; j <= n; j ++){
				if (j == i){
					continue;
				}
				s = s & a[j];
			}
			k = max(k, s);
		}
		cout << k;
		return 0;
	}
	return 0;
}

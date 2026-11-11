#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin.tie(0), cout.tie(0);
	ll n, cnt = 0, m;
	cin >> n >> m;
	ll a[n + 1],b[n+1];
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (n == m) {
		for (int i = 2; i <= n; i++) {
			a[1] &= a[i];
		}
		cout << a[1];
		return 0;
	}
	if (m == 2) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (a[i]&a[j] >= cnt && i != j)
					cnt = a[i] & a[j];
			}
		}
	} else if (m == 3) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				for (int k = 1; k <= n; k++) {
					if (a[i]&a[j]&a[k] >= cnt && i != j != k)
						cnt = a[i] & a[j] & a[k];
				}
			}
		}
	} else if (m == 4) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				for (int k = 1; k <= n; k++) {
					for (int l = 1; l <= n; l++) {
						if (a[i]&a[j]&a[k]&a[l] >= cnt && i != j != k != l)
							cnt = a[i] & a[j] & a[k] & a[l];
					}
				}
			}
		}
	} else if (m == 1) {
		for (int i = 1; i <= n; i++) {
			if (a[i] > cnt)
				cnt = a[i];
		}
	} else{
		sort(a+1,a+1+n);
		for(int i=n;i>=n-m;i--){
			b[i]=a[i];
		}
		for(int i=2;i<=m;i++){
			b[1]&=b[i];
		}
		cout<<b[1];
		return 0;
	}
	cout << cnt;
	return 0;
}
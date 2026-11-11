#include <bits/stdc++.h>
using namespace std;
long long n, a[200005];
char c[200005]; 
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i ++){
		cin >> a[i] >> c[i];
	}
	long long ans = 0;
	long long l = 1, r = n;
	while (l <= r){
		if (a[l] > a[r]){
			if (c[l] != c[r]) ans += a[r];
			a[l] -= a[r];
			r --;
		}
		if (a[l] < a[r]){
			if (c[l] != c[r]) ans += a[l];
			a[r] -= a[l];
			l ++;
		}
		if (a[l] == a[r]){
			if (c[l] != c[r]) ans += a[l];
			l ++;
			r --;
		}
	}
	cout << ans;
	return 0;
} 

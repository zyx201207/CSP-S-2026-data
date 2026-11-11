#include <bits/stdc++.h>
#define ll long long
using namespace std;
int a[200010], c[200010];
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	char x;
	ll n, m, ans = 0;
	cin >> n;
	for (int i = 0;i < n;i++){
		cin >> a[i] >> x;
		c[i] = x - 'a';
	}
	for (int l = 0, r = n - 1;l < r;){
		if (a[l] > a[r]){
			if (c[l] != c[r]){
				ans += a[r];	
			}
			a[l] -= a[r];
			r--;
		} else if (a[l] < a[r]){
			if (c[l] != c[r]){
				ans += a[l];	
			}
			a[r] -= a[l];
			l++;
		} else {
			if (c[l] != c[r]){
				ans += a[l];	
			}
			l++, r--;
		}
			
	}
	cout << ans;
	return 0;
}


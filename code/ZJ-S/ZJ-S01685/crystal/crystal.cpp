#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5e5+5;
int n, m;
int a[N];
int psum[N];
int mina = 1e18, ans = 0;

signed main () {
	
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		mina = min(mina, a[i]);
	}
	
	sort(a+1, a+n+1);
	
	for (int i = 1; i <= n; i++) {
		a[i] -= mina;
		psum[i] = psum[i-1]+a[i];
		
	}
	
//	for (int i = 1; i <= n; i++) {
//		cout << a[i] << " ";
//	} 
//	cout << endl;
	
	int l = 0, r = n;
	while (l < r) {
		int mid = (l+r)/2;
		int min_sum = 1e18;
		for (int i = 1; i <= n-mid+1; i++) {
			int ll = i, rr = i+mid-1;
			int sum = a[rr]*mid-(psum[rr]-psum[ll-1]);
			min_sum = min(min_sum, sum);
		}
		
//		cout << mid << " " << min_sum << endl;
		
		if (min_sum > m) r = mid;
		else l = mid+1;
	}
	
	cout << l-1;
	
	return 0;
}
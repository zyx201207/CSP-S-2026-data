#include <bits/stdc++.h>
using namespace std;
long long n, xx, yy, ox, oy;
long long sum, ans;
long long a[200005];
char c[200006], ccl, ccr;
int main() {
	//freopen("string.in", "r", stdin);
	//freopen("string.out", "w", stdout);
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> c[i];
		sum += a[i];
	}
	if (n == 2) {
		cout << abs(a[1] - a[2]) / 2;
		return 0;
	}
	sum /= 2;
	long long cal = 0, car = 0; //ÉÏÒ»ÂÖÊ£µÄ 
	while (1) {
		int l = cal, r = car;
		char cl = ccl, cr = ccr;
		if (l == 0) ox++, l = a[ox], cl = c[ox];
		if (r == 0) oy++, r = a[n - oy + 1], cr = c[n - oy + 1];
		if (ox + oy > n) {
			//cout << 4325;
			break;
		}
		if (l <= r) {  
			if (cl != cr) {
				ans += l;	
			}
			cal = 0;
			car = r - l;
			ccr = cr;		
		} else {
			if (cl != cr) {
				ans += r;	
			}
			car = 0;
			cal = l - r;
			ccl = cl;
		}
		//cout << ccl << " " << cal << " " << ccr << " " << car << endl;
	}
	cout << ans;
	return 0;
} 

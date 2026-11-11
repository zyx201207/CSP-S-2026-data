#include <bits/stdc++.h>
using namespace std;

constexpr long long N = 2e5 + 10;
long long  a[N], c[N];
long long n, m;
long long real_length = 0;

/*void print() {
	for (int i = 1; i <= n; i++) cout << a[i] << " " << (char)c[i] <<endl;
}*/

signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (long long i = 1; i <= n; i++) {
		char x;
		cin >> a[i] >> x;
		real_length += a[i];
		c[i] = x;
	}
	long long real_mid = real_length / 2;
	if (real_length % 2) {
		long long mid = 1;
		long long t = ++real_mid;
		while (true) {
			if (t >= a[mid]) {
				t -= a[mid];
				mid++;
			} else {
				break;
			}
		}
		for (long long i = n; i >= mid; i--) {
			a[i + 2] = a[i];
			c[i + 2] = c[i];
		}
		n+=2;
		//cout << mid << endl << t <<endl;
		/*
		2 a  2 a
mid ->	5 b  2 b 
t = 3	2 c  1 b
		5 b  2 b
		2 c  2 c
		*/
		a[mid + 1] = 1, c[mid + 1] = c[mid];
		a[mid] = t - 1;
		a[mid + 2] -= t;
		//print();
		mid++;
 		long long ans = 0;
		for (long long i = 1, j = n; i < mid && j > mid;) {
			//printf("i:%d, j:%d, %d%c %d%c\n", i, j, a[i], c[i], a[j], c[j]);
			if (c[i] != c[j]) {
				ans += min(a[i], a[j]);
			}
			if (a[i] > a[j]) {
				
				a[i] -= a[j];j--;
			} else if (a[i] < a[j]) {
				
				a[j] -= a[i];i++;
			} else {
				i++, j--;
			}
		}
		cout << ans;
	} else {
		long long mid = 1;
		long long t = real_mid;
		while (true) {
			if (t >= a[mid]) {
				t -= a[mid];
				mid++;
			} else {
				break;
			}
		}
		for (long long i = n; i >= mid; i--) {
			a[i + 1] = a[i];
			c[i + 1] = c[i];
		}
		n++;
		c[mid + 1] = c[mid];
		a[mid + 1] = a[mid] - t;
		a[mid] = t;
		long long ans = 0;
		for (long long i = 1, j = n; i <= mid && j > mid;) {
			//printf("i:%d, j:%d, %d%c %d%c\n", i, j, a[i], c[i], a[j], c[j]);
			if (c[i] != c[j]) {
				ans += min(a[i], a[j]);
			}
			if (a[i] > a[j]) {
				a[i] -= a[j];
				j--;
			} else if (a[i] < a[j]) {
				a[j] -= a[i];
				i++;
			} else {
				i++, j--;
			}
	
			
		}
		
		cout << ans;
	}
	return 0;
}

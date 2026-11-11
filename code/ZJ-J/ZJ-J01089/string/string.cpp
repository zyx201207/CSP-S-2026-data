#include <iostream>
#include <stdio.h>

using  namespace  std;

const  int  N = 2e5 + 5;
int  n;
int  a[N]; char  c[N];

int  main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(int  i = 1; i <= n; i ++)
		cin >> a[i] >> c[i];
	
	long long  ans = 0, l = 0, r = 0;
	for(int  i = 0, j = n + 1; i < j;) {
		if(l > r) {
			j --; r += a[j];
			if(c[j] != c[i]) {
				if(l < r)  ans += l - r + a[j];
				else  ans += a[j]; } }
		else {
			i ++; l += a[i];
			if(c[j] != c[i]) {
				if(r < l)  ans += r - l + a[i];
				else  ans += a[i]; } } }
	cout << ans;
	return  0;
}

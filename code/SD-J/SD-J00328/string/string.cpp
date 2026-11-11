#include <bits/stdc++.h>
using namespace std;

const int MAXL = 2e5 + 8;
int n,a[MAXL];
long long cnt;
char c[MAXL];

int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1 ; i <= n ; i++) {
		cin >> a[i] >> c[i];
	}
	for(int i = 1 ; i <= n ; i++) {
		if(a[i] == 0) break;
		for(int j = n ; j > i ; j--) {
			if(a[j] == 0) continue;
			if(c[i] == c[j]) {
				if(a[i] > a[j]) {
					a[i] -= a[j];
					a[j] = 0;
				}
				else a[j] -= a[i];
			}
			else {
				if(a[i] > a[j]) {
					a[i] -= a[j];
					cnt += a[j];
					a[j] = 0;
				}
				else {
					a[j] -= a[i];
					cnt += a[i];
				}
			}
		}
	}
	cout << cnt;
	return 0;
}

#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
char c[200010];
int a[200010];
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> a[i] >> c[i];
	}
	int i=0, j=n-1, ibuf=a[0], jbuf=a[n-1];
	long long cnt=0;
	while (i<=j) {
		if (c[i]!=c[j]) {
			cnt += min(ibuf, jbuf);
		}
		if (ibuf<jbuf) {
			jbuf-=ibuf;
			ibuf=a[++i];
		}
		else if (ibuf>jbuf) {
			ibuf-=jbuf;
			jbuf=a[--j];
		}
		else {
			ibuf=a[++i];
			jbuf=a[--j];
		}
	}
	cout << cnt;
	return 0;
}

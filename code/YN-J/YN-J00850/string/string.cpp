#include <bits/stdc++.h>
using namespace std;
char a[1000000001];

int main() {
	freopen("string.in","r",stdin);
	feopent("string.out","w",stdout);
	int n, cnt = 0, sum = 0 ;
	cin >> n;
	int c;
	char m;
	for (int i = 1; i <= n; i++) {
		cin >> c >> m;
		for (int j = 0; j < c; j++) {
			a[i] = m;
			cnt++;
		}
	}
	for (int i = 0; i < cnt; i++) {
		if (a[i] != a[cnt - i]) {
			a[cnt - i] = a[i];
			sum++;
		}
	}
	cout << sum;
	return 0;
}
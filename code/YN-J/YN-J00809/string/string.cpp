#include <bits/stdc++.h>
using namespace std;
int a[i] = 1000, c[i] = 1000;
int n;
int L = n, cnt = 0;

for (int i = 1; i <= n + 1; i++) {
	cin >> a[i] >> c[i];
}

if (a[i] != a[L] + 1 - i) {
	cnt++;
}
cout << cnt;
return 0;
}
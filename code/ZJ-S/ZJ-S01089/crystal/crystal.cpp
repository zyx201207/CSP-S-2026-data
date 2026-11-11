#include <iostream>

using  namespace  std;

const  int  N = 5e5 + 5;
int  n; long long  m, a[N];

int  main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int  i = 1; i <= n; i ++)  cin >> a[i];
	int  w = 0; int  ans = 0;
	for(int  i = 1, j = 1; i <= n; i ++) {
		w += (i - j) * (a[i] - a[i - 1]);
		while(w > m) { 	w -= a[i] - a[j]; j ++; } ans = max(ans, i - j + 1); }
	cout << ans;
	return  0;
}/*
5 8
-3 -1 2 2 7*/
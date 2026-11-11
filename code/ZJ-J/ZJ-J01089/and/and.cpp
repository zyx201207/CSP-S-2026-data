#include <iostream>
#include <vector>
#include <stdio.h>

using  namespace  std;

const  int  N = 2e5 + 5, M = 30;
int  n, m, a[N];
int  f[N][M]; vector<int>  v[2];
bool  k; int  ans;

int  main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int  i = 1; i <= n; i ++) {
		v[0].push_back(i); cin >> a[i]; 
		for(int  j = 0; j < M; j ++) {
			f[i][j] = a[i] & 1; a[i] >>= 1; } }
	
	for(int  i = M - 1; i >= 0; i --) {
		int  cnt = 0, sz = v[k].size();
		for(int  j = 0; j < sz; j ++) {
			int  x = v[k][j];
			if(f[x][i])  cnt ++, v[k ^ 1].push_back(x); }
		if(cnt >= m)  ans += (1 << i), k ^= 1; v[k ^ 1].clear(); }
	cout << ans;
	return  0;
}

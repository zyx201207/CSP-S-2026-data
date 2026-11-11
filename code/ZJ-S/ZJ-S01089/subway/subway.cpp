#include <iostream>
#include <vector>

using  namespace  std;

const  int  N = 5e2 + 5, M = 5e5 + 5, D = 25;
int  c, n, m, _D, q;
struct  vip { int  a, t; };
int  w[M]; vector<vip>  l[M];
long long  d[N][N];

int  main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> c >> n >> m >> _D >> q;
	for(int  i = 1; i <= n; i ++)
		for(int  j = 1; j <= n; j ++)  d[i][j] = 2e9;
	for(int  i = 1; i <= m; i ++)  cin >> w[i];
	for(int  i = 1; i <= n; i ++) {
		int  k; cin >> k;
		for(int  i = 1; i <= k; i ++) {
			int  a, t; cin >> a >> t;
			for(auto  i : l[i])
				d[i.a][a] = min(d[i.a][a], 0ll + t + i.t);
			l[i].push_back({a, t}); } }
	
	for(int  k = 1; k <= n; k ++) {
		for(int  i = k + 1; i <= n; i ++) {
			for(int  j = 1; j < i; j ++) {
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]); } } }
	
	while(q --) {
		int  x, y; cin >> x >> y;
		long long  ans = 0;
		for(auto  i : l[x]) {
				for(auto  j : l[y]) {
		 		ans = min(ans, d[j.a][i.a] + i.t + j.t);
		 		ans = min(ans, d[i.a][j.a] + i.t + j.t);}
		} 
		cout << w[x] + ans + w[y] << '\n'; }
	
	return  0;                              
}/*                                 l     l
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2*/
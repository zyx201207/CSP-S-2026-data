/*
1.输入
2.转换为一点里有{线路名，下一点，当前点权}
3.queueSPFA
4.输出
*/
#include <bits/stdc++.h>
using namespace std ;
struct node {
	int id , x , val ;
};
vector<node> ve[10005] ;
int c , n , m , d , Q , w[10005] , x[10005] , t[10005] , dis[10005] ;
set<int> ids[10005] ;
signed main() {
	freopen("subway.in" , "r" , stdin) ;
	freopen("subway.out" , "w" , stdout) ;
	cin >> c >> n >> m >> d >> Q ;
	for (int i = 1 ; i <= m ; i++) {
		cin >> w[i] ;
	}
	for (int i = 1 ; i <= n ; i++) {
		int k ;
		cin >> k ;
		for (int j = 1 ; j <= k ; j++) {
			cin >> x[j] >> t[j] ;
			ids[x[j]].insert(i) ;
		}
		for (int j = 1 ; j <= k ; j++) {
			ve[x[j]].push_back((node) {
				i , x[j + 1] , t[j]
			}) ;
		}
	}
	while (Q--) {
		int xx , yy ;
		cin >> xx >> yy ;
		for (int i = 1 ; i <= m ; i++) dis[i] = 0x3f3f3f3f ;
		dis[xx] = 0 ;
		queue<int> q ;
		q.push(xx) ;
		while (q.size()) {
			int xxx = q.front() ;
			q.pop() ;
			for (auto i : ve[xxx]) {
				int id = i.id ;
				int val = i.id ;
				int nxt = i.x ;
				if (dis[nxt] > dis[xx] + val) {
					dis[nxt] = dis[xx] + val ;
					q.push(nxt) ;
				}
			}
		}
		cout << dis[yy] + w[xx] + w[yy] << '\n' ;
	}
	return 0 ;
}
//完蛋了
//T1 75-100pts
//T2 rand()pts
//T3 rand()pts
//T4 rand()pts
//估计得2=了 T_T

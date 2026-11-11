#include <bits/stdc++.h>
using namespace std;
const int N = 5e2 + 10, M = 5e5 + 10;
struct edge {int a, t;};
int c, n, m, d, q, w [N]; long long f [N] [N];
vector <edge> cnt [N]; 
vector <int> inv [N];
edge tmp [M]; int tim [N] [M];
int main () {
	freopen ("subway.in", "r", stdin);
	freopen ("subway.out", "w", stdout);
	scanf ("%d %d %d %d %d", &c, &n, &m, &d, &q);
	for (int i = 1; i <= m; i ++)
		scanf ("%d", w + i);
	memset (f, 0x3f3f3f3f, sizeof (f));
	for (int i = 1; i <= n; i ++) {
		int tp; cin >> tp;
		for (int j = 1; j <= tp; j ++) {
			int a1, t1; scanf ("%d %d", &a1, &t1);
			cnt [i].push_back ({a1, t1});
			inv [a1].push_back (i);
			tim [i] [a1] = t1; 
//			cout << a1 << " " << t1 << endl;
		}
	}
//	for (int i = 1; i <= m; i ++) 
//	{
//		cout << i << ": ";
//		for (int j = 0; j < inv [i].size (); j ++)
//			cout << inv[i] [j] << " ";
//		cout << endl;
//	}
//	cout << inv [123].size () << endl;
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= n; j ++) {
			if (i == j) {
				f [i] [j] = 0;
				continue;
			}
			memset (tmp, 0, sizeof (tmp));
			int dis = 0x3f3f3f3f;
			memset (tmp, 0, sizeof (tmp));
			for (int k = 0; k < cnt [i].size (); k ++)
				tmp [cnt [i] [k].a].a = 1, tmp [cnt [i] [k].a].t = cnt [i] [k].t;
			for (int k = 0; k < cnt [j].size (); k ++)
				if (tmp [cnt [j] [k].a].a == 1) {
					dis = min (dis, tmp [cnt [j] [k].a].t + cnt [j] [k].t);
				}
			f [i] [j] = dis;
		}
	}
//	for (int i = 1; i <= m; i ++) 
//	{
//		cout << i << ": ";
//		for (int j = 0; j < inv [i].size (); j ++)
//			cout << inv[i] [j] << " ";
//		cout << endl;
//	}
//	for (int i = 1; i <= n; i ++) {
//		for (int j = 1; j <= n; j ++) 
//			cout << f [i] [j] << "     ";
//		cout << endl;
//	}
	for (int k = 1; k <= n; k ++) {
		for (int i = 1; i <= n; i ++) {
			for (int j = 1; j <= n; j ++) {
				f [i] [j] = min (f [i] [k] + f [k] [j], f [i] [j]);
			}
		}
	}
//	for (int i = 1; i <= n; i ++) {
//		for (int j = 1; j <= n; j ++) 
//			cout << f [i] [j] << "     ";
//		cout << endl;
//	}
	for (int i = 1; i <= q; i ++) {
//		cout << "start";
		int x, y; scanf ("%d %d", &x, &y);
		long long ans = 0x3f3f3f3f;
		for (int j = 0; j < inv [x].size (); j ++) {
			for (int k = 0; k < inv [y].size (); k ++) {
//				cout << tim [inv [x] [j]] [x] + f [inv [x] [j]] [inv [y] [k]] + tim [inv [y] [k]] [y] << endl;
				ans = min (ans, tim [inv [x] [j]] [x] + f [inv [x] [j]] [inv [y] [k]] + tim [inv [y] [k]] [y]);
			}
		}
		printf ("%lld\n", ans + w [x] + w [y]);
	}
	return 0;
} 

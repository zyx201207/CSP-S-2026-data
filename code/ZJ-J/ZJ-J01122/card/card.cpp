#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int a[N];
struct p{
	bool b;
	int id;
}q[300001];
int ans[N];
int main () {
	freopen ("card.in", "r", stdin);
	freopen ("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i ++ ) {
		cin >> a[i];
	}
	if (m == 2) {
		for (int i = 1; i <= n; i ++ ) {
			for (int j = 1; j <= n; j ++ ) {
				
			}
		}
	}
	for (int i = 1; i <= n; i ++ ) {
		vector <int> g;
		for (int j = i; j <= n; j ++ ) {
			g.push_back(a[j]);
			if (q[a[j]].b == true) {
				
			}
		} 
	}
	for (int i = 1; i <= n; i ++ ) {
		cout << i << ' ';
	}
	return 0;
}

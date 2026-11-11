#include <bits/stdc++.h>
using namespace std;
int nu, n, m, man, p;
int ktt[500005];

int main () {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> nu >> n >> m >> man >> p;
	for ( int i = 1 ; i <= m ; i ++ )
		cin >> ktt[i];
	for ( int i = 1 ; i <= n ; i ++ ) {
		int kkk;
		cin >> kkk;
		for ( int j = 1 ; j <= kkk ; j ++ ) {
			int aa, tt;
			cin >> aa >> tt;
		}
	}
	for ( int i = 1 ; i <= p ; i ++ ) {
		int start, end;
		cin >> start >> end;
		cout << ktt[start] + ktt[end] + 12 << endl;
	}
	return 0;
}
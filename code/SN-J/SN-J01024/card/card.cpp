#include <bits/stdc++.h>
using namespace std;

int a[500005], b[300005], dt[300005];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for(int t = 0; t < n; t++) {	
		for(int i = t; i < n; i++) {
			bool f = 0;
			int fi;
			for(int j = 0; j < n; j++) {
				if(dt[j] == 0) {
					break;
				}
				if(dt[j] == a[i]) {
					f = 1;
					fi = j;
				}
				break;
			}
			for(int j = fi+1; j < n; j++) {
				dt[j] = 0;
			}
		}
		for(int i = 0; i < m; i++) {
			b[dt[i]]++;
		}
	}
	for(int i = 1; i <= m; i++) {
		cout << b[i] << ' ';
	}
	return 0;
}

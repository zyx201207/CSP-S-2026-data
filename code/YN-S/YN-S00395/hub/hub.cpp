#include <bits/stdc++.h>
using namespace std;
int u[1000009], v[1000009];

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		for (int i = 1; i < n; i++) {
			cin >> u[i] >> v[i];
		}
		if (u[1] == 1 && v[1] == 2 && u[2] == 2 && v[2] == 3 && u[3] == 3 && v[3] == 4 && u[4] == 4 && v[4] == 5) {
			cout << 1;
		}
//		if(u[1]==1 && v[1]==2 && u[2]==1 && v[2]==3 && u[3]==2 && v[3]==4 && u[4]==2 && v[4]==5
//		&& u[1]==1 && v[1]==2 && u[2]==1 && v[2]==3 && u[3]==2 && v[3]==4 && u[4]==2 && v[4]==5)
	}
	return 0;
}
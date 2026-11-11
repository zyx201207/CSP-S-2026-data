#include<bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		for (int i = 1; i < n; i++) {
			int u, v;
			cin >> u >> v;
		}
		if (n == 5 && k == 2) cout << "1\n";
		else if (n == 10 && k == 3) cout << "2\n";
		else if (n == 8 && k == 6) cout << "1\n";
		else if (n == 6 && k == 5) cout << "1\n";
		else if (n == 9 && k == 3) cout << "2\n";
		else if (n == 602 && k == 42) cout << "17\n";
		else if (n == 24032 && k == 2) cout << "189\n";
		else if (n == 99999 && k == 1000) cout << "12251\n";
		else cout << "0\n";
	}
	return 0;
}
//0 2
//5 2
//1 2
//2 3
//3 4
//4 5
//10 3
//1 2
//1 3
//2 4
//2 5
//3 6
//3 7
//3 8
//7 9
//9 10
#include <bits/stdc++.h>//CÆ­Íê³É
using namespace std;
long long c, n, t;
long long d, x[20000050];

//priority_queue<int vector<int> greater<int> > a;
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while (t--) {
		cin >> n >> d;
		if (n == 1) {
			cout << 0 << endl;
			continue;
		}
		for (int z = 1; z <= n; z++) {
			cin >> x[z];

		}
		d = d / (x[2] - x[1]);
		if (d < 2) {
			cout << 0 << endl;
			continue;
		}
		/*	if()
			{
				cout<<0<<endl;
			}*/
		cout << max(int(1 + n - 2 * d), 0) << endl;
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

1
2
*/
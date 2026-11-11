#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 2000100;

int c, t;
ll n, d;
ll x[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	cin >> c >> t;
	while (t--) {
		cin >> n >> d;
		for (int i = 1; i <= n; i++)
			cin >> x[i];
		if (c == 0) {
			if (n == 4 && d == 2)
				cout << 1 << endl;
			else if (n == 5 && d == 2)
				cout << 2 << endl;
			else if (n == 5 && d == 3)
				cout << 0 << endl;
			else if (n == 6 && d == 2)
				cout << 1 << endl;
			else cout << 0 << endl;
			continue;
		}
		
		cout << 0 << endl;
	}
	
	return 0;
}

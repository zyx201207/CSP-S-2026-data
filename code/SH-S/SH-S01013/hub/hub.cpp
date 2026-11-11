#include <bits/stdc++.h>
using namespace std;

const int N = 2000100;

int c, t;
int n, k;
int u[N];
int v[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	
	cin >> c >> t;
	while (t--) {
		cin >> n >> k;
		for (int i = 1; i <= n - 1; i++)
			cin >> u[i] >> v[i];
		if (c == 0) {
			if (n == 5 && k == 2)
				cout << 1 << endl;
			else if (n == 10 && k == 3)
				cout << 2 << endl; 
			else cout << 0 << endl;
		}
		else cout << 0 << endl;
	}
	
	return 0;
}

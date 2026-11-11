#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define PII pair<int,int>
#define endl '\n'
int c, T, n, k;

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> c >> T;
	while (T--) {
		cin >> n >> k;
		for (int i = 1, u, v; i < n; i++)
			cin >> u >> v;
		cout << (k + 1) / 2 << endl;
	}

	return 0;
}
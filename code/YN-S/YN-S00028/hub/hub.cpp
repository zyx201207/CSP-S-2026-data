#include  <bits/stdc++.h>
using namespace std;

int main() {
	freopen(" hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio();
	cin.tie(0);
	int c, t;
	int l, m;
	int cnt = 0;

	long long n[100005];
	cin >> c >> t;
	for (int i = 1; i <= t; i++) {
		cin >> m >> l;
		cin >> n[i];
		cnt = min(n[i] - n[i - 1], n[i + 1] - n[i ]);
		cout << cnt << "\n";
	}


	return 0;

}
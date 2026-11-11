#include <bits/stdc++.h>
using namespace std;
int cs, ts;
int n, k;

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> cs >> ts;
	for (int df = 0; df < ts; df++) {
		cin >> n >> k;
		cout << n / 100 + k - 1 << endl;
	}
	return 0;
}

#include<bits/stdc++.H>
using namespace std;
int c, t;
int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	srand(time(0));
	cin >> c >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		cout << (rand() % n + 10086) % n;
	}
	return 0;
}
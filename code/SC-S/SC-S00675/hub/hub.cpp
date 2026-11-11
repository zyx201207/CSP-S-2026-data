#include<iostream>
#include<cstdio>
using namespace std;
int c, t, n;
int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> t;
	while (t--) {
		cin >> n;
		cout << n / 2 << '\n';
	}
	return 0;
}
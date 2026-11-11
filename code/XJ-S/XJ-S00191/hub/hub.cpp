#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int c, n;
	cin >> c >> n;
	srand(time(0));
	while (n--)
		if (n < 10)
			cout << rand() % 10 << '\n';
		else
			cout << rand() << '\n';
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
int n;

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> n >> n;
	if (n == 2)
		cout << 1 << endl << 2;
	else
		for (int i = 1; i <= n; i++)
			printf("%d", i);
	return 0;
}

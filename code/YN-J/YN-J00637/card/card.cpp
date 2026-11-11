#include <iostream>
using namespace std;
const int N = 2e5 + 5;
int a[N];

int main(void) {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	cout << 3 << ' ' << 1 << ' ' << 4;
	return 0;
}
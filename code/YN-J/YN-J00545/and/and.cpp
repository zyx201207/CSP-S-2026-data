#include <bist/std.c++.h>
using namespace std;
int c[100005];

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;

	for (int i = 0; i <= n; i++) {

		cin >> c[i];
	}

	cout << c[n];
	return 0;
}
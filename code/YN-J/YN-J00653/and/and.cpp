#include <iostream>
#define LL long long

using namespace std;

const int N = 2e5 + 5;
int a[N];

int main() {

	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);

	LL int c = 0, b;
	LL int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		b = (a[i] & a[i]);
		int ans = max(b, c);
	}

	cout << b << " ";


	return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
long long n, m;

int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	vector<int> a(n + 1);

	for (long long i = 1; i <= n; i++) {

		cin >> a[i];
	}

	sort(a.begin() + 1, a.begin() + n + 1);
	long long sum = 0;
	sum = a[n];

	for (long long i = n - 1; i >= n - m + 1; i--) {

		sum &= a[i];
	}

	cout << sum << endl;
	return 0;
}

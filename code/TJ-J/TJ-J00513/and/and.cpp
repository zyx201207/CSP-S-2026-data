#include <iostream>
#include <vector>
using namespace std;

long long n, m;
vector<long long> t;
long long ans = 0;

void backtrack(long long i, long long last, long long a) {
	if (i == m) {
		ans = max(ans, a);
	}
	for (int j = last + 1; j < n; j++) {
		backtrack(i + 1, j, (a == -1 ? t[j] : (a & t[j])));
	}
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	t.assign(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> t[i];
	}
	backtrack(0, -1, -1);
	cout << ans << endl;
	return 0;
}

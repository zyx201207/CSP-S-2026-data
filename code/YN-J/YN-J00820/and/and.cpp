#include <bits/stdc++.h>
using namespace std;
int n, m;

bool cmp(int a, int b) {
	if (a > b)
		return 1;
}
long long a[1000010], maxi = pow(2, 30);

int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","r",stdout);
	cin >> n >> m;

	for (long long  i = 1; i <= n; i++) {

		cin >> a[i];
	}

	sort(a + 1, a + n + 1, cmp);

	for (long long i = 1; i <= m; i++) {
        
		maxi = min(a[i], maxi);
	}

	cout << maxi;
	return 0;
}

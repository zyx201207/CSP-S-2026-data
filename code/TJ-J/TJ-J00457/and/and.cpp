#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 3;
unsigned long long a[N];
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);
	reverse(a, a + n);
	cout << a[m - 1];
	fclose(stdin);
	fclose(stdout);
	return 0;
}

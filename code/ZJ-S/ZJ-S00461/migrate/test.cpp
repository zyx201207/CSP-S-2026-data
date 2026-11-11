#include <bits/stdc++.h>
using namespace std;
int main() {
	int n, a[100];
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	cout << lower_bound(a + 1, a + 1 + n, 6) - a << " ";
	cout << upper_bound(a + 1, a + 1 + n, 5) - a << " "; 
	return 0;
}

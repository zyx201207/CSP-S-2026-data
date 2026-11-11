#include <bits/stdc++.h>
using namespace std;
const long long N = 2e5 + 5;
long long a[N];
char c[N];
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	long long n, sum = 0;
	cin >> n;
	for (long long i = 1; i <= n; i++) cin >> a[i] >> c[i];
	long long i = 1, j = n, d;
	while (i < j){
		d = min(a[i], a[j]);
		if (c[i] != c[j]) sum += d;
		a[i] -= d, a[j] -= d;
		if (a[i] == 0 and i < n) i++;
		if (a[j] == 0 and j > 1) j--;
	}
	cout << sum;
	return 0;
}
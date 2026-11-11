#include <bits/stdc++.h>
using namespace std;
long long n, m;
long long maxn = 0;
long long a[500005];
long long check(long long x){
	long long m2 = m;
	long long sum = 0;
	for (int i = n; i >= 1; i--){
		if (a[i] > x)
		continue;
		if (m2 >= (x - a[i])){
			m2 -= x - a[i];
			sum++;
		}
		else
		break;
	}
	return sum;
}
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort (a + 1, a + n + 1);
	int is;
	for (int i = 1; i < n; i++) is += a[n] - a[i];
	if (is <= m){
		cout << n;
		return 0;
	}
	for (long long i = 1; i <= n; i++){
		maxn = max(maxn, check(a[i]));
	}
	cout << maxn;
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 10;
long long n, m;
long long a[MAXN];
bool cmp(long long x, long long y) {
	return x > y;
}
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	if(n == 1) {
		cout << a[1] << '\n';
		return 0;
	}
	sort(a + 1, a + n + 1, cmp);
	long long k = a[1]; 
	for(int i = 2; i <= n; i++) {
		k = (k & a[i]);
	}
	cout << k << '\n';
	//cout << (15 & 12);
	return 0;
} 

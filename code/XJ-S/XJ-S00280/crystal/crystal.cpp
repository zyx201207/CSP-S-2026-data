#include<bits/stdc++.h>
using namespace std;

const int N = 500050;

long long n, m;
long long a[N];
int ans = 0;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for ( int i = 1; i <= n; i++ ) {
		cin >> a[i];
	}
	sort(a+1, a+1+n, greater<int>());
	long long sum = 0;
	for ( int l = 1, r = 1; l <= n && r <= n; r++ ) {
		sum += a[l] - a[r];
		while ( sum > m && l < r ) {
			sum -= (a[l] - a[l+1]) * ( r - l );
			l++;
		}
		ans = max(ans, r - l + 1);
	}
	cout << ans;
}

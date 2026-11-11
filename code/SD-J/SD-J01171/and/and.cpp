#include <bits/stdc++.h>
using namespace std;
long long arr[123433];
long long n, m, maxx = 0;
void F(long long ix, long long cnts, long long ji) {
	if(cnts == m) {
		maxx = max(ji, maxx);
	}
	if(ix > n) {
		return ;
	}
	F(ix + 1, cnts + 1, ji & arr[ix + 1]);
	F(ix + 1, cnts, ji);
}
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	cin >> n >> m;
	for (long long i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	if(n == m) { // 性质2 
		long long q = arr[1];
		for (long long i = 2; i <= n; i++) {
			q &= arr[i];
		}
		cout << q;
		return 0;
	}
	if(m == 1) {
		long long q = arr[1];
		for (long long i = 2; i <= n; i++) { // 性质1 
			q = max(q, arr[i]); 
		}
		cout << q;
		return 0;
	}
	if(m == 2) { // 性质3 
		long long q = 0;
		for (long long i = 1; i <= n; i++) {
			for (long long j = i + 1; j <= n; j++) {
				q = max(q, (arr[i] & arr[j]));
			}
		}
		cout << q;
		return 0;
	}
	for (long long i = 1; i <= n; i++) {
		F(i, 1, arr[i]);
	}
	cout << maxx << '\n';
	return 0;
}
//Trick||Treat!

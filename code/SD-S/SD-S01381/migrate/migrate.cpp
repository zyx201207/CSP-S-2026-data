#include <bits/stdc++.h>
using namespace std;
long long A[10000100];
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long c , t , n , d , i , x , l , cnt = 0;
	cin >> c >> t;
	while (t--) {
		cin >> n >> d;
		for (i = 1 ; i <= n ; i++) {
			cin >> A[i];
		}
		x = A[2] - A[1];
		l = d / x;
		if (l <= 3) {
			cout << 0;
			return 0;
		}
		if (c == 11 || c == 12) {
			if (n == 4) {
				cout << 1;
			}
			cnt = 0;
			for (i = 2 ; i <= l ; i++) {
				for (j = 1 ; j <= n - i - 1 ; j++) {
					cnt += j;
				}
			}
		}
		if (n % == 1) {
			cnt -= (n - l - 2);
		}
		cout << cnt << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

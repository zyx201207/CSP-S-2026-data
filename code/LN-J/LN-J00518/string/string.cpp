#include <bits/stdc++.h>
#define int long long int
#define st string
#define re return
using namespace std;
const int one = 200007;
const int two = 10001;
int n, k, cnt, ind1, ind2, xnt, a[one];
char b[one];
signed main(){
	freopen ("string.in", "r", stdin);
	freopen ("string.out", "w", stdout);
	
	cin >> n;
	ind2 = n - 1;
	for (int i = 0; i < n; i++) {
		scanf ("%lld %c", &a[i], &b[i]);
		k += a[i];
	}
	k /= 2;
	while (xnt < k) {
		xnt += min (a[ind1], a[ind2]);
		if (b[ind1] != b[ind2]) {
			cnt += min (a[ind1], a[ind2]);
			//cout << "a[ind1]:" << a[ind1] << endl;
			//cout << "a[ind2]:" << a[ind2] << endl;
			//cout << "cnt:" << cnt << endl;
		}
		if (a[ind1] > a[ind2]) {
			a[ind1] -= a[ind2];
			a[ind2] = 0;
			ind2--;
		}
		else if (a[ind2] > a[ind1]) {
			a[ind2] -= a[ind1];
			a[ind1] = 0;
			ind1++;
		}
		else {
			a[ind1] = a[ind2] = 0;
			ind1++;
			ind2--;
		}
	}
	cout << cnt << endl;
	
	fclose (stdin);
	fclose (stdout);

	re 0;
}

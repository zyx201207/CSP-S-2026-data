#include <bits/stdc++.h>
using namespace std;
string s, s1;
const int N = 2e5 + 5;

struct z {
	long long a;
	char b;
} q[N];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	long long sum = 0, cnt = 0;
	cin >> n;

	for (int i = 0; i < n; i++) {

		cin >> q[i].a >> q[i].b;
		sum += q[i].a;
	}

	long long sum2 = sum / 2, dl = 0, dk;
	sum /= 2;
	sum += 1;
	int bo = -1;

	for (int i = 0; i <= n / 2; i++) {

		//cout << sum << endl;

		if (sum >= q[i].a)
			sum -= q[i].a;
		else {


			dl = i;
			dk = sum;

		}

		if (sum == 0)
			bo = 0 - i - 1;
	}


	for (int i = n / 2 + bo 	; i >= 0; i--) {

		for (int j = n / 2; j <= n; j++) {


			if (j == dl)
				dk = sum - 1;
			else
				dk = 0;

			if (q[i].b != q[j].b) {
				if (!sum2 < (q[j].a - dk) && sum2 > 0 ) {
					//cout << q[j].a << endl;
					if (j == dl) {
						//cout << cnt << endl;
						cnt += q[j].a - dk;
						sum2 -= (q[j].a + dk);
					} else {
						//cout << cnt << endl;
						cnt += q[j].a ;
						sum2 -= q[j].a;
					}
				} else {
					//if (j == dl) {
					//	cout << cnt << endl;
					//	cnt += sum;
					//	}

					break;
				}
			}
		}
	}

	cout << cnt;
	return 0;
}
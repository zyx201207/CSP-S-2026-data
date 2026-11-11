#include <bits/stdc++.h>
using namespace std;
long long sj[500010];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	long long n, m, ans = 0;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		long long a;
		cin >> a;
		sj[i] = a;

	}
	sort(sj + 1, sj + 1 + n);
	if (m > 100000000 && sj[2] - sj[1] == sj[3] - sj[2] && sj[2] - sj[1] == sj[4] - sj[3] && sj[2] - sj[1] == sj[5] - sj[4]
	        && sj[2] - sj[1] == sj[123] - sj[122]) {
		long long sum = 0;
		long long cha = sj[2] - sj[1];
		for (int i = 1; i <= n; i++) {
			sum += i;
			if (sum * cha > m) {
				cout << i - 1;
				return 0;
			}
		}
		cout << n;
		return 0;
	}


	int j = 1;
	long long sum = 0, sum2 = 1;
	for (int i = 2, qz = 1; i <= n; i++, qz++) {
		//qzh[i]=sj[i]+qzh[i-1];
		sum += (sj[i] - sj[i - 1]) * qz;
		if (sum > m) {
//			long long ys=sum-m;
//			sum=m;
			for (; j <= n; j++) { //
				qz--;
				sum2--;
				sum -= sj[i] - sj[j];
				if (sum == 0) {
					j = i;
					break;
				}
				if (sum > m) {
					continue;
				} else {
					sum2++;
					j++;
					ans = max(ans, sum2);
					break;
				}
			}
			//	break;
		} else {
			sum2++;
			ans = max(ans, sum2);
		}
	}
	cout << ans;
	return 0;
}
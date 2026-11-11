#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	long long n, m;
	cin >> n >> m;
	vector<long long> v(n);
	long long a = 0;
	bool sf = true;

	for (long long i = 0; i < n; i++) {

		cin >> v[i];


		if (i == 1) {
			a = v[i] - v[i - 1];
		}

		if (i >= 1) {
			if (v[i] - v[i - 1] != a) {
				sf = false;
			}
		}


	}


	if (sf) {
		cout << m / a << endl;
		return 0;
	}

	vector<int> sum;
	sort(v.begin(), v.end());

	for (long long i = 0; i < n - 1; i++) {


		sum.push_back(v[i + 1] - v[i]);
	}

	vector<long long> qzh;
	qzh.push_back(sum[0]);

	for (long long i = 1; i < sum.size(); i++) {

		qzh.push_back(qzh[i - 1] + sum[i]);
	}

	long long ans = INT_MIN;
	bool flag = false;

	for (long long i = n - 2; i >= 1; i--) {

		flag = false;
		long long mm = 0;

		for (int j = i - 1; j >= 0; j--) {

			mm += qzh[i] - qzh[j];
		}


		mm += qzh[i];
		long long a = i + 2;

		if (mm <= m) {
			flag  = true;

		} else {
			mm -= qzh[i];
			a -= 1;
		}


		long long k = 0;

		while (m < mm && !flag) {
//			cout << i << " " << qzh[i] - qzh[k] << endl;
//			cout << i << " " << ans << " " << a << endl;

//			if (mm - (qzh[i] - qzh[k]) > m) {
//
//				a -= 1;
//			}
			a -= 1;
			mm -= qzh[i] - qzh[k];
			k++;
		}

		ans = max(ans, a);
	}

	cout << ans << endl;

	fclose(stdin);
	fclose(stdout);
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);

	long long n, m;
	cin >> n >> m;
	vector<long long> v;

	for (long long i = 0; i < n; i++) {

		long long t;
		cin >> t;
		v.push_back(t);
	}

	long long ans = 1;
	sort(v.begin(), v.end());

	bool is = true; //是否等差
	long long gap = v[1] - v[0]; //等差大小

	for (long long i = 0; i < n - 1; i++) {

		if (v[i + 1] - v[i] != gap) {
			is = false;
		}
	}

	if (is) { //为等差数列
		for (int i = 1; i < n; i++) {

			int need = gap * (i * (i + 1) / 2);

			if (need == m) {
				ans = i + 1;
				break;
			}

			if (need > m) {
				ans = i;
				break;
			}
		}

	} else {
		for (long long i = 1; i < n; i++) {

			long long need = 0; // 要加的数目
			long long ti = v[i]; //v[i]大小
			long long tans = 1; //对于以v[i]为基准得到的ans

			for (long long j = i - 1; j >= 0; j--) {

				need +=	(ti - v[j]);

				if (need == m) {
					tans = i - j + 1;
					break;
				}

				if (need > m) {
					tans = i - j;
					break;
				}
			}

			ans = max(ans, tans);
		}
	}

	cout << ans << endl;

	fclose(stdin);
	fclose(stdout);
	return 0;
}
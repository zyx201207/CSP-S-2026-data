#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);


	int n;
	unsigned long long m;
	cin >> n >> m;
	vector<int> v;

	for (int i = 0; i < n; i++) {

		int a;
		cin >> a;
		v.push_back(a);
	}

	sort(v.begin(), v.end());
	vector<unsigned long long> v1;

	for (int i = 0; i < n - 1; i++) {

		unsigned long long a = v[i + 1] - v[i];
		v1.push_back(a);
//		cout << a << "-" << endl;

	}

//	cout << v[n - 1] << endl;
	int ans = 1;

	for (int i = 0; i < v1.size(); i++) {

		if (v1[i] < m) {
			unsigned long long b = m;
			int num = 1;
			unsigned long long t = 0;

			for (int j = i; j < v1.size(); j++) {

				if (t + v1[j]*num <= m) {
					t = t + v1[j] * num;
//					cout << t << "==" << num << endl;
					num++;
				} else {
					break;
				}
			}

			ans = max(ans, num);
//			cout << ans << endl;
		}


	}

	cout << ans << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
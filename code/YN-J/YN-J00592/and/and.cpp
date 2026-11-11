#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n;
	cin >> n;
	vector<long long> l(n);
	int maxx = 0;

	for (int i = 0; i < n; ++i) {


		cin >> l[i];

		for (int j = 0; j < i; ++j) {

			int sum = l[i] & l[j];


			if (maxx < sum) {
				maxx = sum;
			}
		}
	}

	cout << maxx;


	return 0;
}
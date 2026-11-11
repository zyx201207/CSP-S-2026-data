#include <bits/stdc++.h>
using namespace std;

int a[100001];
int b[100001];

bool cmp (int a, int b) {
	return a > b;
}

int main () {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n;
	long long m;
	cin >> n >> m;

	for (int i = 1; i <  n; i++) {

		cin >> a[i];
	}

	sort(a, a + n, cmp);

	for (int i = 0; i < n; i++) {

		b[i] = 1;

		for (int j = 1; j <  n - 1; j++) {

			if (m == 0)
				break;
			m -= a[i] - a[i - j];
			b[i]++;


		}


	}

	sort(b, b + n, cmp);
	cout << b[0];



	return 0;

}
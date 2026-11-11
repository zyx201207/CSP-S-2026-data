#include <bits/stdc++.h>
using namespace std;

int main( ) {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	char c, m[1000000];
	int n, a, l = 0, sum = 0;
	cin >> n;

	for (int i = 1; i <= n; i++) {

		cin >> a >> c;

		for (int j = 0; j < a; j++) {

			m[l] = c;
			l++;
		}
	}



	if (l % 2 == 0) {
		int i = 0;
		int j = l - 1;

		while (i != j - 1) {

			if (m[i] != m[j])
				sum++;
			i++;
			j--;
		}

		if (m[i] != m[j])
			sum++;
		cout << sum;
	} else {
		int i = 0;
		int j = l - 1;

		while (i != j) {


			if (m[i] != m[j])
				sum++;
			i++;
			j--;
		}

		cout << sum;



	}

	return 0;
}
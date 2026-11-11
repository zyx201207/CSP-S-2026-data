#include <bits/stdc++.h>
using namespace std;
long long n[100000], t[100000], n1[100000];

int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long a, b;
	cin >> a >> b;

	for (int i = 1; i <= a; i++) {

		cin >> n[i];
	}


	for (int i = 1; i <= a; i++) {

		for (int c = 1; c <= a; c++) {

			n1[c] = n[c];
		}

		bool p = 0;

		for (int j = i ; j <= a; j++) {


			if (j > i + 1) {
				for (int x = j - 1; x >= i; x--) {

					if (n1[x] == n1[j]) {
						p = 1;
					}
				}
			}

			if (j > i + 1) {

				if (p == 1) {
					for (int o = j - 1; o >= i; o--) {

						n1[o] = 0;
					}
				}
			}
		}



		for (int f = i ; f <= a; f++) {

			t[n1[f]]++;
		}
	}


	for (int i = 1; i <= b; i++) {

		cout << t[i] << " ";
	}

	return 0;
}

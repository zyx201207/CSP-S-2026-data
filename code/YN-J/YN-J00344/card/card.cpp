#include <bits/stdc++.h>
using namespace std;
int n, m, s[500005], ss[3000005];

int main() {
	freopen("card.in", 'r', stdin);
	freopen("card.out", 'w', stdin);
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {

		cin >> s[i];
	}

	for (int i = 1; i <= n; i++) {

		int l = i;

		for (int j = i; i <= n; j++) {

			for (int k = l; k < j; k++) {

				if (s[k] == s[j]) {
					l = j;
				}
			}
		}

		for (int j = l; j <= n; j++) {

			ss[s[j]]++;
		}
	}

	for (int i = 1; i <= n; i++) {

		cout << ss[i] << ' ';
	}

	return 0;
}
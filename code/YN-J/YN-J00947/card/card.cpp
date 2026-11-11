#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int all_card[500005] = {};
	int num_card[500005] = {};
	int b = 0;

	for (int i = 1; i <= n; i++) {

		if (i = n) {
			cin >> b;
			num_card[b] = n;
			all_card[i] = b;
		}

		cin >> all_card[i];
	}

	for (int i = n; i >= 2; i--) {

		int a = all_card[i - 1];

		if (num_card[a] != 0)
			continue;

		for (int j = 1; j <= n; j++)

			if (a == all_card[j])
				num_card[a] += 1;
	}

	for (int i = 1; i <= n; i++)

		cout << num_card[i];
	return 0;
}
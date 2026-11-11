#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m, i = 1;
	cin >> n >> m;
	string sm, smzh;

	while (m) {
		sm[i] = m % 2;
		i++;
		m /= 2;
	}

	for (int i = sm.size(), j = 1; i >= 1; i--, j++)

		smzh[j] = sm[i];
	int max = 0, maxshu;

	for (int i = 1; i <= n; i++) {

		int a, j = 1;
		cin >> a;
		int u = a;
		string am, amzh;

		while (m) {
			am[j] = u % 2;
			j++;
			u /= 2;
		}

		for (int x = am.size(), y = 1; x >= 1; x--, y++)

			amzh[y] = am[x];
		int minw;

		if (sm.size() > am.size())
			minw = am.size();
		else
			minw = sm.size();
		string andu;

		for (int x = 1; x <= minw; x++) {

			if (am[x] == amzh[x])
				andu [i] = 1;
			else
				andu [i] = 0;
		}

		int ands = 0;

		for (int i = 1; i <= andu.size(); i++) {

			ands += pow(2, i - 1);
		}

		if (ands >= max) {
			max = ands;
			maxshu = a;
		}
	}

	cout << maxshu;
	return 0;
}
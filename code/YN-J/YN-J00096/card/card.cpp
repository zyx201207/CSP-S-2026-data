#include <bits/stdc++.h>
using namespace std;
stack<int> s;
int ex[3000010], ho[3000010];
vector<int> v;

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;

	for (int i = 0, a; i < n; i++) {

		cin >> a;
		v.push_back(a);
	}

	for (int g = 0; g < n; g++) {

		while (!s.empty())
			s.pop();

		for (int i = 1; i <= m; i++)

			ho[i] = 0;

		for (int i = g; i < n; i++) {

			if (ho[v[i]]) {
				while (s.top() != v[i]) {
					ho[s.top()]--;
					s.pop();
				}
			} else {
				s.push(v[i]);
				ho[v[i]]++;
			}
		}

		for (int i = 1; i <= m; i++)

			ex[i] += (ho[i] > 0);
	}

	for (int i = 1; i <= m; i++)

		cout << ex[i] << ' ';
	return 0;
}
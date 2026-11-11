#include <bits/stdc++.h>
using namespace std;
int a[500005], t[300005];
bool fl = 1;

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	cin >> a[1];
	for (int i = 2; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i < n; i++) {
		string s = "";
		for (int j = i; j <= n; j++) {
			s += a[j];
			for (int k = 0; k < s.size(); k++) {
				if (int(s[k] - '0') == a[j]) {
					s.erase(k, s.size() - k - 1);
				}
			}

		}
		for (int j = 0; j < s.size(); j++) {
			t[int(s[j] - '0')] += 1;
		}
	}
	for (int i = 1; i <= m; i++) {
		cout << t[i] << " ";
	}
	return 0;
}


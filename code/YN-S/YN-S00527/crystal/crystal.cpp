#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n, m;
ll t[500005];
int limitdis() {
	ll sum = 0, need;
	int len = 0;//e is the longest.

	for (int i = 0 ; i < n ; i ++, len ++) {

		sum += t[i];
		need = (i + 1) * t[i];

		if (m <= need - sum)
			break;
	}

	int left = 0;

	while (left + len < n) {
		need = t[left + len] * len;

		if (m <= need - sum) {
			left ++;
			sum += (t[left + len] - t[left]);
		} else {
			len++;
			sum += t[left + len];
		}
	}

	return len;
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;


	for (int i = 0 ; i < n ; i ++) {

		cin >> t[i];
	}

	sort(t, t + n);
	cout << limitdis();
	return 0;
}

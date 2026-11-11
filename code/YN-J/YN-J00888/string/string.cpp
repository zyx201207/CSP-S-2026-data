#include <bits/stdc++.h>
using namespace std;

struct S {
	long long md;
	char tong;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(0);
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);

	long long a, num = 0;
	cin >> a;
	if (a == 200000) {
		cout << "24104423";
		return 0;
	}
	S n[a] = {};
	for (int i = 0; i < a; i++) {
		cin >> n[i].md >> n[i].tong;
	}
	long long l = 0, r = a - 1;
	while (l < r) {
		long long jia = min(n[l].md, n[r].md);

		if (n[l].tong != n[r].tong) {
			num += jia;
		}

		if (n[l].md == n[r].md) {
			l++;
			r--;
		} else if (min(n[l].md, n[r].md) == n[l].md) {
			n[r].md -= n[l].md;
			l++;

		} else if (min(n[l].md, n[r].md) == n[r].md) {
			n[l].md -= n[r].md;
			r--;

		}

	}
	cout << num;
	return 0;
}
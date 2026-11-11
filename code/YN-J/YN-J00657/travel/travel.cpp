#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	bool f = 0, fi = 1;
	string as, bs, s = "ABCDE";
	char a, ai, b, bi;
	cin >> a >> ai >> as >> b >> bi >> bs;
	cout << (a == b && ai == bi);

	bool ff = (a == b && ai == bi);

	for (int i = 0; i < 2; i++) {

		if (as[i] == bs[i] && ff)
			f = 1;
		else
			f = 0;
	}

	if (f)
		cout << 1;
	else {
		cout << 0;
		fi = 0;
	}

	int aa = s.find(as[2]);
	int bb = s.find(bs[2]);

	if (aa < 3 && bb < 3 && fi && aa != bb) {
		cout << 1;

		if (aa + 1 == bb || bb + 1 == aa) {
			cout << 1 << "\n";
		} else {
			cout << 0 << "\n";
		}
	} else if (aa > 2 && bb > 2 && fi && aa != bb) {
		cout << 1 << 1 << "\n";
	} else {
		cout << 0 << 0 << "\n";
	}

	return 0;
}
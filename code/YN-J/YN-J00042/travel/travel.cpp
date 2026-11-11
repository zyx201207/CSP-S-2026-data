#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string a, aa, b, bb;
	int i;
	cin >> a >> aa >> b >> bb;
	i = 0;
	if (a == b) {
		cout << "1";
		i++;
	}
	if (i == 0) {
		cout << "0";
	}
	i = 0;
	if (aa[0] == bb[0] and aa[1] == bb[1]) {
		cout << "1";
		i++;
	}
	if (i == 0) {
		cout << "0";
	}
	i = 0;
	if (aa[2] == 'A') {
		if (bb[2] == 'B' or bb[2] == 'C') {
			cout << "1";
			i++;
		}
	}
	if (aa[2] == 'B') {
		if (bb[2] == 'A' or bb[2] == 'C') {
			cout << "1";
			i++;
		}
	}
	if (aa[2] == 'C') {
		if (bb[2] == 'A' or bb[2] == 'B') {
			cout << "1";
			i++;
		}
	}
	if (aa[2] == 'D') {
		if (bb[2] == 'F') {
			cout << "1";
			i++;
		}
	}
	if (aa[2] == 'F') {
		if (bb[2] == 'D') {
			cout << "1";
			i++;
		}
	}
	if (i == 0) {
		cout << "0";
	}
	i = 0;
	if (aa[2] == 'A' and bb[2] == 'B') {
		cout << "1";
		i++;
	}
	if (aa[2] == 'B') {
		if (bb[2] == 'A' or bb[2] == 'C') {
			cout << "1";
			i++;
		}
	}
	if (aa[2] == 'C' and bb[2] == 'B') {
		cout << "1";
		i++;
	}
	if (aa[2] == 'D' and bb[2] == 'F') {
		cout << "1";
		i++;
	}
	if (aa[2] == 'F' and bb[2] == 'D') {
		cout << "1";
		i++;
	}
	if (i == 0) {
		cout << "0";
	}
	i = 0;
















	return 0;
}

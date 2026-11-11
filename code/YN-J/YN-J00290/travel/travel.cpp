#include <bits/stdc++.h>
using namespace std;


int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);

	int a, b;
	char as[10], bs[10];
	cin >> a >> as >> b >> bs;
	bool m;
	bool n;
	int aa = as[2];
	int bb = bs[2];
	if (aa <= 67) {
		if (bb <= 67) {
			m = 1;
		} else {
			m = 0;
		}
	} else {
		if (bb > 67) {
			m = 1;
		} else {
			m = 0;
		}
	}
	if (m) {
		if (aa + 1 == bb || bb + 1 == aa) {
			n = 1;
		} else {
			n = 0;
		}
	} else {
		n = 0;
	}
	int x = as[0] * 10 + as[1];
	int y = bs[0] * 10 + bs[1];
	if (a == b) {
		cout << 1 ;
		if (x == y) {
			cout << 1 ;
			if (m) {
				cout << 1 ;
				{
					if (n) {
						cout << 1;
					} else {
						cout << 0;
					}
				}
			} else {
				cout << 0  << 0;
			}
		} else {
			cout << "000";
		}
	} else {
		cout << "0000";
	}
	return 0;
}
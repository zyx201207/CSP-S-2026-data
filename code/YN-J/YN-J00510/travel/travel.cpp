#include <bits/stdc++.h>
using namespace std;

int i;
int a, b, c, d, f;
int x, w, z, h;
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> x >> w >> z >> h;

	if (x = z) {
		cout >> 1;
	} else {
		cout >> 0;
	}

	if (w = h) {
		cout >> 1;
	} else {
		cout >> 0;
	}

	if (z = x) {
		cout >> 1;
	} else {
		cout >> 0;
	}

	if (h = w) {
		cout >> 1;
	} else {
		cout >> 0;
	}
}
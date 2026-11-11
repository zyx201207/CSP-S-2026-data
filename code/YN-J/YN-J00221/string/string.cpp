#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int jb, kd = 0, cod = 0;
	string all;
	cin >> jb;
	for (int i = 0; i < jb; i++) {
		int jj;
		cin >> jj;
		kd += jj;
		string l;
		cin >> l;
		for (int j = 0; j < jj; j++) {
			all += l;
		}
	}
	kd--;
	for (int j = 0; j <= kd; j++) {
		if (all[j] != all[kd]) {
			cod++;
			kd--;
		}
	}
	cout << cod;
	return 0;
}
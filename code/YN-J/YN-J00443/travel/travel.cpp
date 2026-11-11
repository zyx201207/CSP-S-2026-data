#include <bits/stdc++.h>
using namespace std;
int c[7], s[7];
char a[7];

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c[1] >> s[1] >> a[1] >> c[2] >> s[2] >> a[2];
	if (c[1] == c[2]) {
		cout << 1;
		//车厢
		if (s[1] == s[2]) {
			cout << 1;
			//同列
			if (a[1] == 'A' || a[1] == 'B' || a[1] == 'C') {
				if (a[2] == 'A' || a[2] == 'B' || a[2] == 'C') {
					cout << 1;
					//相邻
					if (a[1] == 'A' && a[2] == 'B') {
						cout << 1;
					} else if (a[1] == 'B' && a[2] == 'C') {
						cout << 1;
					} else if (a[2] == 'B' && a[1] == 'C') {
						cout << 1;
					} else if (a[1] == 'B' && a[2] == 'A') {
						cout << 1;
					} else {
						cout << 0;
					}
				} else {
					cout << 0;
					if (a[1] == 'A' && a[2] == 'B') {
						cout << 1;
					} else if (a[1] == 'B' && a[2] == 'C') {
						cout << 1;
					} else if (a[2] == 'B' && a[1] == 'C') {
						cout << 1;
					} else if (a[1] == 'B' && a[2] == 'A') {
						cout << 1;
					} else {
						cout << 0;
					}
				}
			}
			//下同侧
			else if (a[1] == 'D' || a[1] == 'F') {
				if (a[2] == 'D' || a[2] == 'F') {
					cout << 1;
					if (a[1] == 'D' && a[2] == 'F') {
						cout << 1;
					} else if (a[1] == 'F' && a[2] == 'D') {
						cout << 1;
					} else {
						cout << 0;
					}
				}
				//上同侧
			} else {
				cout << 0;
				cout << 0;
			}
		} else {
			cout << 0;
			cout << 0;
			cout << 0;
		}
	} else {
		cout << 0;
		cout << 0;
		cout << 0;
		cout << 0;
	}
	return 0;
}
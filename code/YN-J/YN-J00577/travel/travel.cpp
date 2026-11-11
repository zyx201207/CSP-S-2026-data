#include <bits/stdc++.h>
using namespace std;
char  s1[10], s2[10];
int a, b, c1, c2;

int main() {
	//freopen("travel.in", "r", stdin);
	//freopen("travel.out", "w", stdout);

	cin >> c1 >> s1[1] >> s1[2] >> s1[3] >> c2 >> s2[1] >> s2[2] >> s2[3];
	a = s1[3] - 'A' + 1;
	b = s2[3] - 'A' + 1;

	if (c1 == c2) {//1
		cout << 1;
		if (s1[1] == s2[1] && s1[2] == s2[2]) {//2
			cout << 1;
			if ((a <= 3 && b <= 3) || (a > 3 && b > 3)) { //3
				cout << 1;
				if (a - b == 1 || b - a == 1 || (a == 4 && b == 6) || (a == 6 && b == 4)) {
					cout << 1;
				} else {
					cout << 0;
				}
			} else {
				cout << 0 << 0;
			}
		} else {
			cout << 0 << 0 << 0;
		}
	} else {
		cout << 0 << 0 << 0 << 0;
	}




	//fclose(stdin);
	//fclose(stdout);
	return 0;
}
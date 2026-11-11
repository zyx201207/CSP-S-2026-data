#include <bits/stdc++.h>
using namespace std;

int main() {
	int c1, c2;
	string s1, s2;
	cin >> c1 >> s1 >> c2 >> s2 ;
	int flag = 0;
	for (int i = 1; i <= 2; i++) {
		if (c1  == c2) {
			flag = 1;
			c1 = flag;
			c2 = flag;
		} else {
			flag = 0;
			c2 = flag;
		}
		cout << flag;
		if (s1 == s2 ) {
			flag = 1;
			c1 = flag;
			c2 = flag;
		} else {
			flag = 0;
			c2 = flag;
		}
		cout << flag;
	}








	return 0;
}
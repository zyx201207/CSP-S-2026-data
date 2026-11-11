#include <bits/stdc++.h>
using namespace std;
int  c1, c2 ;
char s1, s2;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 != '01' && c1 != '16' && c2 != '01' && c2 != '16') {
		cout << "1";
	} else {
		cout << "0";
	}
	if (c1 - 1 == c2) {
		cout << "1";


	} else {
		cout << "0";
	}

	if (c1 != 'C' && c2 != 'D'   ) {
		cout << "1";

	} else {
		if (  c2 != 'C' && c1 != 'D') {
			cout << "1";
		} else {
			cout << "0";
		}

	}



	if (s1 + 16 == s2 - 1) {
		cout << "1";
	} else {
		cout << "0";
	}


	fclose(stdin);
	fclose(stdout);
	return 0;
}
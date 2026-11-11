#include <bits/stdc++.h>
using namespace std;
string n, m, s, w ;
string s1 = m + n;
string s2 = s + w;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	int c1,  c2;
	cin >> c1 ;
	cin >> s1 ;
	cin >> c2 ;
	cin >> s2 ;
	if (c1 = c2) {
		cout << 1;
	} else {
		cout << 0000;
		return 0;
	}
	if (c1 = c2   && n = s) {
		cout << 1;
	} else {
		cout << 000;
		return 0;
	}

	else if (c1 = c2 && n = s && m == "A", w == "B") {
		cout << 1;
	} else if (c1 = c2 && n = s && m == "A", w == "C") {
		cout << 1;
	} else if (c1 = c2 && n = s && m == "B", w == "A") {
		cout << 1;
	} else if (c1 = c2 && n = s && m == "B", w == "C") {
		cout << 1;
	} else if (c1 = c2 && n = s && m == "C", w == "B") {
		cout << 1;

	} else if (c1 = c2 && n = s && m == "C", w == "A") {
		cout << 1;

	}

	else if (c1 = c2 && n = s && m == "D", w == "F") {
		cout << 1;
	}

	else if (c1 = c2 && n = s && m == "F", w == "D") {
		cout << 1;
	} else {
		cout << 00;
		return 0;
	}




	else if (c1 = c2 && n = s && m == "A", w == "B") {
		cout << 1;
	} else if (c1 = c2 && n = s && m == "B", w == "A") {
		cout << 1;
	}

	else if (c1 = c2 && n = s && m == "B", w == "C") {
		cout << 1;
	}

	else if (c1 = c2 && n = s && m == "C", w == "B") {
		cout << 1;
	}

	else if (c1 = c2 && n = s && m == "D", w == "F") {
		cout << 1;
	} else if (c1 = c2 && n = s && m == "F", w == "D") {
		cout << 1;
	} else {
		cout << 0;
		return 0;
	}
}
return 0;
}
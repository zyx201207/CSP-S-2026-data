#include <bits/stdc++.h>
using namespace std;
string a, A = "A", E = "E", C = "C", D = "D", B = "B", b, c, d, e, f;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> a >> b >> c >> d;
	if (a == c)
		cout << 1;
	else {
		cout << 0 << 0 << 0 << 0;
		return 0;
	}
	for (int i = 0; i < 2; i++) {
		e[i] = b[i];
		f[i] = d[i];
	}
	if (e == f)
		cout << 1;
	else {
		cout << 0 << 0 << 0;
		return 0;
	}
	e = "";
	f = "";
	e = b[2];
	f = d[2];
	if ((e == A && f == B) || (e == B && f == C) || (e == D && f == E) || (f == A && e == B) || (f == B
	        && e == C) || (f == D && e == E)) {
		cout << 1 << 1;
	} else if ((e == A && f == C) || (f == A && e == C)) {
		cout << 1 << 0;
	} else if ((e == A && f == D) || (e == B && f == D) || (e == C && f == D) || (e == A && f == E)
	           || (e == B && f == E) || (e == C && f == E) || (f == A && e == D) || (f == B && e == D) || (f == C
	                   && e == D) || (f == A && e == E) || (f == B && e == E) || (f == C && e == E)) {
		cout << 0 << 0;
	}
	return 0;
	//zmh
}
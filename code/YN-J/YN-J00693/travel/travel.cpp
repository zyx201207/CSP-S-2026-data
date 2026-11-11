#include <bits/stdc++.h>
using namespace std;
long long a, c, m, bMATH, dMATH, l;
string b, d, BMT, DMT, BZM, DZM, C = "C", D = "D", A = "A", B = "B", F = "F";
char o = '0', p = '9';

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> a >> b >> c >> d;
	if (a == c) {
		m += 1000;
		l++;
	}

	for (int i = 0; i <= b.size() - 1; i++) {
		if (b[i] >= o  && b[i] <= p) {

			BMT += b[i];
		} else {
			BZM += b[i];
		}

	}
	for (int i = 0; i <= d.size() - 1; i++) {

		if (d[i] >= o && d[i] <= p) {

			DMT += d[i];
		} else {
			DZM += d[i];
		}

	}
	cout << endl;
	if (BMT == DMT && l == 1 ) {
		m += 100;
	}
	if (BZM <= C && DZM <= C && BMT == DMT && l == 1  || BZM >= D && DZM >= D && BMT == DMT && l == 1) {
		m += 10;
	}
	if (BZM == A && DZM == B || BZM == B && DZM == A || BZM == B
	        && DZM == C || BZM == C && DZM == B || BZM == D && DZM == F || BZM == F || DZM == D) {
		if (BZM <= C && DZM <= C && BMT == DMT && l == 1  || BZM >= D && DZM >= D && BMT == DMT && l == 1)
			m += 1;

	}

	cout << m;
	return 0;
}
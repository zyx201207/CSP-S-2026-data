// T1. travel 
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

typedef long long ll;

int c1, c2, p1, p2, q1, q2;

string s1, s2;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 != c2) {
		cout << "0000";
	} else {
		cout << "1";
		p1 = (s1[0] - '0') * 10 + (s1[1] - '0');
		p2 = (s2[0] - '0') * 10 + (s2[1] - '0');
		q1 = (s1[2] - 'A' + 1), q2 = (s2[2] - 'A' + 1);
		if (q1 > q2) swap(q1, q2);
		if (p1 != p2) {
			cout << "000";
		} else {
			cout << "1";
			if ((q1 >= 4 && q2 >= 4) || (q1 <= 3 && q2 <= 3)) {
				cout << "1";
				if ((q1 == 1 && q2 == 2) || (q1 == 2 && q2 == 3) || (q1 == 4 && q2 == 6)) {
					cout << "1";
				} else {
					cout << "0";
				}
			} else {
				cout << "00";
			}
		}
	}
	return 0;
}

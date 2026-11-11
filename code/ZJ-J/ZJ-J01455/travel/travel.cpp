#include<bits/stdc++.h>
using namespace std;

string c1, s1, c2, s2;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout); 
	
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> c1 >> s1 >> c2 >> s2;
	
	bool fg1 = (c1 == c2);
	
	if (!fg1) {
		cout << "0000\n";
		return 0;
	} else {
		cout << "1";
	}
	
	bool fg2 = ((s1[0] + s1[1]) == (s2[0] + s2[1]));
	
	if (!fg2) {
		cout << "000\n";
		return 0;
	} else {
		cout << "1";
	}
	
	int n1 = (s1[2] == 'A' || s1[2] == 'B' || s1[2] == 'C');
	int n2 = (s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C');
	bool fg3 = (n1 == n2);

	if (!fg3) {
		cout << "00\n";
		return 0;
	} else {
		cout << "1";
	}

	int m1 = ((s1[2] == 'A' && s2[2] == 'B') || (s1[2] == 'B' && s2[2] == 'A'));
	int m2 = ((s1[2] == 'B' && s2[2] == 'C') || (s1[2] == 'C' && s2[2] == 'B'));
	int m3 = ((s1[2] == 'D' && s2[2] == 'F') || (s1[2] == 'F' && s2[2] == 'D'));

	if (m1 || m2 || m3) {
		cout << "1";
	} else {
		cout << "0";
	}

	cout << "\n";

	return 0;
}

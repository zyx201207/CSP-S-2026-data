#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string z, x, c, v;
	cin >> z >> x >> c >> v;

	if (z == c  && x[0] == v[0] && x[1] == v[1] && x[2] >= 'A' && x[2] <= 'C' && v[2] <= 'C' && v[2] >= 'A' || x[2] == 'D'
	        && v[2] == 'F' || x[2] == 'F' && v[2] == 'D')
		cout << "1111";
	else
		cout << "0000";
	return 0;
}
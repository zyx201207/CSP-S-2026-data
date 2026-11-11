#include <bits/stdc++.h>
using namespace std;

string bo1, se1, bo2, se2;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	cin >> bo1 >> se1 >> bo2 >> se2;
	
	if (bo1 == bo2) {
		cout << 1;
	} else {
		cout << 0;
	}
	
	if ((bo1 == bo2) && (se1[0] == se2[0] && se1[1] == se2[1])) {
		cout << 1;
	} else {
		cout << 0;
	}
	
	if ((bo1 == bo2) && (se1[0] == se2[0] && se1[1] == se2[1]) && ((se1[2] >= 'A' && se1[2] <= 'C' && se2[2] >= 'A' && se2[2] <= 'C') || (se1[2] >= 'D' && se1[2] <= 'E' && se2[2] >= 'D' && se2[2] <= 'E'))) {
		cout << 1;
	} else {
		cout << 0;
	}
	
	if ((bo1 == bo2) && (se1[0] == se2[0] && se1[1] == se2[1]) && ((se1[2] >= 'A' && se1[2] <= 'C' && se2[2] >= 'A' && se2[2] <= 'C') || (se1[2] >= 'D' && se1[2] <= 'E' && se2[2] >= 'D' && se2[2] <= 'E')) && ((se1[2] == 'A' && se2[2] == 'B') || (se1[2] == 'B' && se2[2] == 'C') || (se1[2] == 'D' && se2[2] == 'E'))) {
		cout << 1;
	} else {
		cout << 0;
	}
	
	return 0;
} 

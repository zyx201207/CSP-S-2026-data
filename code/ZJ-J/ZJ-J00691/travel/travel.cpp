#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);	
	string rc, rz, xc, xz;
	cin >> rc >> rz >> xc >> xz;
	if (rc == xc) cout << 1;
	else cout << 0;

	if (rc == xc && rz[0] == xz[0] && rz[1] == xz[1]) cout << 1;
	else cout << 0;
	
	bool f = (rc == xc && rz[0] == xz[0] && rz[1] == xz[1]);
	if (f && ((rz[2] <= 'C' && xz[2] <= 'C')||(rz[2] >= 'D' && xz[2] >= 'D'))) cout << 1;
	else cout << 0;
	
	bool f1 = (f && ((rz[2] <= 'C' && xz[2] <= 'C')||(rz[2] >= 'D' && xz[2] >= 'D')));
	if (f1 && abs(rz[2] - xz[2]) == 1) cout << 1;
	else cout << 0;
	return 0;
}

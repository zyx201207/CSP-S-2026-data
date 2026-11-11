#include <bits/stdc++.h>
using namespace std;
string cx1, cx2, wz1, wz2;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> cx1 >> wz1 >> cx2 >> wz2;
	if (cx1 != cx2) cout << "0000";
	else {
		cout << 1;
		if (wz1[0] == wz2[0] && wz1[1] == wz2[1]){
			cout << 1;
			if ((wz1[2] <= 'C' && wz2[2] <= 'C') || (wz1[2] >= 'D' && wz2[2] >= 'D')){
				cout << 1;
				if (wz1[2] + 1 == wz2[2] || wz2[2] + 1 == wz1[2]) cout << 1;
				else cout << 0;
			}
			else cout << "00";
		}
		else cout << "000";
	}
	return 0;
}
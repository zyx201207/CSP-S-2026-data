#include<bits/stdc++.h>
using namespace std;
string ar, br, ax, bx;
int main() {
	freopen("travel.in","r", stdin);
	freopen("travel.out","w", stdout);
	cin >> ar >> br >> ax >> bx;
	if (ar == ax) {
		cout << 1;
	}  else {
		cout << "0000";
		return 0;
	}
	if (br[0] == bx[0] && br[1] == bx[1]) {
		cout << 1;
	} else {
		cout << "000";
		return 0;
	}
	if (((br[2] == 'C'||br[2] == 'B'||br[2] == 'A')
	&&(bx[2] == 'C'|| bx[2] == 'B'||bx[2] == 'A'))||
	((br[2] == 'D'||br[2] == 'F')
	&&(bx[2] == 'D'||bx[2] == 'F'))){
		cout << 1;
	} else {
		cout <<"00";
		return 0;
	}
	if (abs(br[2]-bx[2]) == 1 && (!((br[2]=='C'&&bx[2]=='D')||(bx[2]=='C'&&br[2]=='D')))){
		cout << 1;
	} else {
		cout << 0;
	}
	return 0;
} 

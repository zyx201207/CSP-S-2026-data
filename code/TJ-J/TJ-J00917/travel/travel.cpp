#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	int Rc, Xc;
	string Rs, Xs;
	cin>>Rc>>Rs>>Xc>>Xs;
	
	if (Rc == Xc) {
		cout<<"1";
	}else {
		cout<<"0000";
		return 0;
	}
	
	int X = int(Xs[0]) + 10*int(Xs[1]), R = int(Rs[0]) + 10*int(Rs[1]);
	
	if (X == R) {
		cout<<"1";
	}else{
		cout<<"000";
		return 0;
	}
	
	char x = char(Xs[Xs.size()-1]), r = char(Rs[Rs.size()-1]);
	
	if (x == 'D' && r == 'F' || r == 'D' && x == 'F') {
		cout<<"11";
		return 0;
	}
	if (x == 'A' && r == 'B' || r == 'A' && x == 'B') {
		cout<<"11";
		return 0;
	}
	if (x == 'B' && r == 'C' || r == 'B' && x == 'C') {
		cout<<"11";
		return 0;
	}
	if (x == 'A' && r == 'C' || r == 'A' && x == 'C') {
		cout<<"10";
		return 0;
	}else {
		cout<<"00";
		return 0;
	}
	return 0;
}

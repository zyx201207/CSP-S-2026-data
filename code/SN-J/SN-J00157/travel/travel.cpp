#include <bits/stdc++.h>
using namespace std;
int main () {
	string C1,S1,C2,S2;
    cin>> C1 >> S1 >> C2 >> S2;
	if(C1 == C2) {
		cout << "1";
		if (S1[0]+S1[1] == S2[0] + S2[1]) {
			cout << "111";
			
		} else {
			cout << "000";
		}

	} else {
		cout <<"0";
	}


}

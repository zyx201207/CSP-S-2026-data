#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 8;
string a1, a2, b1, b2;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin>>a1>>a2>>b1>>b2;
	if(a1 != b1) {
		cout<<"0000";
		return 0;
	}
	cout<<"1";
	if(a2[0] == b2[0] && a2[1] == b2[1]) {
		cout<<"1";
		int n1 = a2[2] - 'A' + 1;
		int n2 = b2[2] - 'A' + 1;
		if((n1 <= 3 && n2 <= 3) || (n1 >= 4 && n2 >= 4)) {
			cout<<"1";
			if(abs(n1 - n2) == 1) cout<<"1";
			else cout<<"0";
		}else {
			cout<<"00";
		}
	}else {
		cout<<"000";
	}
	return 0;
}
